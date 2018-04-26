#include <iostream>
#include <algorithm>
 
#define int long long
 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
 
#define INF (3e9)
 
using namespace std;
 
int N;
int A[100003];
 
signed main()
{
    cin >> N;
    REP(i, N) cin >> A[i];
 
    sort(A, A+N);
 
    int a1 = 0;
    int a2 = 0;
    for (int i = N-1; i > 0; --i)
    {
        if (A[i] == A[i-1])
        {
            if (a1 == 0)
            {
                a1 = A[i];
            }
            else
            {
                a2 = A[i];
                break;
            }
            --i;
        }
    }
    cout << a1 * a2 << endl;
 
    return 0;
}
