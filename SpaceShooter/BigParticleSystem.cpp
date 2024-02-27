#include "BigParticleSystem.h"

BigParticleSystem::BigParticleSystem(int count, float particleLifeTime, sf::Color color, sf::Vector2f position,
    float sizeDecrease, float size, float velocityCoef)
{
    this->particleLifeTime = particleLifeTime;
    this->sizeDecreaseRate = sizeDecrease;
    status = true;

    for (int i = 0; i < count; i++)
    {
        sf::Vector2f velocity(rand() % 100 - 50, rand() % 100 - 50);
        AddParticle(position, velocity * velocityCoef, color, size);
    }
}

BigParticleSystem::~BigParticleSystem()
{
}

void BigParticleSystem::AddParticle(const sf::Vector2f& position, const sf::Vector2f& velocity, sf::Color color, float size)
{
    BigParticle particle;
    particle.position = position;
    particle.velocity = velocity;
    particle.color = color;
    particle.lifeTime = particleLifeTime;
    particle.size = size;

    particles.push_back(particle);
}

void BigParticleSystem::Update(float dt)
{
    for (auto& particle : particles) {
        particle.position += particle.velocity * dt;
        particle.lifeTime -= dt;
        particle.size = std::max(particle.size - dt * sizeDecreaseRate, 0.5f);

        if (particle.color.g + 2 <= 255) 
            particle.color.g += 2; 
        else 
            particle.color.g = 255;
        

        particles.erase(std::remove_if(particles.begin(), particles.end(),
            [](const BigParticle& p) { return p.lifeTime <= 0; }),
            particles.end());
    }

    if (particles.empty())
        status = false;
}

void BigParticleSystem::Draw(sf::RenderTarget& target, sf::RenderStates states)
{
    states.transform *= getTransform();

    for (const auto& particle : particles) 
    {
        sf::CircleShape circle(particle.size / 2.0f);
        circle.setPosition(particle.position);
        circle.setFillColor(particle.color);
        target.draw(circle, states);
    }

}

bool BigParticleSystem::GetStatus()
{
    return status;
}
