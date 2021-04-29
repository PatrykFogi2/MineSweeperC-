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
	sf::RenderWindow window(sf::VideoMode(800,600), "Saper - Patryk Wonsewicz");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(1);
   

    




    MinesweeperBoard board(10,10,EASY); 
	MSSFMLView view(board);
  

   



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // a = szerokosc/2 + col * 40 - (height*40/2) ;
           // b = wysokosc/2 + row * 30 - (width*30/2);
             if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    int a;
                    int b;
                    b = ((event.mouseButton.x / 40) -5);
                    a = ((event.mouseButton.y / 30)-5);
                    // a =(event.mouseButton.x);
                    // b = (event.mouseButton.y);
                    board.revealField(a, b);
                }
                if (event.mouseButton.button == Mouse::Right) {
                    int a;
                    int b;
                    b = ((event.mouseButton.x / 40) - 5);
                    a = ((event.mouseButton.y / 30)-5);
                    // a =(event.mouseButton.x/20);
                    // b = (event.mouseButton.y/10);
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
  
