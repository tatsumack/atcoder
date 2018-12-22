
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

int ans;
int N;

char c[] = {'7', '5', '3'};

void dfs(string s, int n, int k) {
    if (n == k) {
        int b = 0;
        REP(i, s.size()) {
            switch (s[i]) {
                case '7':
                    b |= (1 << 0);
                    break;
                case '5':
                    b |= (1 << 1);
                    break;
                case '3':
                    b |= (1 << 2);
                    break;
            }
        }

        if (b != 7) return;
        int a = stol(s);
        if (a <= N) ans++;
        return;
    }
    REP(i, 3) {
        dfs(s + c[i], n, k + 1);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    FOR(i, 1, 10) {
        dfs("", i, 0);
    }
    cout << ans << endl;

    return 0;
}
