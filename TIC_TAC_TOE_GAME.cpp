#include <iostream>
using namespace std;

// Function prototypes
void initializeBoard(char board[3][3]);
void displayBoard(char board[3][3]);
bool makeMove(char board[3][3], char player, int row, int col);
bool checkWin(char board[3][3], char player);
bool checkDraw(char board[3][3]);
bool isValidMove(char board[3][3], int row, int col);

int main() {
    char board[3][3];
    char currentPlayer = 'X';
    bool gameWon = false;
    bool draw = false;

    initializeBoard(board);

    do {
        // Display the current state of the board
        displayBoard(board);

        // Player input
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid
        if (isValidMove(board, row, col)) {
            // Make the move and check for a win
            gameWon = makeMove(board, currentPlayer, row, col);
            if (gameWon) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
            } else {
                // Check for a draw
                draw = checkDraw(board);
                if (draw) {
                    displayBoard(board);
                    cout << "It's a draw!" << endl;
                } else {
                    // Switch players for the next turn
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            }
        } else {
            cout << "Invalid move! Try again." << endl;
        }

    } while (!gameWon && !draw);

    // Ask if players want to play again
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        main(); // Restart the game
    } else {
        cout << "Thanks for playing!" << endl;
    }

    return 0;
}

void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = '-';
        }
    }
}

void displayBoard(char board[3][3]) {
    cout << "Current Board:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool makeMove(char board[3][3], char player, int row, int col) {
    board[row][col] = player;
    return checkWin(board, player);
}

bool checkWin(char board[3][3], char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool checkDraw(char board[3][3]) {
    // Check if the board is full (no empty spaces)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == '-') {
                return false; // There is an empty space, game is not a draw
            }
        }
    }
    return true; // All spaces are filled, game is a draw
}

bool isValidMove(char board[3][3], int row, int col) {
    // Check if the move is within the bounds of the board and the selected cell is empty
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == '-');
}
