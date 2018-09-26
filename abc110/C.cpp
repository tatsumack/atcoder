
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S, T;
    cin >> S >> T;

    map<char, char> map1;
    map<char, char> map2;
    REP(i, S.size()) {
        char s = S[i];
        char t = T[i];

        if (map1.count(s) > 0)
        {
            char ns = map1[s];
            if (ns != t) {
                cout << "No" << endl;
                return 0;
            }
        }

        if (map2.count(t) > 0) {
            char nt = map2[t];
            if (nt != s) {
                cout << "No" << endl;
                return 0;
            }
        }

        if (map1.count(s) == 0) {
            map1[s] = t;
        }
        if (map2.count(t) == 0) {
            map2[t] = s;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
