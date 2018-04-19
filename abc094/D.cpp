#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (3e9)

using namespace std;

int n;
int a[100003];

signed main()
{
    cin >> n;

    int maxa = 0;
    REP(i, n)
    {
        cin >> a[i];
        maxa = max(maxa, a[i]);
    }

    int maxr = 0;
    int rindex = 0;
    REP(i, n)
    {
        int r = min(maxa-a[i], a[i]);
        if (r >= maxr)
        {
            maxr = r;
            rindex = i;
        }
    }

    printf("%lld %lld\n", maxa, a[rindex]);

    return 0;
}
