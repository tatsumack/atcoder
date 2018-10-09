
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

int N, M;

// 素因数
vector<int> getPrimeFactors(int a) {
    vector<int> s;
    for (int i = 2; i * i <= a; i++) {
        if (a % i != 0) continue;
        while (a % i == 0) {
            s.push_back(i);
            a /= i;
        }
    }
    if (a > 1) s.push_back(a);
    return s;
}

int dfs(map<int, int>& cnt, vector<int>& v, vector<int>& num, int i) {
    if (i == v.size()) {
        int t = 1;
        REP(ii, v.size()) {
            REP(k, num[ii]) {
                t *= v[ii];
            }
        }
        return t;
    }

    int res = INF;
    FOR(j, 0, cnt[v[i]]) {
        num.push_back(j);
        int tmp = dfs(cnt, v, num, i + 1);
        if (tmp >= N) {
            res = min(res, dfs(cnt, v, num, i + 1));
        }
        num.pop_back();
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    if (N == 1) {
        cout << M << endl;
        return 0;
    }

    vector<int> v = getPrimeFactors(M);
    sort(v.begin(), v.end());

    vector<int> s;
    s.push_back(v[0]);
    map<int, int> cnt;
    REP(i, v.size()) {
        cnt[v[i]]++;
        if (s.back() != v[i]) {
            s.push_back(v[i]);
        }
    }

    int ans = 1;
    int t = v[0];
    int r = 0;

    vector<int> num;
    int res = dfs(cnt, s, num, 0);

    cout << M / res << endl;

    return 0;
}
