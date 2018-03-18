#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    string ans = A + B >= C ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}
