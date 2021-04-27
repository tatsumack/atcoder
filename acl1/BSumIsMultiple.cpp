#include <bits/stdc++.h>
#include <atcoder/all>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

vector<int> get(int n) {
    vector<int> ret;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i != 1 && i * i != n) {
                ret.push_back(n / i);
            }
        }
    }
    return ret;
}

class BSumIsMultiple {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        auto v = get(2 * N);
        int res = INF;
        for (auto val : v) {
            vector<int> r(2), m(2);
            r[0] = 0, m[0] = val;
            r[1] = -1, m[1] = 2 * N / val;
            auto p = atcoder::crt(r, m);
            if (p.first != 0 && p.second != 0)
                res = min(res, p.first);
        }
        cout << res << endl;
    }
};
