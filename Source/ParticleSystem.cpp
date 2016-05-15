#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(unsigned int count):
m_particles(count),
m_vertices(sf::Points, count),
emitterPosition(0, 0)
{
	for (int i = 0; i < count; i++)
	{
		m_vertices[i].color = sf::Color(255,255,0);
	}
}

void ParticleSystem::Update(float elapsed , bool spawnNew)
{
	for (std::size_t i = 0; i < m_particles.size(); ++i)
	{
		Particle* particle = &m_particles[i];
		particle->lifeTime -= elapsed;
		if (m_vertices[i].color.g > 20)m_vertices[i].color.g-=20;
		if (particle->lifeTime <= 0.0f)
		{
			m_vertices[i].color.a = 0.f;
			if (spawnNew)
				resetParticle(i);
		}

		m_vertices[i].position += particle->velocity * static_cast<float>(elapsed);
		
	}
	
}

void ParticleSystem::SetEmitterPosition(sf::Vector2f position)
{
	emitterPosition = position;
}

void ParticleSystem::resetParticle(std::size_t index)
{
	float angle = (std::rand() % 181 ) * 3.14f / 180.f;

	float speed = (std::rand() % 50) + 5.f;
	m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
	m_particles[index].lifeTime  =static_cast<float>(std::rand() % 10)/20.f;
	m_vertices[index].position = emitterPosition;
	m_vertices[index].color = sf::Color::Yellow;
	m_vertices[index].color.a = 255;
}
