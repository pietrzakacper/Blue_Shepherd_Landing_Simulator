#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>

class ParticleSystem : public sf::Drawable
{
	struct Particle
	{
		sf::Vector2f velocity;
		float lifeTime;
	
	};
public:
	ParticleSystem(unsigned int count);
	void Update(float elapsed, bool spawNew);
	void SetEmitterPosition(sf::Vector2f position);
	
private:
	
	void resetParticle(std::size_t index);
	std::vector<Particle> m_particles;
	sf::VertexArray m_vertices;
	sf::Vector2f emitterPosition;
	void draw(sf::RenderTarget& target, sf::RenderStates states)const override
	{
		target.draw(m_vertices, states);
	}
};