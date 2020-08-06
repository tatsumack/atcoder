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

class ELogs {
public:
    int N, K;
    vector<int> A;

    bool check(int x) {
        int cnt = 0;
        REP(i, N) {
            cnt += (A[i] - 1) / x;
        }
        return cnt <= K;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> K;
        A.resize(N);
        REP(i, N) cin >> A[i];

        int l = 0;
        int r = INF;
        while (r - l > 1) {
            int mid = (r + l) / 2;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << r << endl;
    }
};
