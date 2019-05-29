#pragma once

#include "GraphicalObject.h"

#include <btBulletDynamicsCommon.h>





class Object
{
public:

	struct Properties
	{
		btCollisionShape* m_shape;
		btScalar m_mass = 1.0;
		btScalar m_restitution = 0.0;
		btScalar m_friction = 0.4;

		Properties(btCollisionShape* shape, btScalar mass, btScalar restitution, btScalar friction) :
			m_shape(shape),
			m_mass(mass),
			m_restitution(restitution),
			m_friction(friction)
		{
		}
	};


	Object(GraphicalObject* parent, const Properties& properties);
	Object(GraphicalObject* parent, btEmptyShape* shape);
	~Object();

	btRigidBody* getBody();


	void impulse(const btVector3& force);
	void push(const btVector3& force);

	void setPosition(const btVector3& position);
	void setRotation(const btVector3& rotation);

	btVector3& getPosition();

	void act();

protected:

	GraphicalObject* parent;

	btRigidBody* m_body;

	btTransform* m_transform;
};