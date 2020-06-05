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

class CFolia {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> A(N + 1);
        REP(i, N + 1) cin >> A[i];

        if (A[0] > 1) {
            cout << -1 << endl;
            return;
        }
        if (A[0] == 1) {
            if (N == 0) {
                cout << 1 << endl;
            } else {
                cout << -1 << endl;
            }
            return;
        }

        vector<int> par(N + 1);
        par[0] = 1;
        for (int i = 1; i <= N; i++) {
            par[i] = par[i - 1] * 2 - A[i];
            if (par[i] < 0) {
                cout << -1 << endl;
                return;
            }
            if (par[i] > INF) {
                par[i] = INF;
            }
        }

        vector<int> num(N + 1);
        num[N] = A[N];
        for (int i = N - 1; i >= 0; i--) {
            num[i] = min(num[i + 1], par[i]) + A[i];
        }
        int res = 0;
        for (int i = 0; i <= N; i++) res += num[i];
        cout << res << endl;
    }
};
