#include "TextInterface.hpp"

void TextInterface::update() {
    defaultPos = sf::Vector2f(canvasPosition.x, canvasPosition.y + canvasSize.y - textSize - paragraphSpacing/**/);
    text[text.size() - 1].setPosition(defaultPos);

    for(int i = 0; i < text.size(); i++) {
        text[i].setCharacterSize(textSize);
        text[i].setFont(font);
        text[i].setFillColor(textColor);
    }

    if(newLine == 1) {
        newLine = 0;
        for(int i = text.size() - 1; i >= 0; i--) {
            text[i].setPosition(sf::Vector2f(text[i].getPosition().x, text[i].getPosition().y - textSize - paragraphSpacing));
        }
    }

    /*
    for(int i = 0; i < text.size(); i++) {
        text[i].setCharacterSize(textSize);
        text[i].setFont(font);
        text[i].setFillColor(textColor);
        text[i].setPosition(defaultPos);
        //std::cout << text.size() << std::endl;
    }

    if(newLine == 1) {
        newLine = 0;
        for(int i = 0; i < text.size(); i++) {
            text[i].setPosition(sf::Vector2f(text[i].getPosition().x, text[i].getPosition().y - textSize - paragraphSpacing));
        }
    }

    //text[text.size()-1].setPosition(sf::Vector2f(canvasPosition.x, canvasPosition.y + canvasSize.y - textSize - paragraphSpacing));
    */
}
