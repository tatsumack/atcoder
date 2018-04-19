#include <iostream>
#include <algorithm>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (3e9)

using namespace std;

signed main()
{
    int A, B, X;
    cin >> A >> B >> X;
    if (X < A)
    {
        cout << "NO" << endl;
        return 0;
    }
    if (X > A + B)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;

    return 0;
}
