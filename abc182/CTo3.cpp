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

class CTo3 {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        string N;
        cin >> N;
        int cur = 0;
        map<int, int> cnt;
        REP(i, N.size()) {
            int n = N[i] - '0';
            cur += n;
            cur %= 3;
            cnt[n % 3]++;
        }
        if (cur == 0) {
            cout << 0 << endl;
        }
        if (cur == 1) {
            if (cnt[1] > 0 && N.size() > 1) {
                cout << 1 << endl;
            } else if (cnt[2] >= 2 && N.size() > 2) {
                cout << 2 << endl;
            } else {
                cout << -1 << endl;
            }
        }
        if (cur == 2) {
            if (cnt[2] > 0 && N.size() > 1) {
                cout << 1 << endl;
            } else if (cnt[1] >= 2 && N.size() > 2) {
                cout << 2 << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
};
