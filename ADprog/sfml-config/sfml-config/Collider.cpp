#include "Collider.h"

void Collider::setCollisionListener(CollisionListener* listener)
{
}

void Collider::setChecked(bool flag)
{
}

bool Collider::isChecked()
{
    return false;
}

bool Collider::willCollide(Collider* another)
{
    if (this->getGlobalBounds().intersects(another->getGlobalBounds()))
    {
        return true;
    }
    return false;
}

bool Collider::alreadyCollided()
{
    return false;
}

void Collider::setAlreadyCollided(bool flag)
{
}
sf::FloatRect Collider::getGlobalBounds()
{
    sf::FloatRect GlobalBounds = this->sprite->getGlobalBounds();
    GlobalBounds = this->owner->getGlobalTransform().transformRect(GlobalBounds);

    return GlobalBounds;

}

void Collider::setLocalBounds(sf::FloatRect localBounds)
{
    this->localBounds = localBounds;
}

void Collider::collisionEnter(AGameObject* gameObjects)
{
}

void Collider::collisionExit(AGameObject* gameObjects)
{
}

void Collider::perform()
{
}