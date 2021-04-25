#include <SFML/Graphics.hpp>
#include <iostream>
#include "MSSFMLView.h"
#include "MinesweeperBoard.h"
using namespace sf;
using namespace std;

MSSFMLView::MSSFMLView(MinesweeperBoard & b) : board(b) 

{
    zakryte = RectangleShape(Vector2f(40,40));
    zakryte.setFillColor(Color(128,128,128));
    linia_poz = RectangleShape(Vector2f(40,1));
    linia_poz.setFillColor(Color(2,210,96));
    
    linia_pion = RectangleShape(Vector2f(1,40));
    linia_pion.setFillColor(Color(2,210,96));
    odkryte = RectangleShape(Vector2f(40,40));
     odkryte.setFillColor(Color(0,0,255));
    

  

}



void MSSFMLView::draw (sf::RenderWindow & win)
{
    //wczytuje przed petla
   font.loadFromFile("/home/runner/SFML-WON-SAPER/resources/arial-narrow_[pl.allfont.net].ttf");


  int height = board.getBoardHeight() ; 
  int width = board.getBoardWidth() ; 
  for(int row =0; row<height ; row++){
    for (int col =0 ; col <width; col++){

      int a = row * 40; int b = col * 30;

      if(board.isRevealed(row,col) == 0)
        {
            zakryte.setPosition(a,b);
            win.draw(zakryte);
        }
      if(board.isRevealed(row,col)== 1)  
        {
            odkryte.setPosition(a,b);
            win.draw(odkryte);
        }
      if(board.getFieldInfo(row,col)!='0')
        {   
            txt.setFont(font);
            txt.setString(board.getFieldInfo(row,col));
            txt.setFillColor(sf::Color::Red);
            
            txt.setPosition(a+15,b-3); // a -x b - y
           linia_pion.setPosition(a,b); 
            linia_poz.setPosition(a,b); 
           win.draw(linia_pion);
           win.draw(linia_poz);
           win.draw(txt);
        }
       



    }

  }
	// tu robimy rysowanie planszy na podstawie zawartości "board"
	
	// sf::RectangleShape r;
	// r.setSize ( sf::Vector2f(10, 10) ) ;
	// r.setFillColor ( sf::Color::Red );
	// r.setPosition(100,100);
	// win.draw(r);
    //poczatek commita
}