#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    string S;
    cin >> S;
    int n = S.size();
    int ans = n;
    for (int k = 0; k+1 < n; ++k)
    {
        if (S[k] != S[k+1])
            ans = min(ans, max(k+1, n - (k+1)));
    }
    cout << ans << endl;

    return 0;
}
