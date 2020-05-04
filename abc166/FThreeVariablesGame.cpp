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
int dp[100005][3][3][3];

class FThreeVariablesGame {
public:
    vector<char> res;

    void solve(std::istream& cin, std::ostream& cout) {
        int N, A, B, C;
        cin >> N >> A >> B >> C;

        vector<string> S(N);
        REP(i, N) cin >> S[i];
        map<char, int> cnt;
        cnt['A'] = A;
        cnt['B'] = B;
        cnt['C'] = C;

        vector<char> res;
        REP(i, N) {
            char ca = S[i][0];
            char cb = S[i][1];
            int a = cnt[ca];
            int b = cnt[cb];
            if (a == 0 && b == 0) {
                cout << "No" << endl;
                return;
            }
            if (a > b) {
                swap(a, b);
                swap(ca, cb);
            }
            if (a == b) {
                if (i+1 < N && (S[i+1][0] == cb || S[i+1][1] == cb)) {
                    swap(a, b);
                    swap(ca, cb);
                }
            }
            cnt[ca]++;
            cnt[cb]--;
            res.push_back(ca);
        }
        cout << "Yes" << endl;
        REP(i, N) cout << res[i] << endl;
    }
};
