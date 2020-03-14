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

class DMangaMarket {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, T;
        cin >> N >> T;
        vector<int> a(N), b(N);
        REP(i, N) cin >> a[i] >> b[i];

        vector<pair<P, int>> t(N);
        REP(i, N) {
            int time = (T - b[i]);
            if (a[i] > 0) time /= a[i];
            t[i] = {{time, -a[i]}, i};
        }
        sort(t.rbegin(), t.rend());

        int cur = T;
        int res = 0;
        REP(i, N) {
            auto kv = t[i];
            int idx = kv.second;
            cur = cur - b[idx];
            if (a[idx] > 0) cur /= a[idx];
            cur -= 1;
            if (cur < 0) break;
            res++;
        }
        cout << res << endl;
    }
};
