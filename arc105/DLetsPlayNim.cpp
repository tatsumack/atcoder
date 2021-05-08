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

class DLetsPlayNim {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int T;
        cin >> T;
        while (T--) {
            int N;
            cin >> N;
            vector<int> a(N);
            REP(i, N) cin >> a[i];
            int res = 0;
            REP(i, N) res ^= a[i];
            if (res != 0) {
                if (N % 2 == 0) {
                    cout << "First" << endl;
                } else {
                    cout << "Second" << endl;
                }
            } else {
                map<int, int> cnt;
                for (auto n : a) {
                    cnt[n]++;
                }
                bool ok = true;
                for (auto kv : cnt) {
                    if (kv.second % 2 == 1) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    cout << "Second" << endl;
                    continue;
                }
                if (N % 2 == 0) {
                    cout << "First" << endl;
                } else {
                    cout << "Second" << endl;
                }
            }
        }
    }
};
