#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> P;

class CANDGrid {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int H, W;
        cin >> H >> W;
        vector<vector<char>> A(H, vector<char>(W));
        REP(i, H) {
            REP(j, W) {
                cin >> A[i][j];
            }
        }
        vector<vector<char>> R(H, vector<char>(W, '.'));
        REP(i, H) {
            REP(j, W) {
                if (j == 0) {
                    R[i][j] = '#';
                } else if (i % 2 == 0 && j != W - 1) {
                    R[i][j] = '#';
                } else if (A[i][j] == '#') {
                    R[i][j] = '#';
                }
            }
        }
        vector<vector<char>> B(H, vector<char>(W, '.'));
        REP(i, H) {
            REP(j, W) {
                if (j == W - 1) {
                    B[i][j] = '#';
                } else if (i % 2 == 1 && j != 0) {
                    B[i][j] = '#';
                } else if (A[i][j] == '#') {
                    B[i][j] = '#';
                }
            }
        }

        REP(i, H) {
            REP(j, W) {
                cout << R[i][j];
            }
            cout << endl;
        }
        cout << endl;
        REP(i, H) {
            REP(j, W) {
                cout << B[i][j];
            }
            cout << endl;
        }
    }
};
