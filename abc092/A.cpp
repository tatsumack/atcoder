#include <iostream>
#include <algorithm>

#define int long long
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

using namespace std;

int A, B, C, D;

signed main()
{
    cin >> A >> B >> C >> D;
    cout << min(A, B) + min(C, D) << endl;

    return 0;
}
