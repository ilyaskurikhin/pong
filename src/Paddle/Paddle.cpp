#include "Paddle.h"
#include <iostream>

Paddle::Paddle(double y)
{
    rectangle_.setSize(sf::Vector2f(100,20));
    rectangle_.setOutlineColor(sf::Color(0,0,0));
    rectangle_.setOutlineThickness(2);
    rectangle_.setPosition(300, y);
    speed_ = 20;
}

void 
Paddle::draw(sf::RenderTarget& target) const
{
    target.draw(rectangle_);
}

void
Paddle::updatePosition(double x) 
{
    if ((x > 0) && (x < 800)) {
        rectangle_.setPosition(x,rectangle_.getPosition().y);
    }
}

void
Paddle::updatePositionDelta(double delta)
{
    if (((delta < 0) && (rectangle_.getPosition().x + delta > 0)) or
            ((delta > 0) && (rectangle_.getPosition().x + delta < 800))) {
        rectangle_.move(delta,0);
    }
}

void
Paddle::moveRight()
{
    updatePositionDelta(speed_);
}

void
Paddle::moveLeft()
{
    updatePositionDelta(-speed_);
}

sf::FloatRect
Paddle::getGlobalBounds() const
{
    return rectangle_.getGlobalBounds();
}
