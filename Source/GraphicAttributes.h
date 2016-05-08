#pragma once

#include <SFML\Graphics.hpp>

class GraphicAttributes :
	public sf::Drawable
{
protected:
	sf::Texture m_texture;
	sf::Sprite m_sprite;

public:
	GraphicAttributes(std::string texturePath);

	sf::Texture GetTexture();
	sf::Sprite GetSprite();
	sf::Vector2f GetPosition();
	sf::Vector2f GetScale();

	void SetTexture(sf::Texture);
	void SetSprite(sf::Sprite);
	void SetPosition(sf::Vector2f);
	void SetScale(sf::Vector2f);

	bool IsColliding(sf::Sprite&);

private:
	void draw(sf::RenderTarget&, sf::RenderStates) const;
};

