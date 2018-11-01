
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

    int a, b, c;
    cin >> a >> b >> c;
    int pa = a % 2;
    int pb = b % 2;
    int pc = c % 2;

    int num = 0;
    if (pa != pb && pa != pc) {
        b++;
        c++;
        num++;
    }
    if (pb != pa && pb != pc) {
        a++;
        c++;
        num++;
    }
    if (pc != pa && pc != pb) {
        a++;
        b++;
        num++;
    }

    int maxn = max({a, b, c});
    num += (maxn - a) / 2 + (maxn - b) / 2 + (maxn - c) / 2;
    cout << num << endl;

    return 0;
}
