#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
using namespace sf;
using namespace std;










int main()
{
	sf::RenderWindow window(sf::VideoMode(1200,800), "Saper - Patryk Wonsewicz");
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
  // try to reveal the field at (row,col)
  // Do nothing if any of the following is true
  // - field was already revealed
  // - either row or col is outside board
  // - game is already finished
  // - there is a flag on the field
  //
  // If the field was not revealed and there is no mine on it - reveal it
  // If the field was not revealed and there is a mine on it:  
  // - if its the first player action - move mine to another location, reveal field (not in DEBUG mode!)
  // - reveal it and finish game
