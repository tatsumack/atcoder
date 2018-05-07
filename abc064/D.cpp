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
#define REV(i, a) for (int i = (a); i > 0; --i)
#define CLR(a) memset((a), 0, sizeof(a))
#define DUMP(x) cerr << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

int N;
string S;

signed main() {
    cin >> N;
    cin >> S;

    int left = 0;
    int right = 0;
    REP(i, N) {
        char c = S[i];
        if (c == '(') {
            left++;
        } else {
            if (left == 0)
                right++;
            else
                --left;
        }
    }

    string ans = "";
    REP(i, right) { ans += "("; }
    ans += S;
    REP(i, left) { ans += ")"; }
    cout << ans << endl;

    return 0;
}
