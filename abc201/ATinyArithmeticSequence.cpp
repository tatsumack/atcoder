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

class ATinyArithmeticSequence {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        vector<int> A(3);
        REP(i, 3) cin >> A[i];
        sort(A.begin(), A.end());
        if (A[1] - A[0] == A[2] - A[1]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
};
