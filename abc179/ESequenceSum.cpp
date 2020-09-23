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

class ESequenceSum {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, X, M;
        cin >> N >> X >> M;

        if (N == 1) {
            cout << X << endl;
            return;
        }

        int num = 1;
        int sum = X;
        int cur = X;
        vector<int> v(M + 1);
        v[0] = X;
        set<int> s;
        s.insert(X);
        REP(i, M) {
            cur = (cur * cur) % M;
            v[i + 1] = cur;
            if (s.count(cur)) break;
            sum += cur;
            num++;
            if (num == N) {
                cout << sum << endl;
                return;
            }
        }
        int len = 0;
        int prev = 0;
        int t = -1;
        sum = 0;
        REP(i, M) {
            if (len > 0) {
                if (v[i] == cur) {
                    break;
                }
                sum += v[i];
                len++;
            } else {
                if (v[i] == cur) {
                    len = 1;
                    sum += v[i];
                    t = i;
                } else {
                    prev += v[i];
                }
            }
        }
        int k = (N - t) / len;
        int res = k * sum + prev;
        FOR(i, t + len * k, N-1) {
            res += cur;
            cur = (cur * cur) % M;
        }
        cout << res << endl;


    }
};
