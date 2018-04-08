#include <iostream>
#include <algorithm>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (1e9)

using namespace std;

int A, B, K;

signed main()
{
    cin >> A >> B >> K;
    int aa = min(A + K - 1, B);
    int bb = max(A, B - K + 1);

    for (int i = A; i <= B; ++i)
    {
        if (i <= aa || bb <= i)
        {
            cout << i << endl;
        }
    }

    return 0;
}
