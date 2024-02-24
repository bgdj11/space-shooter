#pragma once
#include <SFML/Graphics.hpp>

struct BigParticle {
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Color color;
    float lifeTime;
    float size;
};

class BigParticleSystem : public sf::Transformable
{
private:
    float particleLifeTime;
    std::vector<BigParticle> particles;
    float sizeDecreaseRate;
    bool status;

public:
    BigParticleSystem(int count, float particleLifeTime, sf::Color color, sf::Vector2f position);
    ~BigParticleSystem();

    void AddParticle(const sf::Vector2f& position, const sf::Vector2f& velocity, sf::Color color, float size);
    void Update(float dt);
    void Draw(sf::RenderTarget& target, sf::RenderStates states);
    bool GetStatus();

};

