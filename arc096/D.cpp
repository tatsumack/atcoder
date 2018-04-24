#include <iostream>
#include <algorithm>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (3e14)

using namespace std;

int N,C;
int x[100003];
int v[100003];
int used[100003];

int sumv1[100003];
int max1[100003];

int sumv2[100003];
int max2[100003];

signed main()
{
    cin >> N >> C;
    REPS(i,N) cin >> x[i] >> v[i];

    for (int i = 1; i <= N; ++i)
        sumv1[i] = sumv1[i-1] + v[i];

    for (int i = 1; i <= N; ++i)
        max1[i] = sumv1[i] - 2*x[i];

    for (int i = 1; i <= N; ++i)
        max1[i] = max(max1[i-1], max1[i]);

    for (int i = N; i > 0; --i)
        sumv2[i] = sumv2[i+1] + v[i];

    for (int i = N; i > 0; --i)
        max2[i] = sumv2[i] - 2*(C - x[i]);

    for (int i = N; i > 0; --i)
        max2[i] = max(max2[i+1], max2[i]);


    int ans = 0;
    REPS(i, N)
    {
        ans = max(ans, max1[i-1] + sumv2[i] - (C - x[i]));
    }

    REPS(i, N)
    {
        ans = max(ans, max2[i+1] + sumv1[i] - x[i]);
    }
    cout << ans << endl;

    return 0;
}
