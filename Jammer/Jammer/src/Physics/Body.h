#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <Physics/JamMath.h>
#include <Physics/Collider.h>
namespace jam {
	namespace phys{
		struct body {
			typedef sf::Vector2f v2;
			v2 velocity;
			float mass, invMass;
			v2 force;
			float restitution;
			bArea shape;

			body(bArea shape, float mass, float restitution) : shape(shape), mass(mass), restitution(restitution) {
				if (mass == 0) invMass = 0;
				else invMass = 1 / mass;
			}

			void impulse(float force, v2 direction);
			void update();
			void resolveCollision(body& other, v2 colNorm, float pdepth) {
				v2 relative_velocity = other.velocity - velocity;

				float velocity_along_normal = math::fdot(relative_velocity, colNorm);

				if (velocity_along_normal > 0) {
					return;
				}
				float min_restitution = fmin(restitution, other.restitution);

				float impulse_scalar = (-(1 + min_restitution) * velocity_along_normal) / (invMass + other.invMass);

				v2 impulse_vector = impulse_scalar * colNorm;
				velocity -= invMass * impulse_vector;
				other.velocity += other.invMass * impulse_vector;


			}

		};
	}
}