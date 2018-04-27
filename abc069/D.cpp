#include <iostream>
#include <algorithm>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (3e15)

using namespace std;

int H, W, N;
int A[10005];
int c[105][105];


signed main()
{
    cin >> H >> W;
    cin >> N;
    REP(i, N) cin >> A[i];

    int aindex = 0;
    REP(i, H) REP(j, W)
    {
        while (A[aindex] == 0) aindex++;
        A[aindex]--;
        c[i][i%2 == 0 ? j : W-1-j] = aindex+1;
    }
    REP(i, H) REP(j, W)
    {
        if (j != 0) printf(" ");
        printf("%lld", c[i][j]);
        if (j == W-1) printf("\n");
    }

    return 0;
}
