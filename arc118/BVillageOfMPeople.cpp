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

class BVillageOfMPeople {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int K, N, M;
        cin >> K >> N >> M;
        vector<int> A(K);
        REP(i, K) cin >> A[i];
        int ng = 0;
        int ok = INF;
        while (ok - ng > 1) {
            int x = (ok + ng) / 2;
            int lsum = 0;
            int rsum = 0;
            REP(i, K) {
                int l = (-x + M * A[i] + N - 1) / N;
                lsum += l;
                int r = (x + M * A[i]) / N;
                rsum += r;
            }
            if (lsum <= M && M <= rsum) {
                ok = x;
            } else {
                ng = x;
            }
        }
        vector<int> B(K), L(K), R(K);
        int sum = 0;
        REP(i, K) {
            L[i] = (-ok + M * A[i] + N - 1) / N;
            R[i] = (ok + M * A[i]) / N;
            sum += L[i];
        }
        REP(i, K) {
            int val = L[i];
            while (sum < M && val < R[i]) {
                val++;
                sum++;
            }
            B[i] = val;
        }
        REP(i, K) cout << B[i] << " ";
    }
};
