//include classes and headers
#include "../inc/common.hpp"
#include "textInterface/TextInterface.hpp"

//declare objects
TextInterface ti;

int main() {
    int exit = 0;
    int count = 0;

    std::vector<std::string> input;
    /*input.resize(1);
    input[0] = "";*/

    sf::RenderWindow w(sf::VideoMode(500, 500), "textinterface test");
    sf::Event e;

    ti.setFont("terminus.ttf");

    while(exit != 1) {
		while (w.pollEvent(e)) {
            //close window
            if (e.type == sf::Event::Closed)
                exit = 1;

            //get keyboard input
            if(sf::Event::KeyPressed) {
                /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) { //enter button new line
                    ti.setNewLine();
                    input.resize(0);
                }*/
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { //exit button
                    exit = 1;
                }
                if (e.type == sf::Event::TextEntered) {
                    // ---> something wrong with this code
                    if(e.text.unicode == 8) { //erase last letter
                        if(input[input.size() - 1].size() > 0) { //if letters exist
                            input[input.size() - 1].erase(input[input.size() - 1].end() - 1, input[input.size() - 1].end());
                        } else if(input.size() > 1) { //if no letters exist
                            input.resize(input.size() - 1);
                            input[input.size() - 1].erase(input[input.size() - 1].end() - 1, input[input.size() - 1].end());
                            ti.removeRecentLine();
                        }

                    } else if(e.text.unicode == 13) {//create new line
                        ti.setNewLine();
                        input.resize(input.size() + 1);
                        //input.resize(0);
                    } else if (e.text.unicode < 127 && e.text.unicode > 31) { //accept input
                        input[input.size() - 1] += static_cast<char>(e.text.unicode);
                    }
                }
            }
		}

        if(input.size() == 0) {
            input.resize(1);
        }

        // ---> something wrong with this code --> corrrected
        ti.update();

        // ---> something wrong with this code --> corrrected
        // ---> new problem. deleteing back to full line will automatically create a new line which means you cant delete previous line.
        if(ti.replaceRecentLine(input[input.size() - 1]) == 1) {
            input.resize(input.size() + 1);
        }



        //get sf::Text for drawing
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
