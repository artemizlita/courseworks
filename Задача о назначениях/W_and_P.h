#ifndef W_AND_P_H
#define W_AND_P_H

#include <vector>
#include <algorithm>

using namespace std;

class W_and_P {
public:
    int n = 2;
    int down_mark, up_mark;
    vector<vector<int> > matrix;
    vector<vector<int> > elementary, inv_elementary;
    vector<int> places;

    void find_change() {
        up_mark = 0;
        for (int i = 0; i < n; ++i) {
            if (matrix[i][i] > up_mark) {
                up_mark = matrix[i][i];
            }
            places.push_back(i);
        }
        down_mark = 0;
        for (int i = 0; i < n; ++i) {
            int min = 1000;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] < min) {
                    min = matrix[i][j];
                }
            }
            if (min > down_mark) {
                down_mark = min;
            }
        }
        while (down_mark != up_mark) {
            places.clear();
            int max = find_elementary();
            if (max == -1) {
                down_mark = (up_mark + down_mark + 1) / 2;
                if (down_mark == up_mark) {
                    find_elementary();
                }
            } else {
                up_mark = max;
            }
        }
    }

    int find_elementary() {
        elementary.resize(n);
        inv_elementary.resize(n);
        for (int i = 0; i < n; ++i) {
            elementary[i].resize(n);
            inv_elementary[i].resize(n);
            for (int j = 0; j < n; ++j) {
                elementary[i][j] = matrix[i][j] <= (up_mark + down_mark) / 2;
                inv_elementary[i][j] = 0;
            }
        }
        vector<int> was(2 * n);
        vector<int> exit(n);
        for (int i = 0; i < 2 * n; ++i) {
            was[i] = 0;
            exit[i / 2] = 0;
        }
        for (int k = 0; k < n; ++k) {
            if (find_way (k, was, exit) == 0) {
                return -1;
            }
        }
        int max = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (inv_elementary[i][j] == 1) {
                    places.push_back(j);
                    if (matrix[j][i] > max) {
                        max = matrix[j][i];
                    }
                }
            }
        }
        return max;
    }

    bool find_way (int k, vector<int> was, vector<int>& exit) {
        was[k] = 1;
        for (int i = 0; i < n; ++i) {
            if (elementary[k][i] == 1 && was[n + i] != 1) {
                if (find_inv_way (i, was, exit)) {
                    elementary[k][i] = 0;
                    inv_elementary[i][k] = 1;
                    return 1;
                }
            }
        }
        return 0;
    }

    bool find_inv_way (int k, vector<int> was, vector<int>& exit) {
        was[n + k] = 1;
        if (exit[k] == 0) {
            exit[k] = 1;
            return 1;
        }
        for (int i = 0; i < n; ++i) {
            if (inv_elementary[k][i] == 1 && was[i] != 1) {
                if (find_way (i, was, exit)) {
                    inv_elementary[k][i] = 0;
                    elementary[i][k] = 1;
                    return 1;
                }
            }
        }
        return 0;
    }
};

#endif // W_AND_P_H
