//include classes and headers
#include "../inc/common.hpp"
#include "textInterface/TextInterface.hpp"

//declare objects
TextInterface ti;

int main() {
    int exit = 0;
    int count = 0;

    std::vector<std::string> input;
    input.resize(input.size() + 1);

    sf::RenderWindow w(sf::VideoMode(500, 500), "textinterface test");
    sf::Event e;

    ti.setFont("terminus.ttf");

    ti.setText("test");
    ti.setNewLine();

    //std::cout << "text: " << tmp[0].getString().toAnsiString() << std::endl;

    while(exit != 1) {

		while (w.pollEvent(e)) {
            //close window
            if (e.type == sf::Event::Closed)
                exit = 1;

            //new line
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                ti.setNewLine();
                input.resize(input.size() + 1);
            }

            if(sf::Event::KeyPressed) {
                if (e.type == sf::Event::TextEntered) {
                    if(e.text.unicode == 8 && input[input.size() - 1].size() > 0) { //erase last letter
                        input[input.size() - 1].erase(input[input.size() - 1].end() - 1, input[input.size() - 1].end());
                    } else if (e.text.unicode < 127 && e.text.unicode > 31) { //accept input
                        input[input.size() - 1] += static_cast<char>(e.text.unicode);
                    }
                }
            }
		}

        if(ti.replaceRecentLine(input[input.size() - 1]) == 1) {
            input.resize(input.size() + 1);
        }
        ti.update();

        std::vector<sf::Text> tmp = ti.returnText();

        //draw entities
		w.clear(sf::Color::White);
        for(int i = 0; i < tmp.size(); i++) {
            w.draw(tmp[i]);
        }
        w.display();
    }

    return 0;
}
