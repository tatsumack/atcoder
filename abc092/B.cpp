#include <iostream>
#include <algorithm>

#define int long long
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

using namespace std;

int N, D, X;
int A[101];

signed main()
{
    cin >> N >> D >> X;

    int ans = 0;
    REP(i, N)
    {
        int a;
        cin >> a;

        int day = 1;
        int k = 1;
        while (day <= D)
        {
            ++ans;
            day = k * a + 1;
            ++k;
        }
    }
    cout << X + ans << endl;

    return 0;
}
