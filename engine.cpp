#include "engine.hpp"

#include <algorithm>

Engine::Engine()
{

}

Engine::~Engine()
{

}


void Engine::pushScene(Scene *scene)
{
	scenes.push_back(scene);
	scene->sceneAdded();
}

void Engine::popScene()
{
	scenes.back()->sceneRemoved();
	scenes.pop_back();
}


void Engine::update()
{
	for(Scene *scene : scenes) 
	{
		scene->update();
	}
}

void Engine::render()
{
	for(Scene *scene : scenes)
	{
		scene->render();
	}	
}

Scene *Engine::getActiveScene()
{
	return (*(scenes.end()-1));
}


Engine *Engine::getInstance()
{
	if(!Engine::instance)
	{
		Engine::instance = new Engine();
	}
	return Engine::instance;
}

void Engine::shutdown()
{
	if(!Engine::instance)
	{
		Engine::instance->scenes.clear();
		delete Engine::instance;
	}
}

Engine *Engine::instance = 0;
