
#pragma once
#include "Particle.h"
#include <vector>

class ParticleSystem : public sf::Drawable
{
public:
	ParticleSystem(unsigned int count);

	void SetEmitterPosition(sf::Vector2f position);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates& states) const ;

	std::vector<Particle> m_particles;
	sf::VertexArray m_vertices;
	sf::Time m_lifetime;
	sf::Vector2f emitterPosition;

};