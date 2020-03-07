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

typedef pair<int, int> P;

class BBingo {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        vector<vector<int>> A(3, vector<int>(3));
        REP(i, 3) REP(j, 3) cin >> A[i][j];

        int N;
        cin >> N;
        set<int> found;
        REP(i, N) {
            int b;
            cin >> b;
            found.insert(b);
        }
        REP(i, 3) {
            bool ok = true;
            REP(j, 3) {
                if (found.count(A[i][j]) == 0)  {
                    ok = false;
                }
            }
            if (ok) {
                cout << "Yes" << endl;
                return;
            }
        }
        REP(j, 3) {
            bool ok = true;
            REP(i, 3) {
                if (found.count(A[i][j]) == 0)  {
                    ok = false;
                }
            }
            if (ok) {
                cout << "Yes" << endl;
                return;
            }
        }
        int j = 0;
        bool ok = true;
        REP(i, 3) {
            if (found.count(A[i][j]) == 0) {
                ok = false;
            }
            j++;
        }
        if (ok) {
            cout << "Yes" << endl;
            return;
        }
        j = 2;
        ok = true;
        REP(i, 3) {
            if (found.count(A[i][j]) == 0) {
                ok = false;
            }
            j--;
        }
        if (ok) {
            cout << "Yes" << endl;
            return;
        }
        cout << "No" << endl;

    }
};
