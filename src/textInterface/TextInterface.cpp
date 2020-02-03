#include "TextInterface.hpp"

TextInterface::TextInterface() {
    //text.resize(1);

    textSize = 40;
	lineSpacing = 5;
	paragraphSpacing = 5;
    newLine = 0;

	textStyle = 0;
    textColor = sf::Color::Black;

    canvasSize = sf::Vector2f(490, 500);
    canvasPosition = sf::Vector2f(10, 0);
}

TextInterface::TextInterface(int txtSz, int lnSpc, int prgSpc, uint32_t stl, sf::Color clr, sf::Vector2f cnvSz, sf::Vector2f cnvPos) {
    //text.resize(1);

    textSize = txtSz;
	lineSpacing = lnSpc;
	paragraphSpacing = prgSpc;

	textStyle = stl;
    textColor = clr;

    canvasSize = cnvSz;
    canvasPosition = cnvPos;
}
