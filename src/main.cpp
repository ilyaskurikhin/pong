#include <SFML/Graphics.hpp>
#include <array>
#include "Paddle/Paddle.h"
#include "Ball/Ball.h"
#include "Score/Score.h"

unsigned int WINDOW_HEIGHT(600);
unsigned int WINDOW_WIDTH(800);

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "InfoSV Pong");
    
    // initialise paddles
    Paddle top(0);
    Paddle bottom(WINDOW_HEIGHT - 20);

    // initialise ball
    Ball ball(5.0, true, 1.2);

    // initialise scorei
    sf::Font font;
    font.loadFromFile("res/arial.ttf");
    std::array<Score, 2> scores = { Score(WINDOW_WIDTH - 30,10,font), Score(10,WINDOW_HEIGHT - 40,font) };

    // loop for display refresh
    while (window.isOpen()) {
        sf::Event event;

        // check for event at each refresh
        while(window.pollEvent(event)) {

            // allow window button closure
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // move top Paddle with mouse
            else if (event.type == sf::Event::MouseMoved) {
                top.updatePosition(event.mouseMove.x);
            }

            // move bottom Paddle with arrow keys
            else if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case(sf::Keyboard::Left):
                        bottom.moveLeft();
                        break;
                    case(sf::Keyboard::Right):
                        bottom.moveRight();
                        break;
                    default:
                        break;
                }
            }
        }

        window.clear(sf::Color(150,150,150));
        top.draw(window);
        bottom.draw(window);
        
        // show scores
        for (size_t i(0); i < scores.size(); ++i) {
            scores[i].draw(window);
        }
        
        // calculate bounces
        ball.paddleBounce(top.getGlobalBounds());
        ball.paddleBounce(bottom.getGlobalBounds());
        
        // check for out of bounds
        int out(ball.out());
        switch (out) {
            case (-1):
                break;
            case (1):
                scores[0].increment();
                ball.restart();
                break;
            case(0):
                scores[1].increment();
                ball.restart();
                break;
            default:
                break;
        }
        
        ball.move();
        ball.draw(window);
    
        window.display();
    }

    return EXIT_SUCCESS;
}
