#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(unsigned count, float particleLifeTime)
	: vertices(sf::Points, count), particleLifeTime(particleLifeTime)
{
	particles.reserve(count);
}

void ParticleSystem::AddParticle(const sf::Vector2f& position, const sf::Vector2f& velocity, const sf::Color& color)
{
	Particle particle;
	particle.position = position;
	particle.velocity = velocity;
	particle.color = color;
	particle.lifeTime = particleLifeTime;

	particles.push_back(particle);
}

void ParticleSystem::Update(float dt, const sf::Vector2f& sourcePosition, const sf::Vector2f& sourceVelocity)
{
	for (auto& particle : particles)
	{
		particle.position += particle.velocity * dt + sourceVelocity * dt;
		particle.lifeTime -= dt;
	}

	particles.erase(std::remove_if(particles.begin(), particles.end(),
		[](const Particle& p) { return p.lifeTime <= 0; }),
		particles.end());

	vertices.clear();
	for (const auto& particle : particles) {
		vertices.append(sf::Vertex(particle.position, particle.color));
	}
}

void ParticleSystem::Draw(sf::RenderTarget& target, sf::RenderStates states)
{
	states.transform *= getTransform();
	target.draw(vertices, states);
}
