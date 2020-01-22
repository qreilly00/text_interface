#ifndef TEXTINTERFACE_HPP
#define TEXTINTERFACE_HPP

#include "../../inc/common.hpp"

class TextInterface {
private:

	//declare variables
	int textSize;
	int lineSpacing;
	int paragraphSpacing;
	int newLine;

	std::vector<sf::Text> text;
	sf::Font font;

	uint32_t textStyle;
	sf::Color textColor;

	sf::Vector2f canvasSize;
	sf::Vector2f canvasPosition;

	sf::Vector2f defaultPos;

public:

	//declare initializers
	TextInterface();
	TextInterface(int, int, int, uint32_t, sf::Color, sf::Vector2f, sf::Vector2f);

	//declare public functions
	void update();

	int setFont(std::string);
	int replaceRecentLine(std::string);

	void setText(std::string txt);
	void setTextSize(int);
	void setLineSpacing(int);
	void setParagraphSpacing(int);
	void setTextStyle(uint32_t);
	void setTextColor(sf::Color);
	void setCanvasSize(sf::Vector2f);
	void setCanvasPosition(sf::Vector2f);
	void setNewLine();
	void setNewLine(int);
	void removeRecentLine();

	std::vector<sf::Text>& returnText();

};

#endif
