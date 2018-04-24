#include <iostream>
#include <algorithm>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (3e9)

using namespace std;

int A, B, C, D, E, F;

signed main()
{
    cin >> A >> B >> C >> D >> E >> F;
    A *= 100;
    B *= 100;

    int maxSW = 0;
    int maxSG = 0;
    for (int i = 0; A*i <= F; ++i)
    for (int j = 0; A*i + B*j <= F; ++j)
    for (int m = 0; A*i + B*j + C*m <= F; ++m)
    for (int n = 0; A*i + B*j + C*m + D*n <= F; ++n)
    {
        int a = A*i + B*j;
        int b = C*m + D*n;
        if (a+b > F) continue;
        if (a/100 * E < b) continue;

        if (b*maxSW >= (a+b)*maxSG)
        {
            maxSW = a+b;
            maxSG = b;
        }
    }
    printf("%lld %lld\n", maxSW, maxSG);

    return 0;
}
