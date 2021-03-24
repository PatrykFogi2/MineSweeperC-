#include "MinesweeperBoard.h"
#include <iostream>
using namespace std;
MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)  
{
    this ->width = width;
    this -> height = height;
    this -> mode = mode;
    //width = 10;
    //height = 10;
    



    
    for (int line=0; line<height; line++)  {
      for (int column=0; column<width; column++)
        {
           board[line][column] = {false,false,false};
        }
    }
    /*
    board[0][0] = {1,0,0};
    board[1][0] = {0,0,1};
    board[0][2] = {1,1,0};
    */
    
  int mines = 0;
  switch(this->mode)
  {
      case EASY:
        mines=height*width*0.1;
        break;
      case NORMAL:
        mines=height*width*0.2;
        break;
      case HARD:
        mines=height*width*0.3;
        break;
      case DEBUG:
        int tmp = 0;
        while(tmp<width)
          {
              // line column
            board[0][tmp] = {1,0,0};
            board[tmp][tmp] = {1,0,0};
            if (tmp%2==0)
            board[tmp][0] = {1,0,0};
            
              tmp ++;
          }
        break;

  }














}


//Funkcja debug_display() ma: wyświetlić planszę w celu weryfikacji poprawności przeprowadzanych operacji - każde pole ma być wyświetlone jako ciąg 3 znaków w nawiasach kwadratowych. 

void  MinesweeperBoard::debug_display() const
{
  for(int line=0; line<height; line++)
    {
        for(int column=0; column<width; column++)
        {
          if(board[line][column].hasMine == true)
            cout<< "[M";
          else
          cout <<"[.";
          if(board[line][column].isRevealed == true)
            cout<< "o";
          else
          cout <<".";
          if(board[line][column].hasFlag == true)
            cout<< "f]";
          else
            cout <<".]";
        }
        cout <<"\n" <<endl;
    }
}


int MinesweeperBoard::getBoardWidth() const
{
   return width;
}


int MinesweeperBoard::getBoardHeight() const
{
  return height;
}


int MinesweeperBoard::getMineCount() const
{
  int mines = 0;
  for(int line=0; line<height; line++)
    {
        for(int column=0; column<width; column++)
        {

         if(board[line][column].hasMine == true)
            mines +=1; 
            continue;
        }
    }
  return mines;
}

int MinesweeperBoard::countMines(int row, int col) const
{
  int count = 0;
  if(row>height || col>width)
    count = -1;
  else 
  while (board[row][col]== )
  if (board[row][col].hasMine ==true && (row>height || col>width))
    count ++;
    
    
    
    // if the field at (row,col) was not revealed - return -1 ?
    


  return count;
}

    



  //int getBoardHeight() const;
//  int getMineCount() const;