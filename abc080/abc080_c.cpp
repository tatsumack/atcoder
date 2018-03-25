#include <iostream>
#include <algorithm>
#include <cmath>

#define int long long
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

using namespace std;

int N;
int F[101][11];
int P[101][11];

signed main()
{
    cin >> N;
    REPS(i, N) REPS(j, 10) cin >> F[i][j];
    REPS(i, N) REPS(j, 11) cin >> P[i][j];

    int ans = -(1 << 30);
    REPS(i, (1 << 10) - 1)
    {
        int c = 0;
        REPS(j, N)
        {
            int tmpc = 0;
            REPS(k, 10)
            {
                if ((i >> (k-1)) & 1) tmpc += F[j][k];
            }
            c += P[j][tmpc+1];
        }
        ans = max(ans, c);
    }
    cout << ans << endl;

    return 0;
}
