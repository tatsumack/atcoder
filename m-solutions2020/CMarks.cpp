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

class CMarks {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        REP(i, N) cin >> A[i];
        int sum = 0;
        REP(i, K) {
            sum += A[i];
        }
        vector<bool> res;
        FOR(i, K, N-1) {
            int prev = sum;
            sum -= A[i-K];
            sum += A[i];
            res.push_back(sum > prev);
        }
        for (auto val : res) cout << (val ? "Yes" : "No") << endl;
    }
};
