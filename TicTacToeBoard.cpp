#include "TicTacToeBoard.hpp"

TicTacToeBoard::TicTacToeBoard() : board(3, std::vector<char>(3, ' ')) {}

TicTacToeBoard::TicTacToeBoard(int givenSize) {
    int s = (givenSize < 3 ? 3 : givenSize);
    board.assign(s, std::vector<char>(s, ' '));
}

void TicTacToeBoard::clear() {
    for (auto &row : board)
        std::fill(row.begin(), row.end(), ' ');
}

char TicTacToeBoard::getValue(int row, int col) const {
    return board[row][col];
}

bool TicTacToeBoard::isAvailable(int row, int col) const {
    return board[row][col] == ' ';
}

bool TicTacToeBoard::isValidRow(int row) const {
    return row >= 0 && row < (int)board.size();
}

bool TicTacToeBoard::isValidCol(int col) const {
    return col >= 0 && col < (int)board.size();
}

int TicTacToeBoard::size() const {
    return board.size();
}

void TicTacToeBoard::mark(int row, int col, char symbol) {
    board[row][col] = symbol;
}

std::string TicTacToeBoard::to_string() const {
  std::string str;
    int n = board.size();

    str += "     ";
    for (int col = 0; col < n; col++) {
        str += std::to_string(col) + "   ";
    }
    str += "\n";

    str += "   +";
    for (int col = 0; col < n; col++) {
        str += "---+";
    }
    str += "\n";

    for (int row = 0; row < n; row++) {

        str += " " + std::to_string(row) + " |";

        for (int col = 0; col < n; col++) {
            str += " " + std::string(1, board[row][col]) + " |";
        }
        str += "\n";

        str += "   +";
        for (int col = 0; col < n; col++) {
            str += "---+";
        }
        str += "\n";
    }


   return str; //TODO: placeholder
}

bool TicTacToeBoard::tie() const {
    int n = size();

    auto lineHasBoth = [&](auto getter) {
        bool hasX = false, hasO = false;
        for (int i = 0; i < n; i++) {
            char v = getter(i);
            if (v == 'X') hasX = true;
            if (v == 'O') hasO = true;
        }
        return hasX && hasO;
    };

    for (int r = 0; r < n; r++)
        if (!lineHasBoth([&](int c){ return board[r][c]; })) return false;

    for (int c = 0; c < n; c++)
        if (!lineHasBoth([&](int r){ return board[r][c]; })) return false;

    if (!lineHasBoth([&](int i){ return board[i][i]; })) return false;
    if (!lineHasBoth([&](int i){ return board[i][n-1-i]; })) return false;

    return true;
}

bool TicTacToeBoard::win(int row, int col) const {
    return winByRow(row, col) || winByCol(row, col) || winByDiagonal(row, col);
}

bool TicTacToeBoard::winByRow(int row, int col) const {
    char s = board[row][col];
    int n = size();
    for (int c = 0; c < n; c++)
        if (board[row][c] != s) return false;
    return true;
}

bool TicTacToeBoard::winByCol(int row, int col) const {
    char s = board[row][col];
    int n = size();
    for (int r = 0; r < n; r++)
        if (board[r][col] != s) return false;
    return true;
}

bool TicTacToeBoard::winByDiagonal(int row, int col) const {
    char s = board[row][col];
    int n = size();

    bool onMain = (row == col);
    bool onAnti = (row + col == n - 1);

    if (!onMain && !onAnti) return false;

    if (onMain) {
        bool ok = true;
        for (int i = 0; i < n; i++)
            if (board[i][i] != s) ok = false;
        if (ok) return true;
    }

    if (onAnti) {
        bool ok = true;
        for (int i = 0; i < n; i++)
            if (board[i][n - 1 - i] != s) ok = false;
        if (ok) return true;
    }

    return false;
}
