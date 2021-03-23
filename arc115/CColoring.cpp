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

class CColoring {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> res(N, -1);
        res[0] = 1;
        FOR(i, 2, N) {
            int cur = i;
            if (res[i - 1] == -1) res[i - 1] = 2;
            int val = res[i - 1];
            cur += i;
            while (cur <= N) {
                res[cur - 1] = max(res[cur - 1], val + 1);
                cur += i;
            }
        }
        REP(i, N) cout << res[i] << " ";
        cout << endl;
    }
};
