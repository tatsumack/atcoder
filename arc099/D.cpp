
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

int ketawa(int i) {
    if (i < 10) return i;
    return i % 10 + ketawa(i / 10);
}

void test(int k) {
    FOR(i, 1, k) {
        cout << i << ":" << (double) i / ketawa(i) << endl;
    }
}


double sunuke(string n) {
    int t = stoul(n);
    return (double) t / ketawa(t);
}

int f(int n) {
    if (n < 10) return n;

    string str = to_string(n);
    int keta = str.size();

    double res = INF;
    string ans;

    FOR(i, str[0] - '0', 9) {
        if (keta <= 2) {
            string t = to_string(i) + '9';
            if (sunuke(t) < res) {
                ans = t;
                res = sunuke(t);
            }
            continue;
        }
        FOR(j, str[1] - '0', 9) {
            if (keta <= 3) {
                string t = to_string(i) + to_string(j) + '9';
                if (sunuke(t) < res) {
                    ans = t;
                    res = sunuke(t);
                }
                continue;
            }
            FOR(k, str[2] - '0', 9) {
                string t = to_string(i) + to_string(j) + to_string(k);
                REP(l, keta - 3) {
                    t += '9';
                }
                if (sunuke(t) < res) {
                    ans = t;
                    res = sunuke(t);
                }
            }
        }
    }
    return stoul(ans);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int K;
    cin >> K;

    int cur = 0;
    while (K--) {
        cur = f(cur + 1);
        cout << cur << endl;
    }

    return 0;
}
