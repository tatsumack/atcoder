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

class CComma {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        int comma = 0;
        int cur = 1;
        int res = 0;
        while (cur < N) {
            int next = cur * 1000;
            if (next > N) break;
            res += comma * (next - cur);
            comma++;
            cur = next;
        }
        if (cur <= N) {
            res += comma * (N - cur + 1);
        }
        cout << res << endl;
    }
};
