#include "Projectile.h"
#include "SeekBehavior.h"
#include "Character.h"
#include "Game.h"

Projectile::Projectile(Character* target, float speed = 200.0F, int damage = 1)
{
	m_target = target;
	m_speed = speed;
	m_damage = damage;
	SeekBehavior* seek = new SeekBehavior();
	seek->setTarget(dynamic_cast<Character*>(m_target));
	addBehavior(seek);
}

void Projectile::update(float deltaTime)
{
	onCollision(m_target);
}

void Projectile::onCollision(Actor* other)
{
	Character* target = dynamic_cast<Character*>(other);
	if (target == m_target)
		target->takeDamage(m_damage);
	Game::getInstance()->getCurrentScene()->removeActor(this);
}