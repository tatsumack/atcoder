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

class C {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<P> v1, v2;
        REP(i, N) {
            int a, b;
            cin >> a >> b;
            if (a < b) {
                v1.emplace_back(a, b);
            } else {
                v2.emplace_back(b, a);
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end(), greater<>());
        int x = 0;
        int res = 0;
        for (auto kv : v1) {
            x += kv.first;
            res = max(res, x);
            x -= kv.second;
        }
        for (auto kv : v2) {
            x += kv.second;
            res = max(res, x);
            x -= kv.first;
        }
        cout << res << endl;
    }
};
