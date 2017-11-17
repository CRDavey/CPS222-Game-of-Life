//  main.cpp
//  GameOfLIfe
//
//  Created by Kenneth Burgess, Cody Davey on 2/8/15.
//  Copyright (c) 2015 VV Development. All rights reserved.
//

#include <iostream>
#include "board.h"

using namespace std;

static const char ESC = 27;

//Initiates and controls the game of life
int main(int argc, const char * argv[]) {
    // Declares input variables
    int numberOfOrganisms;
    int numberOfGenerations;
    
    // Collect Initial Input from User (setting of the game)
    cout << "How many organisms initially? ";
    cin >> numberOfOrganisms;
    int locations[numberOfOrganisms][2]; //prepares an 2 dim array of integers that will store the location of each organism
    cout << "Locations? ";
    for (int i=0; i<numberOfOrganisms; i++) //collects the user's input
    {
        cin >> locations[i][0]; //assigns first int  to the organisms x-coordinate
        cin >> locations[i][1]; //assigns second int to the organisms y-coordinate
    }
    cout << "Generations? ";
    cin >> numberOfGenerations;
    while (cin.get() != '\n');  //flushes the input buffer
    
    Board gameBoard = Board(numberOfOrganisms,locations); //initializes the game board
    
    cout << ESC << "[H" << ESC << "[J" << "Initial:" << endl; //clears the screen
    gameBoard.display(); //displays the initial gameBoard
    for (int i=0; i<numberOfGenerations; i++)
    {
        cout << ESC << "[23;1H" << ESC << "[K" << "Press RETURN to continue";
        while (cin.get() != '\n');
        gameBoard.nextGen(); //updates the game board to the next generation
        cout << ESC << "[H" << "Generation " << i+1 << ":" << endl;
        gameBoard.display();
    }
    cout << "You have now completed the game of life";
    return 0;
}

//included in main file since cout doesn't work in class files
//displays the board
void display(Board gameBoard){
    
}