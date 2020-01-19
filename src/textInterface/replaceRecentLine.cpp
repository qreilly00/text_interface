#include "TextInterface.hpp"

int TextInterface::replaceRecentLine(std::string in) {
    sf::FloatRect tmp = text[text.size() - 1].getGlobalBounds();
    if(tmp.width <= canvasSize.x - textSize) {
        text[text.size() - 1].setString(in);
        return 0;
    } else {
        setNewLine();
        return 1;
    }
}
