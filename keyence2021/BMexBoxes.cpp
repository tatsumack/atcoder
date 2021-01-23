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

class BMexBoxes {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;
        vector<int> a(N);
        REP(i, N) cin >> a[i];
        sort(a.begin(), a.end());
        map<int, int> m;
        REP(i, K) m[-1]++;
        REP(i, N) {
            if (m[a[i] - 1] > 0) {
                m[a[i] - 1]--;
                m[a[i]]++;
            }
        }
        int res = 0;
        for (auto kv : m) {
            if (kv.first == -1) continue;
            res += (kv.first + 1) * kv.second;
        }
        cout << res << endl;
    }
};
