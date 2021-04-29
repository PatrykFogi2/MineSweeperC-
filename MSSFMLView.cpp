#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
#include "MSSFMLView.h"
#include "MinesweeperBoard.h"
using namespace sf;
using namespace std;

MSSFMLView::MSSFMLView(MinesweeperBoard & b) : board(b) 

{
    zakryte = RectangleShape(Vector2f(40,40));
    zakryte.setFillColor(Color(128,128,128));
    linia_poz = RectangleShape(Vector2f(40,1));
    linia_poz.setFillColor(Color(255,255,255));
    
    linia_pion = RectangleShape(Vector2f(1,40));
    linia_pion.setFillColor(Color(255,255,255));
    odkryte = RectangleShape(Vector2f(40,40));
     odkryte.setFillColor(Color(135,120,135));

     bomba = CircleShape(8);
     bomba.setFillColor(Color(0,0,0));
      lont = RectangleShape(Vector2f(2,8));
    lont.setFillColor(Color(0,0,0));
    lont.setRotation(45);
    
    flaga =CircleShape(8, 3);
    flaga.setFillColor(Color(255,0,0));
    flaga.setRotation(30);

     stick = RectangleShape(Vector2f(3,25));
     stick.setFillColor(Color(0,0,0));
     font.loadFromFile("/home/runner/SFML-WON-SAPER/resources/arial-narrow_[pl.allfont.net].ttf");
  
}



void MSSFMLView::draw (sf::RenderWindow & win)
{

   
   
//    font.loadFromFile("/home/runner/SFML-WON-SAPER/resources/arial-narrow_[pl.allfont.net].ttf");
  
   
  int wysokosc = 600;
  int szerokosc =800;
  int height = board.getBoardHeight() ; 
  int width = board.getBoardWidth() ; 
  for(int row =0; row<height ; row++){
    for (int col =0 ; col <width; col++){

 
    int a,b;
    a = szerokosc/2 + col * 40 - (height*40/2) ;
    b = wysokosc/2 + row * 30 - (width*30/2);
    // a = row * 40;
    // b = col * 30;
      

      if(board.isRevealed(row,col) == 0)
        {
            zakryte.setPosition(a,b);
            win.draw(zakryte);
             linia_pion.setPosition(a,b); 
            linia_poz.setPosition(a,b); 
           win.draw(linia_pion);
           win.draw(linia_poz);
        }
      if(board.isRevealed(row,col)== 1)  
        {
            odkryte.setPosition(a,b);
            win.draw(odkryte);
             linia_pion.setPosition(a,b); 
            linia_poz.setPosition(a,b); 
           win.draw(linia_pion);
           win.draw(linia_poz);
        }

        if(board.getFieldInfo(row,col) =='x' )
        {
           bomba.setPosition(a+12,b+8);
           lont.setPosition(a+25,b+4);
           win.draw(bomba);
           win.draw(lont);
           
        }
    
         if(board.getFieldInfo(row,col) =='F' )
        {
           flaga.setPosition(a+18,b);
           stick.setPosition(a+25,b+4);
           win.draw(flaga);
           win.draw(stick);
        }



      if(board.getFieldInfo(row,col)!='0' && board.getFieldInfo(row,col)!='_' && board.getFieldInfo(row,col)!='x' && board.getFieldInfo(row,col)!='F')
        {   
            txt.setFont(font);
            txt.setString(board.getFieldInfo(row,col));
           
            if(board.getFieldInfo(row,col)=='1')
              txt.setFillColor(Color::Red);
            if(board.getFieldInfo(row,col)=='2')
              txt.setFillColor(Color::Blue);
            if(board.getFieldInfo(row,col)=='3')
              txt.setFillColor(Color::Green);
            if(board.getFieldInfo(row,col)=='4')
              txt.setFillColor(Color::Yellow);
            if(board.getFieldInfo(row,col)=='5')
              txt.setFillColor(Color::Cyan);
            if(board.getFieldInfo(row,col)=='6')
              txt.setFillColor(Color::White);
            if(board.getFieldInfo(row,col)=='7')
              txt.setFillColor(Color::Black);
            if(board.getFieldInfo(row,col)=='8')
              txt.setFillColor(Color::Transparent);

             txt.setPosition(a+15,b-3); 
       
           win.draw(txt);
        }
        
    





    }

  }
	if(board.getGameState() == FINISHED_LOSS)
      {

         tekst.setFont(font);
         tekst.setCharacterSize(100);
         tekst.setPosition(200,30);
         tekst.setFillColor(sf::Color::Red);
         tekst.setString("YOU LOST");
         win.draw(tekst);
      }
    if(board.getGameState() == FINISHED_WIN)
      {
         tekst.setFont(font);
         tekst.setCharacterSize(100);
         tekst.setPosition(200,30);
         tekst.setFillColor(sf::Color::White);
         tekst.setString("YOU WON");
         win.draw(tekst);
      }

}