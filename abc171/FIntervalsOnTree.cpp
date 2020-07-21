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

class FIntervalsOnTree {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<pair<int, int>> e(N-1);
        REP(i, N - 1) {
            int u, v;
            cin >> u >> v;
            if (u > v) swap(u, v);
            e[i] = {u, v};
        }

        int num = 0;
        FOR(i, 1, N) {
            num += i * (N - i + 1);
        }

        int sub = 0;
        REP(i, e.size()) {
            sub += e[i].first * (N - e[i].second + 1);
        }
        cout << num - sub << endl;
    }
};
