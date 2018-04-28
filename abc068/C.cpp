#include <iostream>
#include <algorithm>
#include <set>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (3e15)

using namespace std;

int N, M;
int a[200005];
int b[200005];

signed main()
{
    cin >> N >> M;

    set<int> sa;
    set<int> sb;
    REP(i, M)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1) sb.insert(b);
        if (b == N) sa.insert(a);
    }

    for (int a : sa)
    {
        if (sb.find(a) != sb.end())
        {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;

    return 0;
}
