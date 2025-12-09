#include "TicTacToeGame.hpp"
#include <iostream>
using namespace std;

TicTacToeGame::TicTacToeGame() : tttBoard(), currRow(0), currCol(0) {}

TicTacToeGame::TicTacToeGame(int size) : tttBoard(size), currRow(0), currCol(0) {}

void TicTacToeGame::runRepeat() {
    char again = 'y';
    while (again == 'y' || again == 'Y') {
        tttBoard.clear();
        start();
        cout << "Play again? (y/n): ";
        cin >> again;
    }
}

void TicTacToeGame::start() {
    bool humanTurn = true;


    cout << tttBoard.to_string() << endl;

    while (!isGameOver()) {
        if (humanTurn) humanPlay();
        else computerPlay();

     
        cout << tttBoard.to_string() << endl;

        humanTurn = !humanTurn;
    }



    cout << tttBoard.to_string() << endl;

    char last = tttBoard.getValue(currRow, currCol);
    if (last == HUMAN_ID) cout << "You win!\n";
    else if (last == COMPUTER_ID) cout << "Computer wins!\n";
    else cout << "Tie game!\n";
}

bool TicTacToeGame::isGameOver() const {

    char last = tttBoard.getValue(currRow, currCol);


    if (last == HUMAN_ID || last == COMPUTER_ID) {
        if (tttBoard.win(currRow, currCol)) {
            if (last == HUMAN_ID) cout << "Human wins. Yay!!!" << endl;
            else cout << "Computer wins. Yuck." << endl;
            return true;
        }
    }

  
    if (tttBoard.tie()) {
        cout << "It is a tie." << endl;
        return true;
    }


    return false;
}

void TicTacToeGame::humanPlay() {
    int r, c;
    while (true) {
        cout << "Enter row and col: ";
        cin >> r >> c;

        bool ok = true;
        if (!tttBoard.isValidRow(r)) {
            cout << "Row is out of range.\n";
            ok = false;
        }
        if (!tttBoard.isValidCol(c)) {
            cout << "Col is out of range.\n";
            ok = false;
        }
        if (ok && !tttBoard.isAvailable(r, c)) {
            cout << "Cell is not available.\n";
            ok = false;
        }

        if (ok) break;
    }

    currRow = r;
    currCol = c;
    tttBoard.mark(r, c, HUMAN_ID);
}

void TicTacToeGame::computerPlay() {
    int n = tttBoard.size();

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (tttBoard.isAvailable(r, c)) {
                tttBoard.mark(r, c, COMPUTER_ID);
                if (tttBoard.win(r, c)) {
                    currRow = r;
                    currCol = c;
                    return;
                }
                tttBoard.mark(r, c, ' ');
            }
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (tttBoard.isAvailable(r, c)) {
                tttBoard.mark(r, c, HUMAN_ID);
                if (tttBoard.win(r, c)) {
                    tttBoard.mark(r, c, COMPUTER_ID);
                    currRow = r;
                    currCol = c;
                    return;
                }
                tttBoard.mark(r, c, ' ');
            }
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (tttBoard.isAvailable(r, c)) {
                tttBoard.mark(r, c, COMPUTER_ID);
                currRow = r;
                currCol = c;
                return;
            }
        }
    }
}
