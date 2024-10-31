//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//const int N = 6;
//int movesX[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
//int movesY[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
//
//bool isSafe(int x, int y, const vector<vector<int>>& board) {
//    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
//}
//
//bool knightTour(int x, int y, int moveCount, vector<vector<int>>& board) {
//    if (moveCount == N * N) {
//        return true;
//    }
//
//    for (int i = 0; i < 8; i++) {
//        int nextX = x + movesX[i];
//        int nextY = y + movesY[i];
//        if (isSafe(nextX, nextY, board)) {
//            board[nextX][nextY] = moveCount;
//            if (knightTour(nextX, nextY, moveCount + 1, board)) {
//                return true;
//            }
//            board[nextX][nextY] = -1;
//        }
//    }
//    return false;
//}
//
//void printBoard(const vector<vector<int>>& board) {
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            cout << board[i][j] << "\t";
//        }
//        cout << endl;
//    }
//}
//
//int main() {
//    vector<vector<int>> board(N, vector<int>(N, -1));
//    int startX, startY;
//
//    cout << "Введіть координати стартового положення коня (x, y) (0-" << N - 1 << "): ";
//    cin >> startX >> startY;
//
//    if (startX < 0 || startX >= N || startY < 0 || startY >= N) {
//        cout << "Некоректні координати!" << endl;
//        return 1;
//    }
//
//    board[startX][startY] = 0;
//
//    if (knightTour(startX, startY, 1, board)) {
//        cout << "Знайдений шлях коня:" << endl;
//        printBoard(board);
//    }
//    else {
//        cout << "Шлях не знайдено!" << endl;
//    }
//
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstdlib>
//#include <ctime>
//#include <iomanip> 
//
//using namespace std;
//
//const int N = 4;
//
//void printBoard(const vector<vector<int>>& board) {
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            if (board[i][j] == 0)
//                cout << "   ";
//            else
//                cout << setw(3) << board[i][j];
//        }
//        cout << endl;
//    }
//}
//
//bool isSolved(const vector<vector<int>>& board) {
//    int count = 1;
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            if (i == N - 1 && j == N - 1) {
//                return board[i][j] == 0;
//            }
//            if (board[i][j] != count++)
//                return false;
//        }
//    }
//    return true;
//}
//
//bool moveTile(vector<vector<int>>& board, int row, int col) {
//    int zeroRow, zeroCol;
//
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            if (board[i][j] == 0) {
//                zeroRow = i;
//                zeroCol = j;
//            }
//        }
//    }
//
//    if ((abs(zeroRow - row) == 1 && zeroCol == col) || (abs(zeroCol - col) == 1 && zeroRow == row)) {
//        swap(board[zeroRow][zeroCol], board[row][col]);
//        return true;
//    }
//    return false;
//}
//
//void generateBoard(vector<vector<int>>& board) {
//    vector<int> tiles;
//    for (int i = 0; i < N * N; i++) {
//        tiles.push_back(i);
//    }
//    random_shuffle(tiles.begin(), tiles.end());
//
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            board[i][j] = tiles[i * N + j];
//        }
//    }
//}
//
//int main() {
//    srand(static_cast<unsigned int>(time(0)));
//
//    vector<vector<int>> board(N, vector<int>(N));
//    generateBoard(board);
//
//    while (!isSolved(board)) {
//        printBoard(board);
//        cout << "Ви керуєте пустою клітинкою\n";
//        cout << " 0 1 2 3 \n";
//        cout << "0 * * * *\n";
//        cout << "1 * * * *\n";
//        cout << "2 * * * *\n";
//        cout << "3 * * * *\n";
//        cout << "Для ходу використовуйте (рядок, стовпець): ";
//        int row, col;
//        cin >> row >> col;
//
//        if (row < 0 || row >= N || col < 0 || col >= N) {
//            cout << "Некоректні координати! Спробуйте ще раз" << endl;
//            continue;
//        }
//
//        if (!moveTile(board, row, col)) {
//            cout << "Неможливо перемістити плитку" << endl;
//        }
//    }
//
//    cout << "Вітаємо! Ви виграли" << endl;
//    printBoard(board);
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//const int SIZE = 3;
//
//void printBoard(const vector<vector<char>>& board) {
//    for (int i = 0; i < SIZE; i++) {
//        for (int j = 0; j < SIZE; j++) {
//            cout << board[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
//
//bool checkWin(const vector<vector<char>>& board, char player) {
//    for (int i = 0; i < SIZE; i++) {
//        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
//            return true;
//    }
//
//    for (int j = 0; j < SIZE; j++) {
//        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
//            return true;
//    }
//
//    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
//        return true;
//    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
//        return true;
//
//    return false;
//}
//
//bool isDraw(const vector<vector<char>>& board) {
//    for (int i = 0; i < SIZE; i++) {
//        for (int j = 0; j < SIZE; j++) {
//            if (board[i][j] == ' ') {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//int main() {
//    vector<vector<char>> board(SIZE, vector<char>(SIZE, ' '));
//    char currentPlayer = 'X';
//
//    while (true) {
//        printBoard(board);
//        cout << "Гравець " << currentPlayer << ", введіть рядок і стовпець (0-2): ";
//        int row, col;
//        cin >> row >> col;
//
//        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
//            cout << "Некоректний хід. Спробуйте ще раз." << endl;
//            continue;
//        }
//
//        board[row][col] = currentPlayer;
//
//        if (checkWin(board, currentPlayer)) {
//            printBoard(board);
//            cout << "Гравець " << currentPlayer << " виграв" << endl;
//            break;
//        }
//
//        if (isDraw(board)) {
//            printBoard(board);
//            cout << "Гра закінчилася внічию" << endl;
//            break;
//        }
//
//        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
//    }
//
//    return 0;
//}