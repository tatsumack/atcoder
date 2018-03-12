#include<iostream>

using namespace std;

typedef long long ll;

int main()
{
    ll N, A;
    cin >> N >> A;

    string result = N % 500 <= A ? "Yes" : "No";
    cout << result << endl;

    return 0;
}
