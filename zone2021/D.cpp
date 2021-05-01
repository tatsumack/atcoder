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

class D {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        string s;
        cin >> s;

        deque<char> res;
        int state = 0;
        for (auto c : s) {
            if (c == 'R') {
                state ^= 1;
                continue;
            }
            if (state == 0) {
                res.push_back(c);
            } else {
                res.push_front(c);
            }
        }
        string ans;
        while (!res.empty()) {
            auto c = res.front();
            res.pop_front();
            if (ans != "" && ans.back() == c) {
                ans.pop_back();
            } else {
                ans += c;
            }
        }
        if (state == 1) {
            reverse(ans.begin(), ans.end());
        }
        cout << ans << endl;
    }
};
