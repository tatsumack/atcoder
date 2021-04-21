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

class AAgain {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        string S;
        cin >> S;
        vector<int> A(N + 1);
        REP(i, N + 1) cin >> A[i];
        int num = INF;
        REP(i, N) {
            num = min(num, abs(A[i + 1] - A[i]));
        }
        cout << num << endl;
        REP(j, num) {
            REP(i, N + 1) {
                cout << (A[i] + j) / num << " ";
            }
            cout << endl;
        }
    }
};
