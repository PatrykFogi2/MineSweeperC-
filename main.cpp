#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"










int main()
{
	sf::RenderWindow window(sf::VideoMode(1200,800), "Grafika w C++/SFML");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(1);

    MinesweeperBoard board(10,10,EASY); 
	MSSFMLView view(board);
     
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
             if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    int a;
                    int b;
                    a = (event.mouseButton.x / 40);
                    b = (event.mouseButton.y / 30);
                    board.revealField(a, b);
                }
                if (event.mouseButton.button == Mouse::Right) {
                    int a;
                    int b;
                    a = (event.mouseButton.x / 40);
                    b = (event.mouseButton.y / 30);
                    board.toggleFlag(a, b);
                }
            } 
        }
        
        window.clear();
        view.draw(window);
        window.display();
    }

  return 0;
} 
