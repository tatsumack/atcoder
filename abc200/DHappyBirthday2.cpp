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

class DHappyBirthday2 {
public:
    int bitcount(int n) {
        int cnt = 0;
        REP(i, 10) {
            if (n >> i & 1) cnt++;
        }
        return cnt;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> A(N);
        REP(i, N) cin >> A[i];
        map<int, int> m;
        int n = min(N, 8LL);
        REP(i, 1 << n) {
            if (i == 0) continue;
            int val = 0;
            REP(j, n) {
                if ((i >> j & 1) == 0) continue;
                val += A[j];
                val %= 200;
            }
            if (m.count(val)) {
                cout << "Yes" << endl;
                cout << bitcount(m[val]) << " ";
                REP(j, n) {
                    if ((m[val] >> j & 1) == 0) continue;
                    cout << j + 1 << " ";
                }
                cout << endl;
                cout << bitcount(i) << " ";
                REP(j, n) {
                    if ((i >> j & 1) == 0) continue;
                    cout << j + 1 << " ";
                }
                cout << endl;
                return;
            }
            m[val] = i;
        }
        cout << "No" << endl;
    }
};
