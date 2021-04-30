#include "MinesweeperBoard.h"
#include "MSSFMLView.h"


#ifndef MouseController_H__
#define MouseController_H__

namespace sf 
{
 class event;
}

class MinesweeperBoard;
class MSSFMLView;

class MouseController {
MinesweeperBoard & board;
MSSFMLView & View;
public:
MouseController(MinesweeperBoard & bo, MSSFMLView & Vi);
void wydarzenie(sf::Event &event);
};





#endif