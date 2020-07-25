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

class FDivisionOrSubtraction {
public:
    vector<int> get(int n) {
        vector<int> ret;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                ret.push_back(i);
                if (i != 1 && i * i != n) {
                    ret.push_back(n / i);
                }
            }
        }
        return ret;
    }

    bool check(int n, int k) {
        if (n < k) return n == 1;
        if (n % k == 0) return check(n / k, k);
        return (n % k) == 1;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;

        set<int> res;
        res.insert(N);
        if (N > 2) res.insert(N - 1);
        auto v1 = get(N - 1);
        for (auto n : v1) {
            res.insert(n);
        }

        auto v2 = get(N);
        for (auto k : v2) {
            if (check(N, k)) {
                res.insert(k);
            }
        }

        cout << res.size() << endl;
    }
};
