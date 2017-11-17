//  board.cpp
//  GameOfLIfe
//
//  Created by Kenneth Burgess on 2/8/15.
//  Copyright (c) 2015 VV Development. All rights reserved.
//


#include "board.h"
using namespace std;

/* Constructor, placing living organisms in the locations provided */
Board::Board(int initialOrganisms, int locations[][2])
{
    for (int i=0; i<totalRows; i++) {
        for (int j=0; j<totalCols; j++) {
            _board[i][j] = NONE;
        }
    }
    //places initial organisms on board (setting them to living)
    for (int i=0; i<initialOrganisms; i++) {
        _board[locations[i][0]][locations[i][1]] = LIVING;
    }
}

/* determines if there is an organism in the (x,y) location */
bool Board::hasOrganism(int x, int y){
    if (_board[x][y] == LIVING) {
        return true;
    }
    return false;
}

/* Counts the organisms surrounding an (x,y) location */
int Board::countSurroundingOrganisms(int x, int y)
{
    int count = 0;
    for (int i=-1; i<2; i++){
        for (int j=-1; j<2; j++){
            //note that if an organism is dying, it should still be counted, as it hasn't died yet!
            if (_board[x+i][y+j]==LIVING || _board[x+i][y+j] == DYING){
                //can't count the middle square
                if (not(i==0 and j==0)){
                    count++;
                }
            }
        }
    }
    return count;
}

/* Goes through another circle of life */
void Board::nextGen()
{
    //iterators start at 1 since no organisms can live on the first row or column
    //this loop sets the state of each cell to Gestating or Dying based on the number of organisms surrounding it
    for (int i=1; i<totalRows; i++) {
        for (int j=1; j<totalCols; j++) {
            int surrounding_Organisms = this -> countSurroundingOrganisms(i,j);
            if (_board[i][j] == LIVING){
                if (surrounding_Organisms<minSurrounding) {
                    _board[i][j] = DYING; //dies of loneliness
                }
                else if (surrounding_Organisms>maxSurrounding) {
                    _board[i][j] = DYING; //dies of overcrowding
                }
            }
            //else there is no organism in the space
            else if (surrounding_Organisms==neighboringBirthReq){
                _board[i][j] = GESTATING; // a new organism is born
            }
        }
    }
    //this loop sets the state of all GESTATING cells to LIVING and all DYING cells to NONE
    for (int i=1; i<totalRows; i++) {
        for (int j=1; j<totalCols; j++) {
            if (_board[i][j] == DYING){
                _board[i][j] = NONE; //kills a dying organism
            }
            else if (_board[i][j] == GESTATING){
                _board[i][j] = LIVING;
            }
        }
    }
}

/* prints the board out to the terminal */
void Board::display()
{
    //top row
    cout << "+--------------------------------------------------+" << endl;
    for (int i=1; i<totalRows-1; i++){
        cout << "|";
        for (int j=1; j<totalCols-1; j++) {
            if (this->hasOrganism(i,j)){
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << "|" << endl;
    }
    //bottom row
    cout << "+--------------------------------------------------+" << endl;
}
