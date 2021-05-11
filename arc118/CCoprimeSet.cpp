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

class CCoprimeSet {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> res;
        for (int i = 1; i <= 10000 && res.size() < N; i++) {
            if (i % 6 == 0 && i != 12) {
                res.push_back(i);
                continue;
            }
            if (i % 10 == 0) {
                res.push_back(i);
                continue;
            }
            if (i % 15 == 0) {
                res.push_back(i);
                continue;
            }
        }
        REP(i, N) cout << res[i] << " ";
    }
};
