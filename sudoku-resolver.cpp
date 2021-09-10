#include <bits/stdc++.h>
using namespace std;


class Sudoku {
    vector<vector<int>> board = {
        { 7, 0, 2, 0, 5, 0, 6, 0, 0 },
        { 0, 0, 0, 0, 0, 3, 0, 0, 0 },
        { 1, 0, 0, 0, 0, 9, 5, 0, 0 },
        { 8, 0, 0, 0, 0, 0, 0, 9, 0 },
        { 0, 4, 3, 0, 0, 0, 7, 5, 0 },
        { 0, 9, 0, 0, 0, 0, 0, 0, 8 },
        { 0, 0, 9, 7, 0, 0, 0, 0, 5 },
        { 0, 0, 0, 2, 0, 0, 0, 0, 0 },
        { 0, 0, 7, 0, 4, 0, 2, 0, 3 }
    };

    const int len = 9;

    bool exist_number_same_row(int number, int row) {
        for(int i = 0; i < len; ++i) {
            if(board[row][i] == number) {
                return true;
            }
        }

        return false;
    }

    bool exist_number_same_col(int number, int col) {
        for(int i = 0; i < len; ++i) {
            if(board[i][col] == number) {
                return true;
            }
        }

        return false;
    }

    bool exist_number_same_box(int number, int row, int col) {
        int row_begin = row - row % 3;
        int col_begin = col - col % 3;

        for(int i = row_begin; i < row_begin + 3; ++i) {
            for(int j = col_begin; j < col_begin + 3; ++j) {
                if(board[i][j] == number) {
                    return true;
                }
            }
        }

        return false;
    }

    bool is_valid_number(int number, int row, int col) {
        return not exist_number_same_row(number, row) and
            not exist_number_same_col(number, col) and 
            not exist_number_same_box(number, row, col);
    }

    bool resolve() {
        for(int i = 0; i < len; ++i) {
            for(int j = 0; j < len; ++j) {
                if(board[i][j] == 0) {
                    for(int number = 1; number <= len; ++number) {
                        if(is_valid_number(number, i, j)) {
                            board[i][j] = number;

                            if(resolve()) {
                                return true;
                            } else {
                                board[i][j] = 0;
                            }
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

public:

    void display() {
        cout << endl;
        for(int k = 0; k < len; ++k) {
            if(k == 0) {
                cout << "+";
            }
            if((k + 1) % 3 == 0) {
                cout << "-+";
            } else {
                cout << "---";

            }
        }
        cout << endl;
        for(int i = 0; i < len; ++i) {
            cout << "|";
            for(int j = 0; j < len; ++j) {
                if(board[i][j] == 0) {
                    cout << " ";
                } else {
                    cout << board[i][j];
                }
                if((j + 1) % 3 == 0) {
                    cout << "|";
                } else {
                    cout << ", ";
                }
            }
            cout << endl;
            if((i + 1) % 3 == 0) {
                for(int k = 0; k < len; ++k) {
                    if(k == 0) {
                        cout << "+";
                    }
                    if((k + 1) % 3 == 0) {
                        cout << "-+";
                    } else {
                        cout << "---";

                    }
                }
                cout << endl;
            }
        }
    }

    Sudoku() {}

    Sudoku(vector<string> arr) {
        if(arr.size() != 9 || arr[0].size() != 9) {
            cout << "Array must be of 81 numbers.\n";
            exit(1);
        }

        int id = 0;
        for(int i = 0; i < len; ++i) {
            for(int j = 0; j < len; ++j) {
                board[i][j] = arr[i][j] - '0';
            }
        }
    }

    void solve() {
        cout << (resolve() ? "Solved successfully!" : "Unsolvable board :(") << endl;
    }
};

int main() {

    vector<vector<string>> arr(50, vector<string>(9));

    for(int k = 0; k < 50; ++k) {
        string name;
        cin >> name >> name;
        cout << "\nSolving board " + name << endl;
        for(int i = 0; i < 9; ++i) {
            cin >> arr[k][i];
        }

        Sudoku sudoku(arr[k]);
        sudoku.solve();
        sudoku.display();
    }

    return 0;
}