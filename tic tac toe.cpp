#include <iostream>

using namespace std;

// Function to initialize the game board
void initializeBoard(int board[3][3]) {
    // Initialize the board with 0 (empty spots)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = 0;  // 0 represents an empty spot
        }
    }
}

// Function to display the game board
void displayBoard(int board[3][3]) {
    cout << "-------------\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 0) {
                cout << "|   ";  // Empty spot
            } else if (board[i][j] == 1) {
                cout << "| X ";  // Player X
            } else {
                cout << "| O ";  // Player O
            }
        }
        cout << "|\n";
        cout << "-------------\n";
    }
}

// Function to check if the current player has won
bool checkWin(int board[3][3], int player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||  // Check row
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) { // Check column
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||  // Check diagonal
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(int board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 0) {
                return false;  // There's still an empty space, so it's not a draw
            }
        }
    }
    return true;  // No empty spaces left
}

// Function to handle player input
bool playerMove(int board[3][3], int row, int col, int player) {
    if (board[row][col] == 0) {  // Check if the spot is empty
        board[row][col] = player;  // Place the player's move
        return true;
    }
    return false;
}

int main() {
    int board[3][3];  // Declare the board as a 2D array
    int currentPlayer = 1;  // Player 1 starts (1 represents player 'X', 2 represents player 'O')
    bool gameOngoing = true;

    while (true) {
        initializeBoard(board);  // Initialize the board at the start of each game
        gameOngoing = true;

        while (gameOngoing) {
            displayBoard(board);  // Display the current board
            int row, col;

            // Validate the player's input
            bool validMove = false;
            while (!validMove) {
                cout << "Player " << (currentPlayer == 1 ? "X" : "O") 
                     << ", enter your move (row and column from 1 to 3): ";
                cin >> row >> col;

                row--; col--;  // Convert to 0-based index

                if (row >= 0 && row < 3 && col >= 0 && col < 3 && playerMove(board, row, col, currentPlayer)) {
                    validMove = true;  // Valid move, break the loop
                } else {
                    cout << "Invalid move! The cell is either out of range or already taken. Please try again.\n";
                }
            }

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << (currentPlayer == 1 ? "X" : "O") << " wins!\n";
                gameOngoing = false;
            } else if (checkDraw(board)) {
                displayBoard(board);
                cout << "It's a draw!\n";
                gameOngoing = false;
            } else {
                currentPlayer = (currentPlayer == 1) ? 2 : 1;  // Switch players (1 -> 2 or 2 -> 1)
            }
        }

        // Ask players if they want to play again
        char playAgain;
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
        if (playAgain == 'N' || playAgain == 'n') {
            break;
        }
    }

    return 0;
}

