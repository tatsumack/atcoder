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

class DRGBTriplets {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        string s;
        cin >> s;
        vector<int> LR(N), LG(N), LB(N), RR(N), RG(N), RB(N);
        for (int i = 1; i < N; i++) {
            LR[i] = LR[i - 1] + (s[i - 1] == 'R');
            LG[i] = LG[i - 1] + (s[i - 1] == 'G');
            LB[i] = LB[i - 1] + (s[i - 1] == 'B');
        }
        for (int i = N - 2; i >= 0; i--) {
            RR[i] = RR[i + 1] + (s[i + 1] == 'R');
            RG[i] = RG[i + 1] + (s[i + 1] == 'G');
            RB[i] = RB[i + 1] + (s[i + 1] == 'B');
        }
        int res = 0;
        for (int i = 1; i < N - 1; i++) {
            if (s[i] == 'R') {
                res += LG[i] * RB[i] + LB[i] * RG[i];
                for (int j = 1; i - j >= 0 && i + j < N; j++) {
                    if ((s[i - j] == 'G' && s[i + j] == 'B')) res--;
                    if ((s[i - j] == 'B' && s[i + j] == 'G')) res--;
                }
            }
            if (s[i] == 'G') {
                res += LR[i] * RB[i] + LB[i] * RR[i];
                for (int j = 1; i - j >= 0 && i + j < N; j++) {
                    if ((s[i - j] == 'R' && s[i + j] == 'B')) res--;
                    if ((s[i - j] == 'B' && s[i + j] == 'R')) res--;
                }
            }
            if (s[i] == 'B') {
                res += LR[i] * RG[i] + LG[i] * RR[i];
                for (int j = 1; i - j >= 0 && i + j < N; j++) {
                    if ((s[i - j] == 'R' && s[i + j] == 'G')) res--;
                    if ((s[i - j] == 'G' && s[i + j] == 'R')) res--;
                }
            }
        }
        cout << res << endl;
    }
};
