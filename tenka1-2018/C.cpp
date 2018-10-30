
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

int N;

int solve1(vector<int> A) {
    vector<int> ans(N);
    ans[N / 2] = A[0];
    int l = 1;
    int r = N - 1;
    int center = N / 2;
    int cur = 1;
    while (center - cur >= 0) {
        if (center + cur > N - 1) {
            ans[center - cur] = cur % 2 == 1 ? A[r] : A[l];
            break;
        }
        if (cur % 2 == 1) {
            ans[center - cur] = A[r];
            ans[center + cur] = A[r - 1];
            r -= 2;
        } else {
            ans[center - cur] = A[l];
            ans[center + cur] = A[l + 1];
            l += 2;
        }
        cur++;
    }

    int res = 0;
    REP(i, N - 1) {
        res += abs(ans[i + 1] - ans[i]);
    }

    return res;
}

int solve2(vector<int> A) {
    vector<int> ans(N);
    ans[N / 2] = A[N - 1];
    int l = 0;
    int r = N - 2;
    int center = N / 2;
    int cur = 1;
    while (center - cur >= 0) {
        if (center + cur > N - 1) {
            ans[center - cur] = cur % 2 == 0 ? A[r] : A[l];
            break;
        }
        if (cur % 2 == 0) {
            ans[center - cur] = A[r];
            ans[center + cur] = A[r - 1];
            r -= 2;
        } else {
            ans[center - cur] = A[l];
            ans[center + cur] = A[l + 1];
            l += 2;
        }
        cur++;
    }

    int res = 0;
    REP(i, N - 1) {
        res += abs(ans[i + 1] - ans[i]);
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    vector<int> A(N);
    REP(i, N) cin >> A[i];

    sort(A.begin(), A.end());

    cout << max(solve1(A), solve2(A)) << endl;


    return 0;
}
