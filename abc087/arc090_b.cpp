#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>


using namespace std;

typedef long long ll;

struct edge {
    int to, cost; 
    edge(int _to, int _cost) : to(_to), cost(_cost) {};
};

int main()
{
    int N, M;
    cin >> N >> M;

    long x[N+1];
    bool visit[N+1];
    for (int i = 1; i <= N; ++i)
    {
        x[i] = LONG_MAX;
        visit[i] = false;
    }


    vector<edge> G[N+1];
    for (int i = 0; i < M; ++i)
    {
        int L, R, D;
        cin >> L >> R >> D;
        G[R].push_back(edge(L,D));
        G[L].push_back(edge(R,-D));
    }

    for (int i = 1; i <= N; ++i)
    {
        if (G[i].empty()) continue;

        if (x[i] == LONG_MAX) x[i] = 0;

        stack<int> s;
        s.push(i);
        while (!s.empty())
        {
            int t = s.top();
            s.pop();

            visit[t] = true;

            for (int j = 0; j < G[t].size(); ++j)
            {
                edge e = G[t][j];
                if (x[e.to] == LONG_MAX) x[e.to] = x[t] + e.cost;

                if (x[e.to] != x[t] + e.cost) {
                    cout << "No" << endl;
                    return 0;
                }

                if (!visit[e.to]) s.push(e.to);
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}
