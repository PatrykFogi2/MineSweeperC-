#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include "MouseController.h"
using namespace sf;
using namespace std;










int main()
{
	sf::RenderWindow window(sf::VideoMode(800,600), "Saper - Patryk Wonsewicz");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(1);
   




    

    MinesweeperBoard board(5,5,EASY); 
	MSSFMLView view(board);
    MouseController config(board,view);

   
      




    while (window.isOpen())
    {
 
        
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type==Event::Closed)
            {
                window.close();
            }
          
             if (event.type == Event::MouseButtonPressed) {
                //  int a; 
                //  int b;
                // if (event.mouseButton.button == Mouse::Left) {
                    
     
                //      b = (event.mouseButton.x - szerokosc/2 + (board.getBoardWidth() * 40/2 )) /40 ;
                //      a = (event.mouseButton.y - wysokosc/2 +(board.getBoardHeight() *40/2))/40 ;

                     
                //     board.revealField(a, b);
                // }
                // if (event.mouseButton.button == Mouse::Right) {
                  
                //      b = (event.mouseButton.x - szerokosc/2 + (board.getBoardWidth()* 40/2 )) /40 ;
                //      a = (event.mouseButton.y - wysokosc/2 +(board.getBoardHeight() *40/2))/40 ;
     
                //     board.toggleFlag(a, b);
                //   }
                config.wydarzenie(event);
        
        
        
            window.clear();
            view.draw(window);
            window.display();
          }
        }
}
  return 0;
} 

  
