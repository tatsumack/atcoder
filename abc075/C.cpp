#include <iostream>
#include <algorithm>
#include <stack>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (3e9)

using namespace std;

int N, M;
int used[51];

struct Edge
{
    int from, to;
    Edge() {};
    Edge(int _from, int _to) : from(_from), to(_to) {};

};
Edge edge[51];

signed main()
{
    cin >> N >> M;
    REP(i, M)
    {
        int a, b;
        cin >> a >> b;
        edge[i] = Edge(a, b);
    }

    int ans = 0;
    REP(i, M)
    {
        REPS(j, N) used[j] = 0;

        stack<int> s;
        s.push(1);

        while (!s.empty())
        {
            int v = s.top(); s.pop();
            used[v] = 1;
            REP(j, M)
            {
                if (i == j) continue;

                Edge& e =  edge[j];
                if (e.from == v)
                {
                    if (used[e.to] == 1) continue;
                    s.push(e.to);
                }
                else if (e.to == v)
                {
                    if (used[e.from] == 1) continue;
                    s.push(e.from);
                }
            }
        }

        bool bConnect = true;
        REPS(j, N)
        {
            if (used[j] == 0)
            {
                bConnect = false;
                break;
            }
        }
        if (!bConnect) ++ans;
    }
    cout << ans << endl;

    return 0;
}
