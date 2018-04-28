#include <iostream>
#include <algorithm>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (3e15)

using namespace std;

int K;

int A[55];

signed main()
{
    cin >> K;

    int N = 50;
    REP(i, N) A[i] = i+K/50;

    REP(i, K%N)
    {
        REP(j,N)
        {
            A[j] = i == j ? A[j] + 50 : A[j]-1;
        }
    }
    cout << N << endl;
    REP(i, N)
    {
        if (i != 0) cout << " ";
        cout << A[i];
    }
    cout << endl;

    return 0;
}
