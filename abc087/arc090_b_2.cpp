#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>
#include <utility>


using namespace std;

struct WeightedUnionFindTree {
    vector<int> parent;
    vector<int> rank;
    vector<int> diff_weight;

    void init(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            parent.push_back(i);
            diff_weight.push_back(0);
            rank.push_back(0);
        }
    }

    int root(int x)
    {
        if (parent[x] == x) return x;
        int r = root(parent[x]);
        diff_weight[x] += diff_weight[parent[x]];
        return parent[x] = r;
    }

    int weight(int x)
    {
        root(x);
        return diff_weight[x];
    }

    int diff(int x, int y)
    {
        return weight(y) - weight(x);
    }

    bool merge(int x, int y, int w)
    {
        int root_x = root(x);
        int root_y = root(y);
        if (root_x == root_y) return false;

        int root_y_weight = w - diff_weight[y] + diff_weight[x];

        if (rank[root_x] < rank[root_y]) swap(root_x, root_y), root_y_weight = -root_y_weight;

        parent[root_y] = root_x;
        diff_weight[root_y] = root_y_weight;
        if (rank[root_x] == rank[root_y]) ++rank[root_x];

        return true;
    }

    bool issame(int x, int y)
    {
        return root(x) == root(y);
    }
};

int main()
{
    int N, M;
    cin >> N >> M;

    struct WeightedUnionFindTree wuf;
    wuf.init(N);

    for (int i = 0; i < M; ++i)
    {
        int L, R, D;
        cin >> L >> R >> D;

        --L, --R;
        if (wuf.issame(L, R))
        {
            if (wuf.diff(L, R) != D)
            {
                cout << "No" << endl;
                return 0;
            }
        }
        else
        {
            wuf.merge(L, R, D);
        }
    }

    cout << "Yes" << endl;

    return 0;
}
