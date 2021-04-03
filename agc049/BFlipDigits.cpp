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

class BFlipDigits {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        string S, T;
        cin >> S >> T;
        vector<int> v;
        for (int i = N - 1; i >= 0; i--) {
            if (S[i] == '0') continue;
            v.push_back(i);
        }

        int res = 0;
        REP(i, N) {
            if (S[i] == '1') {
                v.pop_back();
            }
            if (S[i] == T[i]) continue;
            if (v.empty()) {
                cout << -1 << endl;
                return;
            }
            int next = v.back();
            v.pop_back();
            res += next - i;
            S[next] = '0';
        }
        cout << res << endl;
    }
};
