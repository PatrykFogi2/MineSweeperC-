#include "MinesweeperBoard.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode)  
{
    this -> width = width;
    this -> height = height;
    this -> mode = mode;
    this -> FirstMove = 0;
    //plansza 000
    for (int row=0; row<height; row++) 
    {
      for (int column=0; column<width; column++)
        {
           board[row][column] = {false,false,false};
        }
    }


  
  
  srand( time( NULL ) );
double mines =0;
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


bool MinesweeperBoard::Czy_Srodek (int row, int col) const
{
  if(row>=height || col>=width || row<0 || col <0)
    return false;
  return true;
}


//////////////////////////////////////////////////////////////////////////////
//Funkcja debug_display() ma: wyświetlić planszę w celu weryfikacji poprawności przeprowadzanych operacji - każde pole ma być wyświetlone jako ciąg 3 znaków w nawiasach kwadratowych. 

void  MinesweeperBoard::debug_display() const //działa
{
  for(int row=0; row<height; row++)
    {
        for(int column=0; column<width; column++)
        {
          if(board[row][column].hasMine == true)
            cout<< "[M";
          else
          cout <<"[.";
          if(board[row][column].isRevealed == true)
            cout<< "o";
          else
          cout <<".";
          if(board[row][column].hasFlag == true)
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
   if(Czy_Srodek(row,col) == false) //za polem
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
     if(Czy_Srodek(row,col)==0 || state==FINISHED_WIN || board[row][col].isRevealed ==1)
       return;
     else 
       board[row][col].hasFlag = 1;
      
          
 }


//////////////////////////////////////////////////////////////////////////////
//dziala

bool MinesweeperBoard::isRevealed(int row, int col) const
  {
     if(Czy_Srodek(row,col)==false) //za polem
       return false;
     if(board[row][col].isRevealed ==1)
       return true;  
     return false;      
  }
 //////////////////////////////////////////////////////////////////////////////

int MinesweeperBoard::countMines(int row, int col) const //
{
  int mines = 0;  
  
  if(Czy_Srodek(row,col)== 0) //za polem
    return -1;
  
  if(board[row][col].isRevealed ==0) //nieodkryty
    return -1;
   
   else
    {
      if(Czy_Srodek(row-1, col-1) == 1 && board[row-1][col-1].hasMine == 1  )
        mines++;
      if(Czy_Srodek(row-1, col) && board[row-1][col].hasMine == 1 )
        mines++;
      if(Czy_Srodek(row-1, col+1) && board[row-1][col+1].hasMine == 1 )
        mines++;
      if(Czy_Srodek(row, col+1) && board[row][col+1].hasMine == 1 )
        mines++;
      if(Czy_Srodek(row, col-1) &&  board[row][col-1].hasMine == 1 )
        mines++;
      if(Czy_Srodek(row+1 , col) &&  board[row+1][col].hasMine == 1 )
        mines++;
      if(Czy_Srodek(row+1, col+1) &&  board[row+1][col+1].hasMine == 1 )
        mines++;
      if(Czy_Srodek(row+1, col-1) &&  board[row+1][col-1].hasMine == 1 )
        mines++;
    }
    return mines;
}

//////////////////////////////////////////////////////////////////////////////

  GameState MinesweeperBoard::getGameState() const
 {
     
    int flags = 0;
    
    for(int row=0; row<height; row++)
      {
          for(int column=0; column<width; column++)
            {
                if(board[row][column].isRevealed==1 && board[row][column].hasMine==1)
                  return FINISHED_LOSS; 
                if(board[row][column].hasFlag ==1 && board[row][column].hasMine==1 )
                  flags++;  
            }
    
      }

    if(getMineCount()==flags || FirstMove + getMineCount() ==height * width)
     {
         return FINISHED_WIN;  
     }    
      
  return RUNNING;
 }

//////////////////////////////////////////////////////////////////////////////

char MinesweeperBoard::getFieldInfo(int row, int col) const 
 {
      
    if(Czy_Srodek(row,col)== false) //za polem
      return '#'; 
    else if(board[row][col].hasFlag==true && board[row][col].isRevealed==false )   
      return 'F'; 
    else if(board[row][col].hasFlag==false && board[row][col].isRevealed==false )   
      return '_'; 
    else if(board[row][col].hasMine==true && board[row][col].isRevealed==true )   
      return 'x'; 
    else if(board[row][col].isRevealed==true && countMines(row,col) == 0 )   
      return ' '; 
    else if(board[row][col].isRevealed==true && countMines(row,col) != 0 )  
      {
        char x ='0' + countMines(row, col);
        return  x;  
      }
 }
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
void MinesweeperBoard::revealField(int row, int col)
{
  FirstMove ++;
  if (Czy_Srodek(row,col) == 0 || board[row][col].hasFlag == 1 || getGameState()!=RUNNING || board[row][col].isRevealed == 1 )
     return;
  if (board[row][col].hasMine == 0 && board[row][col].isRevealed == 0)
    {
      board[row][col].isRevealed = 1;   //bez miny
    }

   if ( board[row][col].hasMine== 1 && board[row][col].isRevealed == 0)   //mina first move
    {
        if (FirstMove == 1 &&  mode !=DEBUG)
        {
            PrzeniesMine(row,col);
        }
            
      
      
          else {
          board[row][col].isRevealed = 1;
          state = FINISHED_LOSS; }   
    
    }
} 


//////////////////////////////////////////////////////////////////////////////

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
  for(int row=0; row<height; row++)
    {
        for(int column=0; column<width; column++)
        {
         if(board[row][column].hasMine == true)
            mines +=1;             
        }
    }

return mines;
}

void MinesweeperBoard::PrzeniesMine(int row, int col) 
{
              bool x = false;
              int rand_col; int rand_row;                
            
           do {
                rand_row = rand() % height;
                rand_col = rand () % width;

                if(board[rand_row][rand_col].hasMine ==0 ) {
                    board[rand_row][rand_col].hasMine = 1;
                     x =  true;
                   } 
            } while( x == false);
   board[row][col].hasMine = 0;       
   board[row][col].isRevealed = 1;   
}
 