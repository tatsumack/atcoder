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
    vector<int> A;
    int N, K;

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N >> K;
        A.resize(N);
        REP(i, N) cin >> A[i];
        sort(A.begin(), A.end());

        vector<int> m, p;
        int minus = 0, plus = 0, zero = 0;
        REP(i, N) {
            if (A[i] < 0) {
                minus++;
                m.push_back(A[i]);
            }
            if (A[i] > 0) {
                plus++;
                p.push_back(A[i]);
            }
            if (A[i] == 0) {
                zero++;
            }
        }
        int num = 0;
        if (minus * plus > K) {
            int l = -INF;
            int r = 0;
            while (r - l > 1) {
                int mid = (r + l) / 2;
                int num = 0;
                REP(i, m.size()) {
                    int x = m[i];
                    int v = (mid + abs(x) - 1) / x;
                    num += lower_bound(p.begin(), p.end(), v) - p.begin();
                }
                if (num >= K) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            cout << l << endl;
            return;
        }
        num += minus * plus;
        if (num + zero * plus + zero * minus + zero * (zero - 1) / 2 > K) {
            cout << 0 << endl;
            return;
        }
        num += zero * plus + zero * minus + zero * (zero - 1) / 2;

        for (auto& n : m) {
            n = abs(n);
        }
        sort(m.begin(), m.end());

        int l = 0;
        int r = INF;
        while (r - l > 1) {
            int mid = (r + l) / 2;
            int num1 = 0;
            int msz = m.size();
            REP(i, m.size()) {
                int x = m[i];
                int v = mid / x;
                int idx = upper_bound(m.begin(), m.end(), v) - m.begin();
                if (idx < i) continue;
                num1 += msz - idx;
            }
            int num2 = 0;
            int psz = p.size();
            REP(i, p.size()) {
                int x = p[i];
                int v = mid / x;
                int idx = upper_bound(p.begin(), p.end(), v) - p.begin();
                if (idx < i) continue;
                num2 += psz - idx;
            }
            int res = msz * (msz - 1) / 2 - num1 + psz * (psz - 1) / 2 - num2;
            if (res > K - num) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << l << endl;
    }
};
