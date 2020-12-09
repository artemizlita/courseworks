#ifndef ROAD_MATRIX_H
#define ROAD_MATRIX_H
#include <vector>
#include <algorithm>

using namespace std;

class road_matrix {
public:
    int n = 2;
    vector<vector<int> > matrix, marks;
    vector<pair<int, int> > parts;

    void find_way() {
        for (int k = 0; k < n; ++ k) {
            marks.resize(n);
            for (int i = 0; i < n; ++i) {
                marks[i].resize(n);
                for (int j = 0; j < n; ++j) {
                    marks[i][j] = -1;
                }
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    int ilok = i, jlok = j;
                    if (parts.size() < n - 1) {
                        for (int problem = 0; problem < 2; ++problem) {
                            for (int l = 0; l < parts.size(); ++l) {
                                if (parts[l].first == jlok) {
                                    jlok = parts[l].second;
                                }
                                if (ilok == jlok) {
                                    matrix[i][j] = 32000;
                                }
                                if (parts[l].second == ilok) {
                                    ilok = parts[l].first;
                                }
                                if (ilok == jlok) {
                                    matrix[i][j] = 32000;
                                }
                            }
                        }
                    }
                }
            }
            reduction ();
            marking ();
            find_part ();
        }
    }

    void reduction () {
        for (int i = 0; i < n; ++i) {
            int min = 1000;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] < min) {
                    min = matrix[i][j];
                }
            }
            for (int j = 0; j < n; ++j) {
                matrix[i][j] -= min;
            }
        }
        for (int j = 0; j < n; ++j) {
            int min = 1000;
            for (int i = 0; i < n; ++i) {
                if (matrix[i][j] < min) {
                    min = matrix[i][j];
                }
            }
            for (int i = 0; i < n; ++i) {
                matrix[i][j] -= min;
            }
        }
    }

    void marking () {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    int minR = 16000, minC = 16000;
                    for (int c = 0; c < n; ++c) {
                        if (matrix[i][c] < minR && c != j) {
                            minR = matrix[i][c];
                        }
                        if (matrix[c][j] < minC && c != i) {
                            minC = matrix[c][j];
                        }
                    }
                    marks[i][j] = minR + minC;
                }
            }
        }
    }

    void find_part() {
        int max_mark = -1, imax = 0, jmax = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (marks[i][j] > max_mark && matrix[i][j] < 1000) {
                    max_mark = marks[i][j];
                    imax = i;
                    jmax = j;
                }
            }
        }
        matrix[jmax][imax] = 32000;
        for (int i = 0; i < n; ++i) {
            matrix[i][jmax] = 32000;
            matrix[imax][i] = 32000;
        }
        parts.push_back(make_pair(imax, jmax));
    }
};

#endif // ROAD_MATRIX_H
