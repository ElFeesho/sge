#ifndef __SCENE_HPP__
#define __SCENE_HPP__

#include <list>
#include "entity.hpp"
#include "renderable.hpp"

using std::list;
using std::string;

typedef list<Renderable*> RenderableList;
typedef list<Entity*> EntityList;

class Scene
{
public:
	Scene();
	~Scene();

	void addEntity(Entity *entity);
	void addRenderable(Renderable *renderable);

	void removeRenderable(Renderable *renderable);

	virtual void update();
	virtual void render();

	virtual void sceneAdded();
	virtual void sceneRemoved();
	
	Entity *findEntityByName(const string &name);
private:
	bool sceneLive;
	EntityList entities;
	RenderableList renderables;
};

#endif
