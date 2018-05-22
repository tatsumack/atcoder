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
#define CLR(a) memset((a), 0, sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

int N, K, A[5005];

bool dp[5005][5005];

bool need(int t)
{
    CLR(dp);
    dp[0][0] = true;
    REPS(i, N)
    {
        int a = A[i - 1];
        FOR(j, 0, K)
        {
            if (i == t)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else if (j - a < 0)
            {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            else
            {
                dp[i][j] = dp[i - 1][j - a] || dp[i - 1][j];
            }
            if (dp[i][j] && j >= K - A[t - 1] && j < K)
                return true;
        }
    }
    return false;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    REP(i, N)
    {
        cin >> A[i];
    }
    sort(A, A + N);

    if (!need(N))
    {
        cout << N << endl;
        return 0;
    }

    int left = 0;
    int right = N;
    while (right - left > 1)
    {
        int mid = (left + right) / 2;
        if (need(mid))
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    cout << left << endl;

    return 0;
}
