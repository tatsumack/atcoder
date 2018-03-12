#include<iostream>
#include <cstdlib>

using namespace std;

typedef long long ll;

ll H, W, D, Q;
struct Square {
    ll i;
    ll j;
};
Square A[90001];
ll d[90001] = {};

int main()
{

    cin >> H >> W >> D;
    for (int i = 1; i <= H; ++i)
    {
        for (int j = 1; j <= W; ++j)
        {
            struct Square s = {i, j};
            ll p;
            scanf("%lld", &p);
            A[p] = s;
        }
    }

    for (int i = D + 1; i <= H * W; ++i)
    {
        struct Square prev = A[i - D];
        d[i] = d[i - D] + abs(A[i].i - prev.i) + abs(A[i].j - prev.j);
    }

    cin >> Q;

    ll result[Q];
    for (int q = 0; q < Q; ++q)
    {
        int L, R;
        scanf("%d", &L);
        scanf("%d", &R);

        result[q] = d[R] - d[L];
    }

    for (int q = 0; q < Q; ++q)
    {
        printf("%lld\n", result[q]);
    }

    return 0;
}
