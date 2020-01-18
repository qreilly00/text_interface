#include "TextInterface.hpp"

void TextInterface::setText(std::string txt) {
    sf::Text tmp;
    tmp.setString(txt);
    text.push_back(tmp);
    //update();
}
