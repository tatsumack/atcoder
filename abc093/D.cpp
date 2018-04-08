#include <iostream>
#include <algorithm>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (3e9)

using namespace std;

bool search(int x, int A, int B)
{
    int ret = 0;
    for (int i = max(x/2-50, 1LL); i <= min(x/2+50, x); ++i)
    {
        int first = i;
        if (first >= A) ++first;
        int second = x + 1 - i;
        if (second >= B) ++second;
        ret = max(ret, first * second);
    }
    return ret < A*B;
}

int solve(int A, int B)
{
    if (A > B) swap(A, B);

    int lo = 0;
    int hi = INF;
    int ans = 0;
    while (lo <= hi)
    {
        int mid = (hi + lo) / 2;
        if (search(mid, A, B))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return ans;
}

signed main()
{
    int Q;
    cin >> Q;

    REP(i, Q)
    {
        int A, B;
        cin >> A >> B;

        int ans = solve(A, B);
        printf("%lld\n", ans);
    }

    return 0;
}
