#include "TextInterface.hpp"

void TextInterface::setNewLine() {
    newLine ++;
    text.resize(text.size() + 1);
}

void TextInterface::setNewLine(int i) {
    newLine = i;
    text.resize(text.size() + 1);
}
