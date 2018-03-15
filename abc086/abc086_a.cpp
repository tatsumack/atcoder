#include <iostream>

using namespace std;


int main()
{
    int a, b;
    cin >> a >> b;
    string ans = (a*b) % 2 == 0 ? "Even" : "Odd";
    cout << ans << endl;

    return 0;
}
