#include <iostream>
#include <algorithm>
#include <map>

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

    std::map<int, int> count;
    REP(i, N)
    {
        int a;
        cin >> a;
        if (count.find(a) != count.end())
        {
            count[a] = (count[a] + 1) % 2;
        }
        else
        {
            count[a] = 1;
        }
    }

    int ans = 0;
    for (auto c : count)
    {
        ans += c.second;
    }
    cout << ans << endl;

    return 0;
}
