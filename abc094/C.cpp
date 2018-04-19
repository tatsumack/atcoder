#include <iostream>
#include <algorithm>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (3e9)

using namespace std;

int N;
int X[200003];
int SX[200003];

signed main()
{
    cin >> N;
    REP(i, N)
    {
        int x;
        cin >> x;
        X[i] = x;
        SX[i] = x;
    }


    sort(SX, SX+N);
    int mid = SX[N/2 - 1];
    int mid2 = SX[N/2];

    REP(i, N)
    {
        if (X[i] <= mid)
        {
            printf("%lld\n", mid2);
        }
        else
        {
            printf("%lld\n", mid);
        }
    }

    return 0;
}
