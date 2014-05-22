#include "scene.hpp"
#include <algorithm>
#include <iostream>
#include <functional>

Scene::Scene() : sceneLive(false)
{

}

Scene::~Scene()
{

}

void Scene::addEntity(Entity *entity)
{
	entities.push_back(entity);
	if(sceneLive)
	{
		entity->entityAdded();
	}
}

void Scene::addRenderable(Renderable *renderable)
{
	renderables.push_back(renderable);
}

void Scene::removeRenderable(Renderable *renderable)
{
	renderables.remove(renderable);
}

void Scene::sceneAdded()
{
	sceneLive = true;
	for(Entity *entity : entities) {
		entity->entityAdded();
	}
}

void Scene::sceneRemoved()
{

}

void Scene::update()
{
	for(Entity *entity : entities)
	{
		if(!entity->update())
		{
			entity->entityRemoved();
		}
	}

	if(entities.size()>0)
	{
		entities.remove_if([](Entity *ent) { return !ent->isAlive(); });
	}

	for(Entity *collider : entities) {
		if(collider->isAlive())
		{
			for(Entity *collidee : entities) {
				if(collider != collidee && collidee->isAlive())
				{
					collider->checkCollision(collidee);
				}
			}
		}
	}
}

void Scene::render()
{
	renderables.remove_if([](Renderable *renderable){ return !renderable->render(); });
}


Entity *Scene::findEntityByName(const string &name)
{
	for(Entity *entity : entities)
	{
		if(entity->getName() == name)
		{
			return entity;
		}
	}

	return 0;
}
