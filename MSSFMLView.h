#ifndef MSSFMLVIEW_H__
#define MSSFMLVIEW_H__
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"
using namespace sf;

class MSSFMLView
{
	MinesweeperBoard & board;
     RectangleShape zakryte;
     RectangleShape odkryte;
    Font font;
    Text txt;
    Text tekst;
 
    
     RectangleShape linia_poz;
     RectangleShape linia_pion;
     CircleShape bomba;
     CircleShape flaga;
     RectangleShape stick;
     RectangleShape lont;
     
     
public:
	explicit MSSFMLView(MinesweeperBoard & b);

	void draw (sf::RenderWindow & win);
};

#endif