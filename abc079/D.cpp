#include <iostream>
#include <algorithm>

#define int long long
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

using namespace std;

int H, W;
int c[10][10];
int A[201][201];

signed main()
{
    cin >> H >> W;
    REP(i, 10) REP(j, 10) cin >> c[i][j];

    REP(k, 10) REP(i, 10) REP(j, 10)
    {
        c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
    }

    int ans;
    REP(i, H) REP(j, W)
    {
        int a;
        cin >> a;
        if (a == -1) continue;
        ans += c[a][1];
    }

    cout << ans << endl;

    return 0;
}
