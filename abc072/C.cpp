#include <iostream>
#include <algorithm>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (3e9)

using namespace std;

int N;
int A[300003];

signed main()
{
    cin >> N;
    REP(i, N)
    {
        int a;
        cin >> a;

        A[i*3] = a-1;
        A[i*3+1] = a;
        A[i*3+2] = a+1;
    }
    sort(A, A+N*3);

    int contNum = 0;
    int maxNum = 0;
    int prev = INF;
    REP(i, N*3)
    {
        int a = A[i];
        if (a == prev)
        {
            ++contNum;
        }
        else
        {
            if (contNum > maxNum)
            {
                maxNum = contNum;
            }
            contNum = 1;
        }
        prev = a;
    }
    cout << maxNum << endl;

    return 0;
}
