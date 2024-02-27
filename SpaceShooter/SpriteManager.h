#pragma once
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>

class SpriteManager
{
private:
	std::unordered_map<std::string, sf::Texture> textures;

public:
	SpriteManager();
	~SpriteManager();
	bool LoadTexture(const std::string& filePath);
	sf::Texture& GetTexture(const std::string& filePath);

};

