#include <iostream>
#include <algorithm>
#include <map>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (3e15)

using namespace std;

int N;

signed main()
{
    cin >> N;


    int a4 = 0;
    int a2 = 0;
    REP(i,N)
    {
        int a;
        cin >> a;

        if (a%4 == 0)
        {
            a4++;
        }
        else if (a%2 == 0)
        {
            a2++;
        }
    }

    int ans = 0;
    if (a4 > 0) ans += 2*a4+1;
    if (a2 > 0) ans += a2/2*2;

    if (ans >= N)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
