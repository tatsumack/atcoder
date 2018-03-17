#include <iostream>

using namespace std;

typedef long long ll;

int C[501];
int S[501];
int F[501];


int main()
{
    int N;
    cin >> N;
    for (int i = 1; i < N; ++i)
    {
        cin >> C[i] >> S[i] >> F[i];
    }

    for (int i = 1; i < N; ++i)
    {
        int t = S[i] + C[i];
        for (int j = i+1; j < N; ++j)
        {
            if (t > S[j])
            {
                int tmp = (t - S[j]) % F[j];
                t += tmp == 0 ? 0 : F[j] - tmp;
            }
            else
            {
                t = S[j];
            }
            t += C[j];
        }
        cout << t << endl;
    }
    cout << 0 << endl;

    return 0;
}
