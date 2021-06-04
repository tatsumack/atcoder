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

class CFriendsAndTravelCosts {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;
        vector<pair<int, int>> v(N);
        REP(i, N) {
            int a, b;
            cin >> a >> b;
            v[i] = {a, b};
        }
        sort(v.begin(), v.end());

        int res = 0;
        int prev = 0;
        REP(i, N) {
            int need = v[i].first - prev;
            if (K < need) {
                res = prev + K;
                K = 0;
                break;
            }
            K -= need;
            K += v[i].second;
            prev = v[i].first;
        }
        if (K > 0) {
            res = prev + K;
        }
        cout << res << endl;
    }
};
