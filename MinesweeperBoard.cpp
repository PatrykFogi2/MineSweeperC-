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
    [1][8] = {0,0,1};
    board[0][2] = {1,1,0};
    */
    board[1][8] = {0,1,0};
  
  
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


int MinesweeperBoard::getBoardWidth() const //działa
{
   return width;
}


int MinesweeperBoard::getBoardHeight() const //działa
{
  return height;
}


int MinesweeperBoard::getMineCount() const //działa
{
  int mines = 0;
  for(int line=0; line<height; line++)
    {
        for(int column=0; column<width; column++)
        {

         if(board[line][column].hasMine == true)
            mines +=1;             
        }
    }
  return mines;
}




int MinesweeperBoard::countMines(int row, int col) const //
{
  int mines = 0;  
  
  if(row>=height || col>=width) //za polem
    return -1;
  
  if(board[row][col].isRevealed ==1) //nieodkryty
    return -1;
   
   else
    {
      if(board[row-1][col-1].hasMine == 1 )
        mines++;
      if(board[row-1][col].hasMine == 1 )
        mines++;
      if(board[row-1][col+1].hasMine == 1 )
        mines++;
      if(board[row][col+1].hasMine == 1 )
        mines++;
      if(board[row][col-1].hasMine == 1 )
        mines++;
      if(board[row+1][col+1].hasMine == 1 )
        mines++;
      if(board[row-1][col+1].hasMine == 1 )
        mines++;
      if(board[row+1][col-1].hasMine == 1 )
        mines++;
      //zapytac sie czemu petla nie dzialala
      
    }
    return mines;
}

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
 void MinesweeperBoard::toggleFlag(int row, int col)
 {
     firstMove = true;
     if(board[row][col].isRevealed ==0)
        board[row][col].hasFlag =1;
     
     if(board[row][col].isRevealed ==0) 
       return;
     if(row>=height || col>=width) //za polem
       return;
     if(getGameState()==FINISHED_WIN)
       return;    
 }
 

//////////////////////////////////////////////////////////////////////////////


bool MinesweeperBoard::isRevealed(int row, int col) const
  {
     if(board[row][col].isRevealed ==1)
       return true;     
  }
 
 //////////////////////////////////////////////////////////////////////////////
 char MinesweeperBoard::getFieldInfo(int row, int col) const //sprawdz
 {
    if(row>=height || col>=width) //za polem
      return '#';
    if(board[row][col].hasFlag==true && board[row][col].isRevealed==false )   
      return 'F';
    if(board[row][col].hasFlag==false && board[row][col].isRevealed==false )   
      return '_';
    if(board[row][col].hasMine==true && board[row][col].isRevealed==true )   
      return 'x'; 
    if(board[row][col].hasMine==true && countMines(row,col) ==0 )   
      return ' '; 
    if(board[row][col].hasMine==true && countMines(row,col) > 0 )   
      return countMines(row, col);  
 }
 

void MinesweeperBoard::revealField(int row, int col)
{
  board[row][col].isRevealed = 1;
   
   if(row>=height || col>=width)
     return;
   if (getGameState()==FINISHED_WIN)
     return;
   if (board[row][col].hasFlag == 1)
     return;
   if (board[row][col].isRevealed ==0 && board[row][col].hasMine==0)  
     board[row][col].isRevealed =1;
   if (board[row][col].isRevealed ==0 && board[row][col].hasMine==1) 
     {
         firstMove == false;  
         
     }


}

 
 GameState MinesweeperBoard::getGameState() const
 {
   
 }
 