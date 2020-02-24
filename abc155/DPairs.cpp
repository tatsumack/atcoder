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

class DPairs {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        REP(i, N) {
            cin >> A[i];
        }
        sort(A.begin(), A.end());

        int ng = -INF;
        int ok = INF;
        while (ok - ng > 1) {
            int x = (ok + ng) / 2;
            int num = 0;
            int xnum = 0;
            REP(i, N) {
                if (A[i] * A[i] <= x) {
                    xnum++;
                }
                if (A[i] > 0) {
                    int b = x / A[i];
                    if (x < 0 && x % A[i] != 0) b--;
                    num += upper_bound(A.begin(), A.end(), b) - A.begin();
                } else if (A[i] == 0) {
                    if (x >= 0) {
                        num += N;
                    }
                } else {
                    int b = x / A[i];
                    if (x < 0 && x % A[i] != 0) b++;
                    num += N - (lower_bound(A.begin(), A.end(), b) - A.begin());
                }
            }
            num -= xnum;
            num /= 2;
            if (num < K) {
                ng = x;
            } else {
                ok = x;
            }
        }
        cout << ok << endl;
    }
};
