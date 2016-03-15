#include "Ball.h"
#include <iostream>
#include <cmath>

Ball::Ball(double speed, bool accelerate, double factor)
{
    texture_.loadFromFile("res/Ball.png");
    sprite_.setTexture(texture_);
    sprite_.setPosition(100, 100);

    speed_ = speed;
    accelerate_ = accelerate;
    factor_ = factor;

    max_speed_ = 15.0;

    std::cout << "Ball constructed using full constructor" << std::endl; 
    std::cout << "speed_ = " << speed_ << ", accelerate_ = " << accelerate_ << " factor_ = " << factor_ << std::endl;

    restart();
}

void 
Ball::draw(sf::RenderTarget& target) const
{
    target.draw(sprite_);
}

void
Ball::setDirectionFromAngle(double angle)
{
    velocity_ = sf::Vector2f(speed_*std::cos(angle),-speed_*std::sin(angle));
    angle_ = angle;
}

void
Ball::restart()
{
    sprite_.setPosition(400,300);
    setDirectionFromAngle(M_PI/4.0);
    if (accelerate_) {
        accelerate();
    }
    std::cout << "\nBall restarted" << std::endl;
    std::cout << "speed_ = " << speed_ << std::endl;
}

void
Ball::move()
{
    if (clock_.getElapsedTime().asMilliseconds() > 35) {
        checkWallCollisions();
        sprite_.move(velocity_);
        clock_.restart();
    }
}

int
Ball::out()
{
    if (sprite_.getPosition().y < 0) {
        return 0;
    }
    else if (sprite_.getPosition().y > 600) {
        return 1;
    } else {
        return -1;
    }
}

void 
Ball::checkWallCollisions()
{
    if (sprite_.getPosition().x >= 800) {
        angle_ = M_PI - angle_;
        setDirectionFromAngle(angle_);
    } 
    else if (sprite_.getPosition().x <= 0) {
        angle_ = M_PI - angle_;
        setDirectionFromAngle(angle_);
    }
}

void 
Ball::paddleBounce(const sf::FloatRect& paddleRect)
{
    if (sprite_.getGlobalBounds().intersects(paddleRect)) {
        angle_ = - angle_;
        setDirectionFromAngle(angle_);
    }
}

void
Ball::accelerate()
{
    if (speed_ < max_speed_) {
        speed_ = factor_ * speed_;
    }
}
