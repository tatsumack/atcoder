#include <bits/stdc++.h>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

class BPlusMatrix {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<vector<int>> C(N, vector<int>(N));
        REP(i, N) {
            REP(j, N) {
                cin >> C[i][j];
            }
        }
        vector<int> check(N);
        REP(i, N) {
            check[i] = C[0][0] - C[0][i];
        }
        bool ok = true;
        int val = INF;
        int row = -1;
        int col = -1;
        REP(i, N) {
            REP(j, N) {
                if (C[i][0] - C[i][j] != check[j]) {
                    ok = false;
                }
                if (C[i][j] < val) {
                    val = C[i][j];
                    row = i;
                    col = j;
                }
            }
        }
        if (!ok) {
            cout << "No" << endl;
            return;
        }

        cout << "Yes" << endl;
        REP(i, N) {
            if (i > 0) cout << " ";
            cout << C[i][0] - C[row][0];
        }
        cout << endl;
        REP(i, N) {
            if (i > 0) cout << " ";
            cout << C[row][i];
        }
        cout << endl;
    }
};
