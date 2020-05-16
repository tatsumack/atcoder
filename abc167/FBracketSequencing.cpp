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

class FBracketSequencing {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<string> S(N);
        REP(i, N) cin >> S[i];

        int lo = 0;
        int ro = 0;
        vector<pair<int, int>> v;
        for (auto& s : S) {
            int cl = 0;
            int cr = 0;
            for (auto c : s) {
                if (c == '(') {
                    cl++;
                } else {
                    if (cl > 0) {
                        cl--;
                    } else {
                        cr++;
                    }
                }
            }
            if (cr == 0) {
                lo += cl;
            } else if (cl == 0) {
                ro += cr;
            } else {
                v.emplace_back(cr, -cl);
            }
        }

        int cl = lo;
        sort(v.begin(), v.end());
        for (auto kv : v) {
            int r, l;
            tie(r, l) = kv;
            l *= -1;
            if (cl < r) {
                cout << "No" << endl;
                return;
            }
            cl -= r;
            cl += l;
        }

        if (cl == ro) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
};
