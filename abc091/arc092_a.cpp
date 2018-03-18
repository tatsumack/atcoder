#include <iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

struct Node
{
    int x, y;
    bool is_used;
    Node() {};
    Node(int _x, int _y) : x(_x), y(_y), is_used(false) {};
};

bool xasc(const Node& left, const Node& right) {
        return left.x < right.x;
}
bool ydsc(const Node& left, const Node& right) {
        return left.y > right.y;
}

Node R[101];
Node B[101];

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int x,y;
        cin >> x >> y;
        R[i] = Node(x, y);
    }
    sort(R, R+N, ydsc);

    for (int j = 0; j < N; ++j)
    {
        int x,y;
        cin >> x >> y;
        B[j] = Node(x, y);
    }
    sort(B, B+N, xasc);

    int ans1 = 0;
    for (int i = 0; i < N; ++i)
    {
        Node& b = B[i];
        for (int j = 0; j < N; ++j)
        {
            Node& r = R[j];
            if (!r.is_used && r.x < b.x && r.y < b.y)
            {
                ++ans1;
                r.is_used = true;
                break;
            }
        }
    }

    cout << ans1 << endl;

    return 0;
}
