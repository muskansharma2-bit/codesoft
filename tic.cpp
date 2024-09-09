#include <iostream>
#include <vector>

using namespace std;

void drawBoard(const vector<char>& board) {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

bool checkWin(const vector<char>& board, char player) {
    const int winConditions[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

    for (const auto& condition : winConditions) {
        if (board[condition[0]] == player &&
            board[condition[1]] == player &&
            board[condition[2]] == player) {
            return true;
        }
    }
    return false;
}

bool isBoardFull(const vector<char>& board) {
    for (char cell : board) {
        if (cell == ' ') return false;
    }
    return true;
}

int main() {
    vector<char> board(9, ' ');
    char currentPlayer = 'X';
    bool gameWon = false;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (!gameWon && !isBoardFull(board)) {
        drawBoard(board);
        int move;

        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9 || board[move - 1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[move - 1] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            drawBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameWon = true;
        } else if (isBoardFull(board)) {
            drawBoard(board);
            cout << "It's a draw!" << endl;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    cout << "Thanks for playing!" << endl;
    return 0;
}