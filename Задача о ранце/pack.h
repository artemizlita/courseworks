#ifndef PACK_H
#define PACK_H
#include <vector>

using namespace std;

class pack {
public:
    int BacV = 1;
    vector<int> v, c;
    vector<pair<int,int> > steps;
    vector<int> cstep;
    int Recurtion(int k, int p) {
        int tek;
        if (k == 0) {
            if (v[0] > p) {
                tek = 0;
            } else {
                tek = c[0];
            }
        } else {
            if (p >= v[k]) {
                tek = max(Recurtion(k - 1, p), c[k] + Recurtion(k - 1, p - v[k]));
            } else {
                tek = Recurtion(k - 1, p);
            }
        }
        if (p > 0) {
            steps.push_back(make_pair<int, int>(k, p + 1));
            cstep.push_back(tek);
        }
        return tek;
    }
};

#endif // PACK_H
