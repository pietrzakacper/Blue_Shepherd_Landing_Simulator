#include "GameObject.h"

GameObject::GameObject(std::string texturePath, sf::Vector2f velVec): GraphicAttributes(texturePath), PhysicAttributes(velVec)
{
}

void GameObject::Update(float fps, float, float)
{
	m_sprite.move(m_velocityVector * fps);
}

void GameObject::draw(sf::RenderTarget & target, sf::RenderStates states)
{
	target.draw(m_sprite, states);
}
