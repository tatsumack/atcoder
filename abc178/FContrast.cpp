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

class FContrast {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> A(N), B(N), CA(N+1), CB(N+1);
        REP(i, N) {
            cin >> A[i];
            CA[A[i]]++;
        }
        REP(i, N) {
            cin >> B[i];
            CB[B[i]]++;
        }
        FOR(i, 1, N) {
            if (CA[i] + CB[i] > N) {
                cout << "No" << endl;
                return;
            }
        }

        cout << "Yes" << endl;
        sort(B.rbegin(), B.rend());

        int x = -1;
        int p = -1;
        REP(i, N) {
            if (A[i] == B[i]) {
                x = A[i];
                p = i;
                break;
            }
        }
        if (x == -1) {
            REP(i, N) cout << B[i] << " ";
            return;
        }
        REP(i, N) {
            if (A[i] != x && B[i] != x) {
                swap(B[i], B[p]);
                p++;
                if (p >= N) break;
                if (A[p] != x || B[p] != x) break;
            }
        }
        REP(i, N) cout << B[i] << " ";
    }
};
