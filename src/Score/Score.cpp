#include "Score.h"

Score::Score(double x, double y, sf::Font& font)
:   font_(font),
    score_(0),
    text_("text", font)
{
    text_.setPosition(x,y);
}

void 
Score::draw(sf::RenderTarget& target)
{
    text_.setString(std::to_string(score_));
    target.draw(text_);
}

void 
Score::increment()
{
    score_ = score_ + 1;
}
