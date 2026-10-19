
#include <iostream>
using namespace std;

char board[3][3];

void initializeBoard() {
    char num = '1';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << "\n";
        if (i < 2)
            cout << "---+---+---\n";
    }
    cout << "\n";
}

bool checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;

        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' &&
                board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

int main() {
    char playAgain;

    do {
        initializeBoard();
        char player = 'X';
        int move;
        bool gameOver = false;

        cout << "\nTIC-TAC-TOE GAME\n";
        cout << "Player 1: X\n";
        cout << "Player 2: O\n";

        while (!gameOver) {
            displayBoard();

            cout << "Player " << player
                 << ", enter your move (1-9): ";
            cin >> move;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input! Enter a number from 1 to 9.\n";
                continue;
            }

            if (move < 1 || move > 9) {
                cout << "Invalid move! Choose a number from 1 to 9.\n";
                continue;
            }

            int row = (move - 1) / 3;
            int col = (move - 1) % 3;

            if (board[row][col] == 'X' ||
                board[row][col] == 'O') {
                cout << "That position is already occupied!\n";
                continue;
            }

            board[row][col] = player;

            if (checkWin(player)) {
                displayBoard();
                cout << "Player " << player << " wins!\n";
                gameOver = true;
            }
            else if (checkDraw()) {
                displayBoard();
                cout << "The game is a draw!\n";
                gameOver = true;
            }
            else {
                player = (player == 'X') ? 'O' : 'X';
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";

    return 0;
}
