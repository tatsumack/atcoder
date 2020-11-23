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

class DHachi {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        string s;
        cin >> s;

        if (s.size() == 1) {
            int n = s[0] - '0';
            cout << (n % 8 == 0 ? "Yes" : "No") << endl;
            return;
        }
        if (s.size() == 2) {
            int n1 = (s[0] - '0') * 10 + (s[1] - '0');
            int n2 = (s[1] - '0') * 10 + (s[0] - '0');
            cout << (n1 % 8 == 0 || n2 % 8 == 0 ? "Yes" : "No") << endl;
            return;
        }
        vector<string> cond;
        int cur = 0;
        while (cur < 1000) {
            if (cur >= 100) {
                string tmp = to_string(cur);
                bool ok = true;
                for (auto c : tmp) {
                    if (c == '0') {
                        ok = false;
                    }
                }
                if (ok) {
                    cond.push_back(tmp);
                }
            }
            cur += 8;
        }

        map<char, int> cnt;
        for (auto c : s) cnt[c]++;
        for (auto t : cond) {
            map<char, int> tmp;
            for (auto c : t) {
                tmp[c]++;
            }
            bool ok = true;
            for (auto kv : tmp) {
                if (cnt[kv.first] < kv.second) {
                    ok = false;
                }
            }
            if (ok) {
                cout << "Yes" << endl;
                return;
            }
        }
        cout << "No" << endl;
    }
};
