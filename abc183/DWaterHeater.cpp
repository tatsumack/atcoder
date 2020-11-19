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

class DWaterHeater {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        vector<int> sum(200005);
        int N, W;
        cin >> N >> W;
        REP(i, N) {
            int s, t, p;
            cin >> s >> t >> p;
            sum[s] += p;
            sum[t] -= p;
        }
        REP(i, 200002) {
            sum[i+1] += sum[i];
        }
        REP(i, 200002) {
            if (sum[i] > W) {
                cout << "No" << endl;
                return;
            }
        }
        cout << "Yes" << endl;
    }
};
