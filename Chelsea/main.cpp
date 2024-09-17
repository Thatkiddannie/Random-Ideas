#include <iostream>
#include <vector>

using namespace std;

const int boardSize = 3;

char board[boardSize][boardSize] = {{' ', ' ', ' '},
                                  {' ', ' ', ' '},
                                  {' ', ' ', ' '}};

bool isBoardFull() {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool checkWin(char player) {
    // Check rows
    for (int i = 0; i < boardSize; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < boardSize; ++j) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

void printBoard() {
    cout << "-------------" << endl;
    for (int i = 0; i < boardSize; ++i) {
        cout << "| ";
        for (int j = 0; j < boardSize; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

int main() {
    char currentPlayer = 'X';
    bool gameFinished = false;

    while (!gameFinished) {
        printBoard();

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row, col): ";
        cin >> row >> col;

        if (row < 1 || row > boardSize || col < 1 || col > boardSize || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Please try again." << endl;
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;

        if (checkWin(currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameFinished = true;
        } else if (isBoardFull()) {
            cout << "It's a tie!" << endl;
            gameFinished = true;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
