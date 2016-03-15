#include <SFML/Graphics.hpp>

#ifndef SCORE_H
#define SCORE_H

class Score
{
    private:
    sf::Font font_;
    int score_;
    sf::Text text_;
    
    public:
    Score(double x, double y, sf::Font& font);

    //draw the text on the target
    void 
    draw(sf::RenderTarget& target);

    //increment score by 1
    void 
    increment();

};
#endif
