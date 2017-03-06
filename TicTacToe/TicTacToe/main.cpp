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
int askNumber(string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<char>& board);
char winner(const vector<char>& board);
bool isLegal(const vector<char>& board, int move);
int humanMove(const vector<char>& board, char human);
int computerMove(vector<char> board, char computer);
void announceWinner(char winner, char computer, char human);

int main(int argc, const char * argv[]) {
    int move;
    const int NUM_SQUARES = 9;
    vector<char> board(NUM_SQUARES, EMPTY);
    
    instructions();
    char human = humanPiece();
    char computer = opponent(human);
    char turn = X;
    displayBoard(board);
    
    while (winner(board) == NO_ONE) {
        if (turn == human) {
            move = humanMove(board, human);
            board[move] = human;
        } else {
            move = computerMove(board, computer);
            board[move] = computer;
        }
        displayBoard(board);
        turn = opponent(turn);
    }
    
    announceWinner(winner(board), computer, human);
    
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

char opponent(char piece) {
    return (piece == X) ? O : X;
}

void displayBoard(const vector<char>& board) {

    cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
    cout << "\n\t" << "---------";
    cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
    cout << "\n\t" << "---------";
    cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
    cout << "\n\n";
}

char winner(const vector<char>& board) {
    
    const int TOTAL_ROWS = 8;
    // all possible winning rows
    const int WINNING_ROWS[TOTAL_ROWS][3] = { {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6} };
    
    // if any winning row has three values that are the same (and not EMPTY),
    // then we have a winner
    for (int row = 0; row < TOTAL_ROWS; ++row) {
        if ( (board[WINNING_ROWS[row][0]] != EMPTY) &&  // without this three empties would meet the winning condition
            (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
            (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]) ) {
                return board[WINNING_ROWS[row][0]]; // returns 'X' or 'O'
        }
    }
    
    // since nobody has won, check for a tie (no empty squares left)
    if (count(board.begin(), board.end(), EMPTY) == 0) return TIE;  // TIE = 'T'
    
    // since nobody has won and it isn't a tie, the game ain't over
    return NO_ONE;  // NO_ONE = 'N'
}

int humanMove(const vector<char>& board, char human) {
    int move = askNumber("Where will you move?", ((int)board.size() - 1)); // note use of default parameters
    while (!isLegal(board, move))
    {
        cout << "\nThat square is already occupied, foolish human.\n";
        move = askNumber("Where will you move?", ((int)board.size() - 1));
    }
    cout << "Fine...\n";
    
    return move;
}

inline bool isLegal(const vector<char>& board, int moves) {
    return (board[moves] == EMPTY);
}

int askNumber(string question, int high, int low) {
    int number;
    do {
        cout << question << " (" << low << " - " << high << "): ";
        cin >> number;
    } while (number > high || number < low);
    
    return number;
}

// board passed by value as AI will experiement with various moves
// to find optimum move
int computerMove(vector<char> board, char computer) {
    unsigned int move = 0;
    bool found = false;  // AI's move found (or not)
    
    //if computer can win on next move, that is the move to make
    while (!found && move < board.size()) {
        if (isLegal(board, move)) {
            //try move
            board[move] = computer;
            //test for winner
            found = winner(board) == computer;   //found changes to true if the move make AI the winner
            //undo move
            board[move] = EMPTY;
        }
        
        if (!found) {
            ++move;  // try the next move
        }
    }
    
    //otherwise, if opponent can win on next move, that's the move to make
    if (!found) {
        move = 0;
        char human = opponent(computer);
        
        while (!found && move < board.size()) {
            if (isLegal(board, move)) {
                //try move
                board[move] = human;
                //test for winner
                found = winner(board) == human;
                //undo move
                board[move] = EMPTY;
            }
            
            if (!found) {
                ++move;
            }
        }
    }
    
    //otherwise, moving to the best open square is the move to make
    if (!found) {
        move = 0;
        unsigned int i = 0;
        
        const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
        //pick best open square
        while (!found && i <  board.size()) {
            move = BEST_MOVES[i];
            if (isLegal(board, move)) {
                found = true;
            }
            
            ++i;
        }
    }
    
    cout << "I shall take square number " << move << endl;
    return move;
}

void announceWinner(char winner, char computer, char human) {
    if (winner == computer) {
        cout << winner << "'s won!\n";
        cout << "As I predicted, human, I am triumphant once more -- proof\n";
        cout << "that computers are superior to humans in all regards.\n";
    } else if (winner == human) {
        cout << winner << "'s won!\n";
        cout << "No, no!  It cannot be!  Somehow you tricked me, human.\n";
        cout << "But never again!  I, the computer, so swear it!\n";
    } else {
        cout << "It's a tie.\n";
        cout << "You were most lucky, human, and somehow managed to tie me.\n";
        cout << "Celebrate... for this is the best you will ever achieve.\n";
    }
}
