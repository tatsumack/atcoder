#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1e18
#define fcout cout << fixed << setprecision(12)

using namespace std;

vector<int> makeTable(const string& s) {
    int n = s.size();
    vector<int> ret(n + 1);
    ret[0] = -1;
    int j = -1;
    for (int i = 0; i < n; i++) {
        while (j >= 0 && s[i] != s[j]) j = ret[j];
        j++;
        ret[i + 1] = j;
    }
    return ret;
}

vector<int> kmp(const string& str, const string& word) {
    vector<int> table = makeTable(word), ret;
    int m = 0, i = 0, n = str.size();
    while (m + i < n) {
        if (word[i] == str[m + i]) {
            if (++i == (int) (word.size())) {
                ret.push_back(m);
                m = m + i - table[i];
                i = table[i];
            }
        } else {
            m = m + i - table[i];
            if (i > 0) i = table[i];
        }
    }
    return ret;
}

class FStringsOfEternity {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    set<int> pos;
    vector<bool> used;
    vector<int> memo;
    string u;
    string s, t;

    int dfs(int v) {
        if (memo[v] != -1) return memo[v];

        if (used[v]) {
            return memo[v] = INF;
        }

        used[v] = true;

        if (pos.count(v)) {
            int to = (v + t.size()) % s.size();
            return memo[v] = dfs(to) + 1;
        } else {
            return memo[v] = 0;
        }
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> s >> t;

        u = s;
        while (u.size() < s.size() + t.size()) {
            u += s;
        }

        auto v = kmp(u, t);
        REP(i, v.size()) pos.insert(v[i] % s.size());

        used = vector<bool>(s.size());
        memo = vector<int>(s.size(), -1);

        for (auto i : pos) {
            dfs(i);
        }

        int ans = 0;
        REP(i, s.size()) {
            ans = max(ans, memo[i]);
        }
        if (ans >= INF) ans = -1;

        cout << ans << endl;
    }
};
