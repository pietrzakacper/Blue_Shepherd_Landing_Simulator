#include "GraphicAttributes.h"

GraphicAttributes::GraphicAttributes(std::string texturePath)
{
	if (!m_texture.loadFromFile(texturePath))
	{
		exit(0);
	}

	m_sprite.setTexture(m_texture);
}

sf::Texture GraphicAttributes::GetTexture()
{
	return m_texture;
}

sf::Sprite GraphicAttributes::GetSprite()
{
	return m_sprite;
}

sf::Vector2f GraphicAttributes::GetPosition()
{
	return m_sprite.getPosition();
}

sf::Vector2f GraphicAttributes::GetScale()
{
	return m_sprite.getScale();
}

void GraphicAttributes::SetTexture(sf::Texture texture)
{
	m_texture = *m_sprite.getTexture();
	m_sprite.setTexture(m_texture);
}

void GraphicAttributes::SetSprite(sf::Sprite sprite)
{
	m_sprite = sprite;
	m_texture = *m_sprite.getTexture();
}

void GraphicAttributes::SetPosition(sf::Vector2f val)
{
	m_sprite.setPosition(val);
}

void GraphicAttributes::SetScale(sf::Vector2f val)
{
	m_sprite.setScale(val);
}

bool GraphicAttributes::IsColliding(sf::Sprite & sprite)
{
	if (m_sprite.getGlobalBounds().intersects(sprite.getGlobalBounds()))
	{
		return true;
	}

	return false;
}

void GraphicAttributes::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}
