#include <iostream>
#include<locale.h>

using namespace std;

const int boardSize = 8;

bool isSafe(int board[boardSize][boardSize], int row, int col) {
    for (int i = 0; i < boardSize; i++) {
        if (board[row][i] || board[i][col] ||
            (row - i >= 0 && col - i >= 0 && board[row - i][col - i]) ||
            (row + i < boardSize && col + i < boardSize && board[row + i][col + i]) ||
            (row - i >= 0 && col + i < boardSize && board[row - i][col + i]) ||
            (row + i < boardSize && col - i >= 0 && board[row + i][col - i])) {
            return false; // если атакует другого ферзя
        }
    }
    return true;
}

bool solve(int board[boardSize][boardSize], int row) {
    if (row == boardSize) return true;

    for (int col = 0; col < boardSize; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1; // ставим ферзя на доску

            if (solve(board, row + 1)) {
                return true;
            }

            board[row][col] = 0; // возвращаем пусто
        }
    }

    return false;
}

void printBoard(int board[boardSize][boardSize]) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (board[i][j] == 1) {
                cout << "Q ";
            }
            else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int board[boardSize][boardSize] = { 0 };

    if (solve(board, 0)) {
        cout << "Ферзи были успешно расставлены на доске:" << endl;
        printBoard(board);
    }

    return 0;
}
