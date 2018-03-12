#include<iostream>

using namespace std;
typedef long long ll;

int main()
{

    ll N, K;
    cin >> N >> K;

    ll result = 0;
    for (int i = K+1; i <= N; ++i)
    {
        result += (N / i) * (i - K);
        if (N % i >= K) result += N % i - K + 1;
    }
    if (K == 0) result -= N;
    cout << result << endl;

    return 0;
}

