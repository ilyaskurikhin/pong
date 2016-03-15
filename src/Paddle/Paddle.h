#include <SFML/Graphics.hpp>

#ifndef PADDLE_H
#define PADDLE_H

class Paddle 
{
    public:
    Paddle(double y);
   
    // display Paddle to target
    void 
    draw(sf::RenderTarget& target) const;

    // update horizontal position if in limits
    void
    updatePosition(double x);

    // move horizontally by delta if in limits
    void
    updatePositionDelta(double delta);

    // move right by speed_
    void 
    moveRight();

    // move left by speed_
    void
    moveLeft();

    // return bounds of rectangle_
    sf::FloatRect
    getGlobalBounds() const;

    private:
    sf::RectangleShape rectangle_;
    double speed_;
};
#endif
