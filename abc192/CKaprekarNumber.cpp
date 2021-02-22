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

class CKaprekarNumber {
public:
    int g1(int x) {
        vector<int> v;
        while (x > 0) {
            v.push_back(x % 10);
            x /= 10;
        }
        sort(v.rbegin(), v.rend());
        int res = 0;
        REP(i, v.size()) {
            res *= 10;
            res += v[i];
        }
        return res;
    }
    int g2(int x) {
        vector<int> v;
        while (x > 0) {
            v.push_back(x % 10);
            x /= 10;
        }
        sort(v.begin(), v.end());
        int res = 0;
        REP(i, v.size()) {
            res *= 10;
            res += v[i];
        }
        return res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;
        int cur = N;
        REP(i, K) {
            cur = g1(cur) - g2(cur);
        }
        cout << cur << endl;
    }
};
