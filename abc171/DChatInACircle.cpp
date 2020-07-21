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

class DChatInACircle {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> A(N);
        REP(i, N) cin >> A[i];
        sort(A.rbegin(), A.rend());

        int num = 1;
        int res = A[0];
        FOR(i, 1, A.size() - 1) {
            if (num == A.size() - 1) break;
            if (num + 2 < A.size()) {
                res += A[i] * 2;
                num += 2;
            } else if (num + 1 < A.size()) {
                res += A[i];
                num += 1;
            }
        }
        cout << res << endl;
    }
};
