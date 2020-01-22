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
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> P;

vector<int> makeTable(const vector<int>& s) {
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

vector<int> kmp(const vector<int>& str, const vector<int>& word) {
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

class FXorShift {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> a(N), b(N);
        REP(i, N) cin >> a[i];
        REP(i, N) cin >> b[i];
        vector<int> va(2 * N - 1), vb(N - 1);
        REP(i, 2 * N - 1) va[i] = a[i % N] ^ a[(i + 1) % N];
        REP(i, N - 1) vb[i] = b[i] ^ b[i + 1];

        auto v = kmp(va, vb);
        vector<P> res;
        REP(i, v.size()) {
            int idx = v[i];
            if (idx >= N) continue;
            res.push_back({idx, b[0] ^ a[idx]});
        }
        for (auto kv : res) {
            cout << kv.first << " " << kv.second << endl;
        }
    }
};
