#include <SFML/Graphics.hpp>
#include "../Paddle/Paddle.h"

#ifndef BALL_H
#define BALL_H

class Ball
{
    public:
    Ball(double speed = 5.0, bool accelerate = true, double factor = 1.33);

    void 
    draw(sf::RenderTarget& target) const;

    // set the velocity vector to be used at next move
    void
    setDirectionFromAngle(double angle);

    // put the ball in the middle
    void 
    restart();

    // move the ball in angle at velocity, bounce off walls
    void
    move();
    
    // returns 1 (above) or 0 (below) if ball is out of bounds, -1 otherwise
    int 
    out();

    // changes the angle_ in the event of a collision with the walls
    void
    checkWallCollisions();

    // chage the angle_ in a collision with a Paddle.getGlobalBounds()
    void
    paddleBounce(const sf::FloatRect& paddleRect);

    private:

    // accelerate the ball by factor_
    void
    accelerate();

    sf::Texture texture_;
    sf::Sprite sprite_;
    double angle_;
    sf::Vector2f velocity_;
    double speed_;
    double max_speed_;
    sf::Clock clock_;

    // use speed_ accleration after each win
    bool accelerate_;
    // accelerate the ball by factor_
    double factor_;
};
#endif
