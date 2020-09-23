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

class BMakingTriangle {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> L(N);
        REP(i, N) cin >> L[i];

        int res = 0;
        REP(i, N) {
            FOR(j, i + 1, N - 1) {
                FOR(k, j + 1, N - 1) {
                    if (L[i] == L[j]) continue;
                    if (L[i] == L[k]) continue;
                    if (L[j] == L[k]) continue;
                    if (L[i] + L[j] > L[k] && L[i] + L[k] > L[j] && L[j] + L[k] > L[i]) res++;
                }
            }
        }
        cout << res << endl;
    }
};
