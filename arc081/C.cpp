
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

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(10)

using namespace std;

int p1[50];
int p2[50][50];
int p3[50][50][50];
int p4[50][50][50][50];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string A;
    cin >> A;

    REP(i, A.size()) {
        int t = A[i] - 'a';
        REP(j, 26) {
            REP(k, 26) {
                REP(l, 26) {
                    if (p3[j][k][l] == 1) {
                        p4[j][k][l][t] = 1;
                    }
                }
                if (p2[j][k] == 1) {
                    p3[j][k][t] = 1;
                }
            }
            if (p1[j] == 1) {
                p2[j][t] = 1;
            }
        }
        p1[t] = 1;
    }


    REP(i, 26) {
        if (p1[i] == 0) {
            char ans = (char) (i + 'a');
            cout << ans << endl;
            return 0;
        }
    }
    REP(i, 26) {
        REP(j, 26) {
            if (p2[i][j] == 0) {
                char ic = (char) (i + 'a');
                char ij = (char) (j + 'a');
                cout << ic << ij << endl;
                return 0;
            }
        }
    }
    REP(i, 26) {
        REP(j, 26) {
            REP(k, 26) {
                if (p3[i][j][k] == 0) {
                    char ic = (char) (i + 'a');
                    char ij = (char) (j + 'a');
                    char ik = (char) (k + 'a');
                    cout << ic << ij << ik << endl;
                    return 0;
                }
            }
        }
    }
    REP(i, 26) {
        REP(j, 26) {
            REP(k, 26) {
                REP(l, 26) {
                    if (p4[i][j][k][l] == 0) {
                        char ic = (char) (i + 'a');
                        char ij = (char) (j + 'a');
                        char ik = (char) (k + 'a');
                        char il = (char) (l + 'a');
                        cout << ic << ij << ik << il << endl;
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}
