#include "MouseController.h"

MouseController::MouseController(MinesweeperBoard & bo, MSSFMLView & Vi) :board(bo) ,View(Vi)
{

}


void MouseController::wydarzenie(sf::Event &event){

      int a;
      int b;
      constexpr int szerokosc = 800;
     constexpr int wysokosc = 600;
      int height = board.getBoardHeight() ; 
      int width = board.getBoardWidth() ; 

    if (event.type == Event::MouseButtonPressed) {   
                if (event.mouseButton.button == Mouse::Left) {
                    
               

                    b = (event.mouseButton.x - szerokosc/2 + (width * 40/2 )) /40 ;
                    a = (event.mouseButton.y - wysokosc/2 +(height *40/2))/40 ;  
                          board.revealField(a, b);
                }
                if (event.mouseButton.button == Mouse::Right) {
                    
                     b = (event.mouseButton.x - szerokosc/2 + (width * 40/2 )) /40 ;
                     a = (event.mouseButton.y - wysokosc/2 +(height *40/2)) /40 ;
                   
                    board.toggleFlag(a, b);
                }
            } 
        }
