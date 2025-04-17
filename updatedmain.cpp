#include <bits/stdc++.h>
using namespace std;

struct Move {
    int row, col;// coordinates
};

char player = 'x', opponent = 'o';

bool isMovesLeft(char board[3][3]) {
    // checking if there's an empty space if yes then return true
    // i.e. checking if moves are possible
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == '_')
                return true;
    return false;
}

int evaluate(char b[3][3]) {
// check if someone has won the game
    // check row wise
    for (int row = 0; row < 3; row++) {
        if (b[row][0] == b[row][1] && b[row][1] == b[row][2]) {
            if (b[row][0] == player)
                return +10;
            else if (b[row][0] == opponent)
                return -10;
        }
    }
    // check column wise
    for (int col = 0; col < 3; col++) {
        if (b[0][col] == b[1][col] && b[1][col] == b[2][col]) {
            if (b[0][col] == player)
                return +10;
            else if (b[0][col] == opponent)
                return -10;
        }
    }
    // check diagonal wise
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2]) {
        if (b[0][0] == player)
            return +10;
        else if (b[0][0] == opponent)
            return -10;
    }

    if (b[0][2] == b[1][1] && b[1][1] == b[2][0]) {
        if (b[0][2] == player)
            return +10;
        else if (b[0][2] == opponent)
            return -10;
    }
    return 0;
}
// ai algo that checks all opponenet and bot moves by calculating all possibilities through recursion and find the best move for bot
// depth- for faster stimulation
int minimax(char board[3][3], int depth, bool isMax) {
    int score = evaluate(board);
    if (score == 10 || score == -10)
        return score - depth;

    if (!isMovesLeft(board))
        return 0 - depth;

    if (isMax) {
        //simulating all moves for bot for max score
        int best = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = player;
                    best = max(best, minimax(board, depth + 1, !isMax));
                    board[i][j] = '_';
                }
            }
        }
        return best;
    } else {
        // for person and trying to make the score minimum as possible
        int best = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = opponent;
                    best = min(best, minimax(board, depth + 1, !isMax));
                    board[i][j] = '_';
                }
            }
        } 
        return best;
    }
}

Move makeMove(char board[3][3]) {
    // move through all empty set and find the best move for bot 
    int bestVal = -1000;
    Move bestMove = {0, 0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '_') {
                board[i][j] = player;
                int moveVal = minimax(board, 0, false);
                board[i][j] = '_';
                if (moveVal > bestVal) {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

void printboard(char board[3][3]) {
    // clears the screen and prints x , o for opp and bot respectively
    // color grid 
    cout << "\033[2J\033[H"; // Clear screen and move cursor to top left
    cout << "\033[36m";
    cout << "+---+---+---+\n";
    for (int i = 0; i < 3; i++) {
        cout << "|";
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'x')
                cout << " \033[34mx\033[36m |";  // Blue x
            else if (board[i][j] == 'o')
                cout << " \033[31mo\033[36m |";  // Red o
            else
                cout << " \033[90m_\033[36m |";  // Gray _
        }
        cout << "\n+---+---+---+\n";
    }
    cout << "\033[0m\n";
}

bool checkGameOver(char board[3][3]) {
    // uses evaluate to check if someone has won the game or not
    int result = evaluate(board);
    if (result == 10) {
        cout << "\033[33mBot wins\033[0m\n";
        return true;
    }
    if (result == -10) {
        cout << "\033[32mYou win\033[0m\n";
        return true;
    }
    if (!isMovesLeft(board)) {
        cout << "\033[35mTie\033[0m\n";
        return true;
    }
    return false;
}

int main() {
    // board initialization 
    char board[3][3] = {
        { '_', '_', '_' },
        { '_', '_', '_' },
        { '_', '_', '_' }
    };

    cout << "\033[36mPlayer: o\nComputer: x\n-----------Beat the bot-----------\033[0m\n";
    srand(time(NULL));
    printboard(board);
   // rand for human or bot initializing the game
    if (rand() & 1) {
        cout << "You start first\n";
        while (!checkGameOver(board)) {
            int x, y;
            cout << "Make your move (row col): ";
            cin >> x >> y;
            while (x < 1 || x > 3 || y < 1 || y > 3 || board[x - 1][y - 1] != '_') {
                cout << "Invalid move. Re-enter: ";
                cin >> x >> y;
            }
            board[x - 1][y - 1] = opponent;
            printboard(board);
            if (checkGameOver(board)) break;

            Move bestMove = makeMove(board);
            board[bestMove.row][bestMove.col] = player;
            printboard(board);
        }
    } else {
        cout << "Bot starts first\n";
        Move bestMove = makeMove(board);
        board[bestMove.row][bestMove.col] = player;
        printboard(board);
        while (!checkGameOver(board)) {
            int x, y;
            cout << "Make your move (row col): ";
            cin >> x >> y;
            while (x < 1 || x > 3 || y < 1 || y > 3 || board[x - 1][y - 1] != '_') {
                cout << "Invalid move. Re-enter: ";
                cin >> x >> y;
            }
            board[x - 1][y - 1] = opponent;
            printboard(board);
            if (checkGameOver(board)) break;

            bestMove = makeMove(board);
            board[bestMove.row][bestMove.col] = player;
            printboard(board);
        }
    }
    return 0;
}
