#ifndef _ENTITY_MANAGER_HPP_
#define _ENTITY_MANAGER_HPP_

#include "Entity.hpp"
#include <unordered_set>

class EntityManager
{
	public:
		EntityManager();
		~EntityManager();
		Entity Create();
		bool alive(Entity e);
		void destroy(Entity e);


	private:

		std::unordered_set<Entity> entities;
		Entity next;

};





#endif // _ENTITY_MANAGER_HPP_
