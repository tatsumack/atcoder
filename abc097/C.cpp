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

#define int long long

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define REV(i, a) for (int i = (a); i >= 0; --i)
#define CLR(a) memset((a), 0, sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

string S;
int K;
signed main() {
    cin >> S;
    cin >> K;

    vector<string> vs;
    REP(i, S.size()) {
        FOR(j, i + 1, i + 10) { vs.push_back(S.substr(i, j - i)); }
    }
    sort(vs.begin(), vs.end());
    vs.erase(unique(vs.begin(), vs.end()), vs.end());
    // REP(i, vs.size()) { DUMP(vs[i]); }
    cout << vs[K - 1] << endl;

    return 0;
}
