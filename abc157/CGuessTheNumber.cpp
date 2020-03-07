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

class CGuessTheNumber {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M;
        cin >> N >> M;
        bool ok = true;
        map<int, int> pos;
        REP(i, M) {
            int s, c;
            cin >> s >> c;
            s--;
            if (pos.count(s) > 0 && pos[s] != c) {
                ok = false;
            }
            pos[s] = c;
        }
        if (!ok) {
            cout << -1 << endl;
            return;
        }

        if (pos.count(0) > 0 && pos[0] == 0 && N > 1) {
            cout << -1 << endl;
            return;
        }

        string res;
        REP(i, N) {
            if (pos.count(i) > 0) {
                res += pos[i] + '0';
            } else {
                if (i == 0 && N > 1) {
                    res += '1';
                } else {
                    res += '0';
                }
            }
        }
        cout << res << endl;
    }
};
