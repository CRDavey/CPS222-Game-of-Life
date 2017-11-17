//  board.h
//  GameOfLIfe
//
//  Created by Kenneth Burgess, Cody Davey on 2/8/15.
//  Copyright (c) 2015 VV Development. All rights reserved.


// the following ensures this header is only included once
#ifndef __GameOfLIfe__board__
#define __GameOfLIfe__board__

#include <stdio.h>
#include <iostream>
#endif /* defined(__GameOfLIfe__board__) */

/* This class serves to represent the board on which the game of Life operates, containing numerous organisms that
 * live and die according to our whims
 */
class Board
{
public:
    /* Constructor */
    Board(int initialOrganisms, int locations[] [2]);
    /*Accessor, kindof */
    bool hasOrganism(int x, int y);
    /* UPDATE board */
    void nextGen();
    /* DISPLAY board */
    void display();
    
private:
    /* Counts number of Organisms surrounding a space */
    int countSurroundingOrganisms(int x, int y);
    /* declares possible organism states */
    enum Organism { NONE, GESTATING, LIVING, DYING };
    /* CONSTANTS */
    static const int activeRows = 18;
    static const int activeCols = 50;
    static const int totalRows = activeRows + 2;
    static const int totalCols = activeCols + 2;
    static const int minSurrounding = 2; //if lower the organism dies of loneliness
    static const int maxSurrounding = 3; //if higher the organism dies of overcrowding
    static const int neighboringBirthReq = 3; //the number of neighboring organisms for a new organism to be born
    /* declares size of the board, composed of organisms */
    Organism _board[totalRows][totalCols];
};