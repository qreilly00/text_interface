#include "TextInterface.hpp"

int TextInterface::setFont(std::string fntName) {
    int i = 1;

    if(!font.loadFromFile(fntName)) {
        i = 0;
    }

    return i;
}
