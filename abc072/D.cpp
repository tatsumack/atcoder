#include <iostream>
#include <algorithm>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (3e9)

using namespace std;

int N;
int P[100003];

signed main()
{
    cin >> N;


    int ans = 0;
    int num = 0;
    REPS(i, N)
    {
        int p;
        cin >> p;

        if (i == p)
        {
            ++num;
        }

        if (i != p || i == N)
        {
            if (num > 0)
            {
                ans += num/2;
                if (num&1) ++ans;
            }
            num = 0;
        }
    }
    cout << ans << endl;


    return 0;
}
