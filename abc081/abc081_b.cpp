#include <iostream>

using namespace std;

typedef long long ll;

int A[201];

#define INF 10000

int main()
{
    int N;
    cin >> N;

    int ans = INF;
    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;

        int cnt = 0;
        while (a % 2 == 0) a /= 2, ++cnt;
        ans = min(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}
