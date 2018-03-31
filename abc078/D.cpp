#include <iostream>
#include <algorithm>
#include <cmath>

#define int long long
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

using namespace std;

int N, Z, W;
int a[2001];

signed main()
{
    cin >> N >> Z >> W;
    REPS(i, N) cin >> a[i];

    int ans = N > 1 ? max(abs(a[N-1] - a[N]), abs(a[N] - W)) : abs(a[N] - W);
    cout << ans << endl;

    return 0;
}
