/**
*File: Knight.cpp
*Author: Ashli Mosiman
*KUID Number: 2819456
*Date Last Updated: March 21,2016
*Purpose: Defines all methods of the Knight class in order to see if the Knight can move to each square once with four given integers
**/


#include "Knight.h"

Knight::Knight()
{
  initRow=0;
  initCol=0;
  boardRow=1;
  boardCol=1;
  stepNum=0;
}//ends arbitrary class definition

Knight::Knight(int sizeRow, int sizeCol, int startRow, int startCol)
{
  initRow=startRow;//value for the Knight's starting position's row
  initCol=startCol;//value for the Knight's starting position's column
  boardRow=sizeRow;//value for the number of rows on the board
  boardCol=sizeCol;//value for the number of columns on the board
  stepNum=0;//starts the count of moves at zero
}//ends second class definition

bool Knight::canMove(int row, int col)
{
  if(row < 0 || row >= boardRow || col < 0 || col >= boardCol)//the next move is located on the board
  {
    return(false);
  }
  else if(board[row][col] >= 0)//prospective square for the next move hasn't been landed on
  {
    return(false);
  }
  return(true);//the Knight can move to the next square
}//ends method

void Knight::initBoard()
{
  //fills board with the value negative one
  for(int x=0;x<boardRow;x++)
  {
    for(int y=0;y<boardCol;y++)
    {
      board[x][y]=-1;
    }//ends second for loop
  }//ends first for loop
}//ends method

void Knight::tracker()
{
  initBoard();//initializes the board
  board[initRow][initCol]=stepNum;//establishing the starting position of the Knight to be step 0

  std::cout<<'\n'<<'\t'<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<'\n'
          <<'\t'<<'\t'<<"WELCOME TO THE GRAND KNIGHT'S TOUR"<<'\n'
          <<'\t'<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<'\n';


  if(isSolution(initRow,initCol,stepNum))//first call of the recursive method
  {                                       //prints message saying a path exists and prints board
    std::cout<<'\n'<<"BRILLIANT! It worked!"<<'\n';
    for(int x=0; x<boardRow; x++)
    {
      for(int y=0; y<boardCol; y++)
      {
          std::cout<<'['<<std::setfill(' ')<<std::setw(2)<<board[x][y]<<']';
      }//ends second for loop
      std::cout<<'\n';
    }//ends first for loop
  }//ends if
  else//says the path doesn't exists and prints empty board except the starting position
  {
    std::cout<<'\n'<<"Ah Fudge it! It could not be done."<<'\n';
    for(int x=0; x<boardRow; x++)
    {
      for(int y=0; y<boardCol; y++)
      {
        if(x == initRow && y == initCol)
        {
          std::cout<<'['<<std::setfill(' ')<<std::setw(2)<<board[x][y]<<']';
        }
       else
        {
          std::cout<<'['<<"  "<<']';
        }
      }//end second for loop
      std::cout<<'\n';
    }//ends first for loop
  }//ends else
  std::cout<<'\n';
}//ends method


bool Knight::isSolution(int r, int c, int count)//recursive
{
  //arrays to hold values of possible moves
  int moveR[8]={-2,-2,-1,-1,1,1,2,2};
  int moveC[8]={-1,1,-2,2,-2,2,-1,1};

  if(count == ((boardRow*boardCol)-1))//base case: reached last step of existing path
  {
    return(true);
  }
  for(int i=0;i<8;i++)//runs through possible moves and backtracks to test other possible paths
  {
    if(canMove(r+moveR[i],c+moveC[i]))//numbers the square if it's a valid move or sets to negative one if the path is a dud
    {
      board[r+moveR[i]][c+moveC[i]]=count+1;
      if(isSolution(r+moveR[i],c+moveC[i],count+1))//recursive call of the method
      {
        return(true);
      }
      else
      {
        board[r+moveR[i]][c+moveC[i]]=-1;
      }
    }
  }//ends for loop
  return(false);//returning false if there's no more moves
}//ends method
