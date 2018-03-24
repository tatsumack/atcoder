#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

struct OP
{
    int x, y;
    OP(int _x, int _y) : x(_x), y(_y) {};
    OP() {};
};

int N;
int a[51];
OP ops[101];

int main()
{
    cin >> N;
    cin >> a[1];
    int maxA = a[1];
    int maxI = 1;
    int minA = a[1];
    int minI = 1;
    for (int i = 2; i <= N; ++i)
    {
        cin >> a[i];
        if (maxA < a[i])
        {
            maxA = a[i];
            maxI = i;
        }
        if (minA > a[i])
        {
            minA = a[i];
            minI = i;
        }
    }

    int opnum = 0;
    if (minA < 0 && abs(maxA) < abs(minA))
    {
        for (int i = 1; i <= N; ++i)
        {
            if (i == minI) continue;
            ops[opnum] = OP(minI, i);
            ++opnum;
            a[i] += a[minI];
        }
        for (int i = N; i >= 2; --i)
        {
            ops[opnum] = OP(i, i-1);
            ++opnum;
            a[i-1] += a[i];
        }
    }
    else
    {
        for (int i = 1; i <= N; ++i)
        {
            if (i == maxI) continue;
            ops[opnum] = OP(maxI, i);
            ++opnum;
            a[i] += a[maxI];
        }
        for (int i = 1; i <= N-1; ++i)
        {
            ops[opnum] = OP(i, i+1);
            ++opnum;
            a[i+1] += a[i];
        }
    }

    cout << opnum << endl;
    for (int i = 0; i < opnum; ++i)
    {
        printf("%d %d\n", ops[i].x, ops[i].y);
    }

    return 0;
}
