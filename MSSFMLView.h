#ifndef MSSFMLVIEW_H__
#define MSSFMLVIEW_H__

#include <SFML/Graphics.hpp>
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"
using namespace sf;

class MSSFMLView
{
	MinesweeperBoard & board;
public:
	explicit MSSFMLView(MinesweeperBoard & b);

	void draw (sf::RenderWindow & win);
};

#endif