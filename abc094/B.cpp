#include <iostream>
#include <algorithm>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (3e9)

using namespace std;

int N, M, X;

signed main()
{
    cin >> N >> M >> X;
    int ans1 = 0;
    int ans2 = 0;
    REP(i, M)
    {
        int a;
        cin >> a;
        if ( a < X ) ++ans1;
        if ( a > X ) ++ans2;
    }
    int ans = min(ans1, ans2);
    cout << ans << endl;

    return 0;
}
