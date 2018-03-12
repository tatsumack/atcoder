#include<iostream>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

int main()
{
    ll N;
    ll a[100];

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + N, greater<ll>());

    ll alice = 0, bob = 0;
    for (int j = 0; j < N; ++j)
    {
        if (j % 2 == 0)
        {
            alice += a[j];
        }
        else
        {
            bob += a[j];
        }
    }
    cout << alice - bob << endl;

    return 0;
}
