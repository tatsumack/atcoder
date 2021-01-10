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

class DSnukePrime {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, C;
        cin >> N >> C;
        vector<pair<int, int>> v;
        REP(i, N) {
            int a, b, c;
            cin >> a >> b >> c;
            v.push_back({a, c});
            v.push_back({b + 1, -c});
        }
        sort(v.begin(), v.end());

        int day = 0;
        int cur = 0;
        int res = 0;
        REP(i, v.size()) {
            res += (v[i].first - day) * min(cur, C);
            day = v[i].first;
            cur += v[i].second;
            while (i + 1 < v.size() && day == v[i + 1].first) {
                i++;
                cur += v[i].second;
            }
        }
        cout << res << endl;
    }
};
