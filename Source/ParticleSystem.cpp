#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(unsigned int count):
m_particles(count),
m_vertices(sf::Points, count),
m_lifetime(sf::seconds(3)),
emitterPosition(0, 0)
{
}

void ParticleSystem::SetEmitterPosition(sf::Vector2f position)
{
	emitterPosition = position;
}

void ParticleSystem::draw(sf::RenderTarget & target, sf::RenderStates & states) const
{
	// draw the vertex array
	target.draw(m_vertices, states);
}
