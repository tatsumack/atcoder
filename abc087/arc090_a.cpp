#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    int N;
    int A1[101] = {};
    int A2[101] = {};

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int a;
        cin >> a;
        A1[i] = A1[i-1] + a;
    }
    for (int i = 1; i <= N; ++i)
    {
        int a;
        cin >> a;
        A2[i] = A2[i-1] + a;
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        int cnum = A1[i] + (A2[N] - A2[i-1]);
        ans = max(ans, cnum);
    }

    cout << ans << endl;

    return 0;
}

