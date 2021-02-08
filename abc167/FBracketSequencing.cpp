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

class FBracketSequencing {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<string> S(N);
        REP(i, N) cin >> S[i];
        vector<tuple<int,int>> f;
        vector<tuple<int, int, int>> s;
        REP(i, N) {
            int sum = 0;
            int m = 0;
            for (auto c :S[i]) {
                if (c == '(') {
                    sum++;
                } else {
                    sum--;
                }
                m = min(m, sum);
            }
            if (sum > 0) {
                f.push_back({m, sum});
                continue;
            }
            int sum2 = 0;
            int m2 = 0;
            for (int j = S[i].size() - 1; j >= 0; j--) {
                char c = S[i][j];
                if (c == '(') {
                    sum2--;
                } else {
                    sum2++;
                }
                m2 = min(m2, sum2);
            }
            s.push_back({m2, m, sum});
        }

        sort(f.rbegin(), f.rend());
        sort(s.begin(), s.end());
        bool ok = true;
        int cur = 0;
        for (auto val : f) {
            int m, s;
            tie(m, s) = val;
            if (cur + m < 0) {
                ok = false;
                break;
            }
            cur += s;
        }
        if (!ok) {
            cout << "No" << endl;
            return;
        }
        for (auto val : s) {
            int m2, m, s;
            tie(m2, m, s) = val;
            if (cur + m < 0) {
                ok = false;
                break;
            }
            cur += s;
        }
        if (!ok || cur != 0) {
            cout << "No" << endl;
            return;
        }
        cout << "Yes" << endl;
    }
};
