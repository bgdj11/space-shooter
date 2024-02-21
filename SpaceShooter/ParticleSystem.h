#pragma once
#include <SFML/Graphics.hpp>

struct Particle {
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Color color;
	float lifeTime;
};

class ParticleSystem : public sf::Transformable
{
private:
	float particleLifeTime;

public:
	std::vector<Particle> particles;
	sf::VertexArray vertices;

	ParticleSystem(unsigned count, float particleLifeTime);
	void AddParticle(const sf::Vector2f& position, const sf::Vector2f& velocity, const sf::Color& color);
	void Update(float dt, const sf::Vector2f& sourcePosition, const sf::Vector2f& sourceVelocity);

protected:
	virtual void Draw(sf::RenderTarget& target, sf::RenderStates states);

};

