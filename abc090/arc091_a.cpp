#include<iostream>

using namespace std;

int main()
{

    unsigned long long N, M;
    cin >> N >> M;

    unsigned long long result = 0;

    if (N >= 2 && M >= 2)
    {
        result = (N - 2) * (M - 2);
    }

    if (N == 1 && M > 1)
    {
        result = M - 2;
    }
    if (M == 1 && N > 1)
    {
        result = N - 2;
    }

    if (N == 1 && M == 1)
    {
        result = 1;
    }

    cout << result << endl;

    return 0;
}
