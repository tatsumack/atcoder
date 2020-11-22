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

class BAbbreviateFox {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        string s;
        cin >> s;
        vector<char> res;
        for (auto c : s) {
            if (res.size() < 2 || c != 'x') {
                res.push_back(c);
                continue;
            }
            int i = res.size() - 1;
            if (res[i] == 'o' && res[i-1] == 'f') {
                res.pop_back();
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        cout << res.size() << endl;
    }
};
