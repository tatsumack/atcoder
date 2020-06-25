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

class DReplacing {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> A(N);
        map<int, int> m;
        int sum = 0;
        REP(i, N) {
            cin >> A[i];
            m[A[i]]++;
            sum += A[i];
        }

        int Q;
        cin >> Q;
        while (Q--) {
            int b, c;
            cin >> b >> c;
            sum += (c - b) * m[b];
            m[c] += m[b];
            m[b] = 0;
            cout << sum << endl;
        }
    }
};
