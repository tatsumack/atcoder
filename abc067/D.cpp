#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

#define INF (3e15)

using namespace std;

int N;
int df[100005];
int ds[100005];
vector<int> e[100005];

void bfs(queue<int>& q, int d[])
{
    while (!q.empty())
    {
        int v = q.front(); q.pop();
        for (int i = 0; i < e[v].size(); ++i)
        {
            int to = e[v][i];
            if (d[to] > 0) continue;
            d[to] = d[v] + 1;
            q.push(to);
        }
    }
}

signed main()
{
    cin >> N;

    REP(i,N-1)
    {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    queue <int> qf;
    qf.push(1);
    bfs(qf, df);

    queue <int> qs;
    qs.push(N);
    bfs(qs, ds);

    int sunuke = 0;
    int fennec = 0;
    REPS(i, N)
    {
        ds[i] < df[i] ? sunuke++ : fennec++;
    }
    sunuke >= fennec ? cout << "Snuke" << endl : cout << "Fennec" << endl;
    return 0;
}
