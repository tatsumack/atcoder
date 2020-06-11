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

class ECountMedian {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> A(N), B(N);
        REP(i, N) cin >> A[i] >> B[i];
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        if (N & 1) {
            int mid = N / 2;
            cout << B[mid] - A[mid] + 1 << endl;
        } else {
            int mid1 = N / 2;
            int mid2 = mid1 - 1;
            cout << (B[mid1] + B[mid2]) - (A[mid1] + A[mid2]) + 1 << endl;
        }

    }
};
