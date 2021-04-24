#include <SFML/Graphics.hpp>
#include <iostream>
#include "MSSFMLView.h"
#include "MinesweeperBoard.h"
using namespace sf;
using namespace std;

MSSFMLView::MSSFMLView(MinesweeperBoard & b) : board(b) {
    

}



void MSSFMLView::draw (sf::RenderWindow & win)
{
	// tu robimy rysowanie planszy na podstawie zawartości "board"
	
	sf::RectangleShape r;
	r.setSize ( sf::Vector2f(10, 10) ) ;
	r.setFillColor ( sf::Color::Red );
	r.setPosition(100,100);
	win.draw(r);
    //poczatek commita
}