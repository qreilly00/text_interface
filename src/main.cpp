//include classes and headers
#include "../inc/common.hpp"
#include "textInterface/TextInterface.hpp"

//declare objects
TextInterface ti;

int main() {
    int exit = 0;
    int count = 0;

    sf::RenderWindow w(sf::VideoMode(500, 500), "textinterface test");
    sf::Event e;

    ti.setFont("animatic.ttf");

    ti.setText("test");
    ti.setNewLine();

    //std::cout << "text: " << tmp[0].getString().toAnsiString() << std::endl;

    while(exit != 1) {
		//close window
		while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                exit = 1;
            //create a new text thing when button is pressed
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                std::string a = "Hello" + std::to_string(count) + "!";
                ti.setText(a);
                ti.setNewLine();
            }
		}

        /*if(count <= 10) {
            std::string a = "Hello" + std::to_string(count) + "!";
            ti.setText(a);
            ti.setNewLine();
            count++;
            ti.update();
        }*/

        ti.update();

        std::vector<sf::Text> tmp = ti.returnText();
        //std::cout << "text: " << tmp[0].getString().toAnsiString() << std::endl;

        //draw entities
		w.clear(sf::Color::White);
        for(int i = 0; i < tmp.size(); i++) {
            w.draw(tmp[i]);
        }
        w.display();
    }

    return 0;
}
