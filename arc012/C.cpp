#include <bits/stdc++.h>

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

class C {
public:

    vector<vector<char>> b;
    map<char, bool> isWin;
    map<char, int> num;
    int di[4] = {1, 0, 1, 1};
    int dj[4] = {0, 1, 1, -1};

    bool check() {
        REP(i, 19) {
            REP(j, 19) {
                if (b[i][j] == '.') continue;
                char c = b[i][j];
                num[c]++;
                REP(k, 4) {
                    int cur = 0;
                    int ni = i;
                    int nj = j;
                    while (ni >= 0 && nj >= 0 && ni < 19 && nj < 19) {
                        if (b[ni][nj] != c) break;
                        cur++;
                        ni += di[k];
                        nj += dj[k];
                    }

                    if (cur >= 5) {
                        isWin[c] = true;
                    }
                }
            }
        }

        if (abs(num['o'] - num['x']) > 1) {
            return false;
        }

        return true;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        b = vector<vector<char >>(19, vector<char>(19));
        REP(i, 19) REP(j, 19) cin >> b[i][j];

        if (!check()) {
            cout << "NO" << endl;
            return;
        }

        if (isWin['o'] && isWin['x']) {
            cout << "NO" << endl;
            return;
        }
        if (!isWin['o'] && !isWin['x']) {
            cout << "YES" << endl;
            return;
        }
        if (isWin['o'] && num['o'] == num['x']) {
            cout << "NO" << endl;
            return;
        }
        if (isWin['x'] && num['o'] > num['x']) {
            cout << "NO" << endl;
            return;
        }

        char t = isWin['o'] ? 'o' : 'x';
        REP(i, 19) {
            REP(j, 19) {
                if (b[i][j] != t)continue;
                b[i][j] = '.';
                isWin['o'] = false;
                isWin['x'] = false;

                check();
                if (!isWin[t]) {
                    cout << "YES" << endl;
                    return;
                }

                b[i][j] = t;
            }
        }
        cout << "NO" << endl;
    }

};
