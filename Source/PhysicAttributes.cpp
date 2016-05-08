#include "PhysicAttributes.h"

PhysicAttributes::PhysicAttributes(sf::Vector2f velVec)
{
	m_velocityVector = velVec;
}

sf::Vector2f PhysicAttributes::GetVelocityVector()
{
	return m_velocityVector;
}

void PhysicAttributes::SetVelocityVector(sf::Vector2f velVec)
{
	m_velocityVector = velVec;
}


