
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
#define fcout cout << fixed << setprecision(10)

using namespace std;

template<typename T>
vector <T> make_v(size_t a) { return vector<T>(a); }

template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T& t, const V& v) { t = v; }

template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T& t, const V& v) {
    for (auto& e:t) fill_v(e, v);
}

typedef pair<int, int> P;

unordered_map<int, unordered_map<string, int>> memo;
int N;
int mod = 1e9 + 7;

bool ok(string str) {
    if (str.find("AGC") != string::npos) return false;
    if (str.find("ACG") != string::npos) return false;
    if (str.find("GAC") != string::npos) return false;
    if (str[0] == 'A' && str[2] == 'G' && str[3] == 'C') return false;
    if (str[0] == 'A' && str[1] == 'G' && str[3] == 'C') return false;

    return true;
}

int dfs(int pos, string cur) {
    if (memo.count(pos) && memo[pos].count(cur)) return memo[pos][cur];
    if (pos == N) return 1;

    string sub = cur.substr(1, 3);
    char cand[] = {'A', 'G', 'C', 'T'};
    int res = 0;
    REP(i, 4) {
        if (ok(sub + cand[i])) {
            res += dfs(pos + 1, sub + cand[i]);
            res %= mod;
        }
    }

    return memo[pos][cur] = res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    cout << dfs(0, "TTTT") << endl;

    return 0;
}
