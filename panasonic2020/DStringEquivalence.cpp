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

class DStringEquivalence {
public:
    int N;
    void dfs(vector<string>& res, string cur, int m, int d) {
        if (d == N) {
            res.push_back(cur);
            return;
        }

        FOR(i, 0, m + 1) {
            char c = i + 'a';
            dfs(res, cur + c, max(i, m), d + 1);
        }
    }
    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N;

        vector<string> res;
        dfs(res, "", -1, 0);
        REP(i, res.size()) {
            cout << res[i] << endl;
        }
    }
};
