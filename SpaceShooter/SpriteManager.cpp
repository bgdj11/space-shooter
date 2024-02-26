#include "SpriteManager.h"

SpriteManager::SpriteManager()
{
    LoadTexture("../sprites/Engine_Ss_png.png"); // Player
    LoadTexture("../sprites/rocket.png"); // PlayerProjectile


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

sf::Texture SpriteManager::GetTexture(const std::string& filePath)
{
    if (LoadTexture(filePath))
        return textures[filePath];
}
