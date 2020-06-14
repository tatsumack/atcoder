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

class CLamps {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        REP(i, N) cin >> A[i];

        while (K--) {
            vector<int> V(N+1);
            REP(i, N) {
                int val = A[i];
                int l = max(0LL, i - val);
                int r = min(N, i + val + 1);
                V[l] += 1;
                V[r] -= 1;
            }
            FOR(i, 1, N) {
                V[i] += V[i-1];
            }
            swap(A, V);

            bool finish = true;
            REP(i, N) {
                if (A[i] < N) {
                    finish = false;
                    break;
                }
            }
            if (finish) break;
        }
        REP(i, N) cout << A[i] << " ";
    }
};
