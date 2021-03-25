#ifndef MineSweeeperBoard_H__
#define MineSweeeperBoard_H__

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

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
  GameMode mode;   //poziom
  //first move
  bool firstMove = false;
  
public:
  
  MinesweeperBoard(int width, int height, GameMode mode);
  void debug_display() const;
  int getBoardWidth() const;
  int getBoardHeight() const;
  int getMineCount() const;
  int countMines(int row, int col) const;
  bool hasFlag(int row, int col) const;
  void toggleFlag(int row, int col); 
  void revealField(int row, int col);
  bool isRevealed(int row, int col) const; 
  char getFieldInfo(int row, int col) const;
    GameState getGameState() const;
};





#endif