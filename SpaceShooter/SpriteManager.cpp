#include "SpriteManager.h"

SpriteManager::SpriteManager()
{
    LoadTexture("../sprites/Engine_Ss_png.png"); // Player
    LoadTexture("../sprites/rocket.png"); // PlayerProjectile

    // First wave
    LoadTexture("../sprites/Boss_1_png.png");
    LoadTexture("../sprites/Enemy1_Ss_png.png");

    // Rocks
    LoadTexture("../sprites/rock1.png");
    LoadTexture("../sprites/rock2.png");
    LoadTexture("../sprites/rock3.png");
    LoadTexture("../sprites/rock4.png");
    LoadTexture("../sprites/rock5.png");
}

SpriteManager::~SpriteManager()
{
}

bool SpriteManager::LoadTexture(const std::string& filePath)
{
    if (textures.find(filePath) == textures.end()) {
        sf::Texture texture;
        if (texture.loadFromFile(filePath)) {
            textures[filePath] = texture;
            return true;
        }
        else {
            return false;
        }
    }
    return true;
}

sf::Texture& SpriteManager::GetTexture(const std::string& filePath)
{
    return textures[filePath];
}
