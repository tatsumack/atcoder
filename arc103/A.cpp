
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

    int n;

    cin >> n;

    map<int, int> cnt0;
    map<int, int> cnt1;

    REP(i, n) {
        int a;
        cin >> a;
        if (i % 2 == 0) {
            cnt0[a]++;
        } else {
            cnt1[a]++;
        }
    }

    int maxf0 = 0;
    int maxs0 = 0;
    int cntf0 = 0;
    int cnts0 = 0;
    for (auto kv : cnt0) {
        if (kv.second > cntf0) {
            maxs0 = maxf0;
            cnts0 = cntf0;
            maxf0 = kv.first;
            cntf0 = kv.second;
        } else if (kv.second > cnts0) {
            maxs0 = kv.first;
            cnts0 = kv.second;
        }
    }

    int maxf1 = 0;
    int maxs1 = 0;
    int cntf1 = 0;
    int cnts1 = 0;
    for (auto kv : cnt1) {
        if (kv.second > cntf1) {
            maxs1 = maxf1;
            cnts1 = cntf1;
            maxf1 = kv.first;
            cntf1 = kv.second;
        } else if (kv.second > cnts1) {
            maxs1 = kv.first;
            cnts1 = kv.second;
        }
    }

    if (maxf0 != maxf1) {
        cout << n - (cntf0 + cntf1) << endl;
    } else {
        if (cntf0 + cnts1 > cnts0 + cntf1) {
            cout << n - (cntf0 + cnts1) << endl;
        }
        else {
            cout << n - (cnts0 + cntf1) << endl;
        }
    }
    return 0;
}
