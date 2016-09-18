/**
*File: Knight.h
*Author: Ashli Mosiman
*KUID Number: 2819456
*Date Last Updated: March 08,2016
*Purpose: Header file for the Knight class
**/
#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>
#include <string>
#include <array>
#include <iomanip>

const int ms=1000;//constant arbitrary integer to be the dimension of the 2D array, the board

class Knight
{
  private:
    int initRow;
    int initCol;
    int boardRow;
    int boardCol;
    int stepNum;
    int board[ms][ms];

  public:

    /**
    *  @pre None
    *  @post just the original definition of the Knight class
    *  @return None
    */
    Knight();

    /**
    *  @pre four valid integers
    *  @post establishes the four given integers as the board dimensions and the starting position of the Knight
    *  @return None
    */
    Knight(int sizeRow, int sizeCol, int startRow, int startCol);

    /**
    *  @pre two integers representing position of the next move
    *  @post tests whether the move can be made by the Knight
    *  @return true/false based on if the next move is possible
    */
    bool canMove(int row, int col);

    /**
    *  @pre 2D array exists
    *  @post sets up each value on the board to negative one
    *  @return None
    */
    void initBoard();

    /**
    *  @pre 2D array exists
    *  @post prints out the board and initial call of the recursive method
    *  @return None
    */
    void tracker();

    /**
    *  @pre three integers passed in for the position of the next move and the current step number
    *  @post recursively tests possible paths for the Knight until it gets a valid path or no possible paths exist
    *  @return true/false based on if a path to touch each square once exists
    */
    bool isSolution(int r, int c,int count);
};
#endif //KNIGHT_H
