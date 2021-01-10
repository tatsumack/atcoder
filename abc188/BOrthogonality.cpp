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

class BOrthogonality {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> A(N), B(N);
        REP(i, N) cin >> A[i];
        REP(i, N) cin >> B[i];

        int res = 0;
        REP(i, N) res += A[i] * B[i];
        cout << (res == 0 ? "Yes" : "No") << endl;
    }
};
