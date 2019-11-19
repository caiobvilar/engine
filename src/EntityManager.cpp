#include "../include/EntityManager.hpp"

EntityManager::EntityManager()
{
	this->next.id=0;
}

EntityManager::~EntityManager()
{
}

Entity EntityManager::Create()
{
	++this->next.id;
	while()
	{
	}
}


bool EntityManager::alive(Entity e)
{
}

void EntityManager::destroy(Entity e)
{
}

