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

class AIntegerProduct {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> A(N);
        vector<pair<int, int>> v(N);
        REP(i, N) {
            string s;
            cin >> s;
            int x = 0;
            int num = 0;
            bool found = false;
            REP(i, s.size()) {
                if (s[i] == '.') {
                    found = true;
                    continue;
                }
                if (found) {
                    num++;
                }
                x = x * 10 + s[i] - '0';
            }
            REP(i, 9 - num) x *= 10;
            A[i] = x;
            int two = 0;
            while (x % 2 == 0) {
                two++;
                x /= 2;
            }
            int five = 0;
            while (x % 5 == 0) {
                five++;
                x /= 5;
            }
            v[i] = {two, five};
        }

        int res = 0;
        vector<vector<int>> num(61, vector<int>(21));
        REP(i, N) {
            int need2 = max(18 - v[i].first, 0LL);
            int need5 = max(18 - v[i].second, 0LL);
            FOR(i, need2, 60) {
                FOR(j, need5, 20) {
                    res += num[i][j];
                }
            }
            num[v[i].first][v[i].second]++;
        }
        cout << res << endl;
    }
};
