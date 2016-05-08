#pragma once

#include "GraphicAttributes.h"
#include "PhysicAttributes.h"

class GameObject :
	public GraphicAttributes,
	public PhysicAttributes
{
public:
	GameObject(std::string texturePath, sf::Vector2f velVec);

	void Update(float, float = 0, float = 0);

private:
	void draw(sf::RenderTarget&, sf::RenderStates);
};

