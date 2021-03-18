#ifndef MineSweeeperBoard_H__
#define MineSweeeperBoard_H__

struct Field
{
	bool hasMine;
	bool hasFlag;
	bool isRevealed;
};


class MinesweeperBoard
{
  Field board[100][100];    // 100-elementowa tablica, 100-elementowych tablic typu Field 
  int width;                // rzeczywista szerokość planszy
  int height;               // rzeczywista wysokość planszy

public:
  MinesweeperBoard();
  void debug_display() const;
};





#endif