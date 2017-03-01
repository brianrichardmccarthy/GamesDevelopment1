//
//  main.cpp
//  TicTacToe
//
//  Created by 20063914 on 01/03/2017.
//  Copyright © 2017 20063914. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::cout;
using std::vector;
using std::cin;
using std::endl;

// global constants
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

//function prototypes
void instructions();
char askYesNo(string question);
// int askNumber(string question, int high, int low = 0);
char humanPiece();
/* char opponent(char piece);
void displayBoard(const vector<char>& board);
char winner(const vector<char>& board);
bool isLegal(const vector<char>& board, int move);
int humanMove(const vector<char>& board, char human);
int computerMove(vector<char> board, char computer);
void announceWinner(char winner, char computer, char human);*/

int main(int argc, const char * argv[]) {
    int move;
    const int NUM_SQUARES = 9;
    vector<char> board(NUM_SQUARES, EMPTY);
    
    instructions();
    
    char response = humanPiece();
    cout << "Response: " << response << endl;
    
    /*char human = humanPiece();
    char computer = opponent(human);
    char turn = X;
    displayBoard(board);
    
    while (winner(board) == NO_ONE)
    {
        if (turn == human)
        {
            move = humanMove(board, human);
            board[move] = human;
        }
        else
        {
            move = computerMove(board, computer);
            board[move] = computer;
        }
        displayBoard(board);
        turn = opponent(turn);
    }
    
    announceWinner(winner(board), computer, human);*/
    
    return 0;
}


void instructions() {
    cout << "Welcome to the unlimited man-machine showdown: Tic-Tac-Toe." << endl;
    cout << "--where human brain is pit against silicon processor." << endl;
    cout << "\nMake your move known by entering a number 0 - 8. The number corresponds to the desired board position, an illustration:" << endl;
    cout << "\n\t 0 | 1 | 2 " << endl;
    cout << "\t-----------" << endl;
    cout << "\t 3 | 4 | 5 " << endl;
    cout << "\t-----------" << endl;
    cout << "\t 6 | 7 | 8 " << endl;
    cout << "\nPrepare yourself, human. The battle is about to begin." << endl;
    
}

char askYesNo(string question) {
    char response = 'Q';
    
    while (response != 'y' && response != 'n' ) {
        cout << question << " y or n: ";
        cin >> response;
        response = tolower(response);
    }
    
    return response;
}

char humanPiece() {
    return (askYesNo("Do you want to go first?") == 'y') ? X : O;
}
