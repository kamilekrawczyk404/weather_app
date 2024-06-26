//
// Created by Kamil Krawczyk on 27/04/2024.
//

#ifndef CPP_WEATHER_APP_STATICTEXT_H
#define CPP_WEATHER_APP_STATICTEXT_H

#include <SFML/Graphics.hpp>
#include <string>
#include "../Font/CustomFont.h"

class StaticText : public CustomFont {
public:
    sf::Text text;
    int fontSize = 14;
    StaticText(std::string text, int fontSize = 14, sf::Color color = sf::Color(32, 32, 32));
    void draw(sf::RenderWindow& window);
    void setPosition(float x, float y);
    void setText(std::string& text);
    void justifyCenter(float centerX, float centerY, float offsetX, float offsetY);
};


#endif //CPP_WEATHER_APP_STATICTEXT_H
