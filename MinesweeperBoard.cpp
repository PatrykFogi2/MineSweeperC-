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
    



    
    for (int line=0; line<height; line++) 
    {
      for (int column=0; column<width; column++)
        {
           board[line][column] = {false,false,false};
        }
    }


    /*
    board[0][0] = {1,0,0};
    [1][8] = {0,0,1};
    board[0][2] = {1,1,0};
    */
    //board[8][7] = {0,0,0};
  
  
double mines =0;
  switch(this->mode) //dziala
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

  int row =0; int col=0;
  int c = height-1; int d= width -1;
  int i =0; 
 
  while(i<mines)  
  {
     row=rand()%c;
     col=rand()%d;
  
     if(board[row][col].hasMine==1)
       {
         continue;
       }
  
      else
        {
          board[row][col].hasMine=1;
          i++;
        }
  } 

}

//////////////////////////////////////////////////////////////////////////////
//Funkcja debug_display() ma: wyświetlić planszę w celu weryfikacji poprawności przeprowadzanych operacji - każde pole ma być wyświetlone jako ciąg 3 znaków w nawiasach kwadratowych. 

void  MinesweeperBoard::debug_display() const //działa
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





//////////////////////////////////////////////////////////////////////////////
//dziala

 bool MinesweeperBoard::hasFlag(int row, int col)  const //sprawdz
 {
     
   if(board[row][col].hasFlag ==1)
     return true;
     
     
   if(row>=height || col>=width) //za polem
    return false; 
   if(board[row][col].hasFlag ==0)
     return false; 
    if(board[row][col].isRevealed ==1)
     return false; 
     
 }

//////////////////////////////////////////////////////////////////////////////
 //dziala
 void MinesweeperBoard::toggleFlag(int row, int col)
 {
     
     if(row>=height || col>=width) //za polem
       return;
     if(getGameState()==FINISHED_WIN)
       return; 
      if(board[row][col].isRevealed ==1) 
       return; 
     
     if(board[row][col].isRevealed ==0)
        board[row][col].hasFlag =1;
          
 }
 

//////////////////////////////////////////////////////////////////////////////
//dziala

bool MinesweeperBoard::isRevealed(int row, int col) const
  {
     if(board[row][col].isRevealed ==1)
       return true;  
     return false;      
  }
 
 

  /*

  int line = row; int column = col; mines = 0; 
for(line=row-1; line>row+1; line++)
    {
           
           if(board[line][col].hasMine==1 && line!=raw)
            mines++;
           if(board[line][col-1].hasMine==1)
            mines++;
            if(board[line][col+1].hasMine==1)
            mines++; 

        } 
        return mines;
     }



  */
