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

class FSimplifiedReversi {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, Q;
        cin >> N >> Q;
        set<pair<int, int>> col, row;
        col.insert({N, N});
        row.insert({N, N});
        int num = 0;
        REP(i, Q) {
            int type, x;
            cin >> type >> x;
            if (type == 1) {
                auto itr = col.upper_bound({x, N});
                int to = itr->second;
                num += to - 2;
                row.insert({to, x});
            } else {
                auto itr = row.upper_bound({x, N});
                int to = itr->second;
                num += to - 2;
                col.insert({to, x});
            }
        }
        cout << (N-2) * (N-2) - num << endl;
    }
};
