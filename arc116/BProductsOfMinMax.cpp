#include <bits/stdc++.h>
#include <atcoder/all>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef atcoder::modint998244353 mint;

class BProductsOfMinMax {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> A(N);
        REP(i, N) cin >> A[i];
        sort(A.begin(), A.end());
        mint cur = 1;
        mint sum = 0;
        FOR(i, 1, N - 1) {
            sum += A[i] * cur;
            cur *= 2;
        }

        mint res = 0;
        REP(i, N - 1) {
            res += sum * A[i];
            sum -= A[i + 1];
            sum /= 2;
        }
        REP(i, N) res += A[i] * A[i];
        cout << res.val() << endl;
    }
};
