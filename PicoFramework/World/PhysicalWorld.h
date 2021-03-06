#pragma once

#include <btBulletDynamicsCommon.h>

#include "ObjectManager/Object/Object.h"

class PhysicalWorld
{
public:
	
	static PhysicalWorld* getInstance();
	
	~PhysicalWorld();

	btDiscreteDynamicsWorld* getDynamicsWorld();

	void addObjectStatic(Object* object);
	void addObjectDynamic(Object* object);


	void step(double fps);

	void clear();

private:

	PhysicalWorld(const btVector3& gravity = btVector3(0, -10, 0));
	PhysicalWorld(const PhysicalWorld const&) = delete;
	PhysicalWorld& operator=(const PhysicalWorld const&) = delete;

	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btBroadphaseInterface* overlappingPairCache;
	btSequentialImpulseConstraintSolver* solver;

	btDiscreteDynamicsWorld* dynamicsWorld;

	std::vector<Object*> sObjects;
	std::vector<Object*> dObjects;
};

 