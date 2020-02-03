#include "TextInterface.hpp"

void TextInterface::update() {
    if(text.size() == 0) {
        text.resize(1);
    }

    defaultPos = sf::Vector2f(canvasPosition.x, canvasPosition.y + canvasSize.y - textSize - paragraphSpacing);
    text[text.size() - 1].setPosition(defaultPos);

    for(int i = 0; i < text.size(); i++) {
        text[i].setCharacterSize(textSize);
        text[i].setFont(font);
        text[i].setFillColor(textColor);
    }

    if(newLine < 0) {
        newLine ++;
        if(text.size() > 1) {
            text.resize(text.size() - 1);
        }
        for(int i = text.size() - 1; i >= 0; i--) {
            text[i].setPosition(sf::Vector2f(text[i].getPosition().x, text[i].getPosition().y + textSize + paragraphSpacing));
        }
    }

    if(newLine > 0) {
        newLine --;
        text.resize(text.size() + 1);
        for(int i = text.size() - 1; i >= 0; i--) {
            text[i].setPosition(sf::Vector2f(text[i].getPosition().x, text[i].getPosition().y - textSize - paragraphSpacing));
        }
    }

    //std::string tmp = text[text.size() - 1].getString().toAnsiString(); textSize * tmp.length()
    /*sf::FloatRect tmp = text[text.size() - 1].getGlobalBounds();
    if(tmp.width >= canvasSize.x) {
        setNewLine();
    }*/
}
