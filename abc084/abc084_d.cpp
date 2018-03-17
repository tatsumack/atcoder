#include <iostream>
#include <complex>


using namespace std;

typedef long long ll;

#define NMAX 100001

bool is_prime[NMAX];
int pnum[NMAX] = {};

int main()
{
    int Q;
    cin >> Q;

    for (int i = 0; i < NMAX; ++i) is_prime[i] = true;
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i < NMAX; ++i)
    {
        if (is_prime[i])
        {
            for (int j = 2*i; j < NMAX; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i < NMAX; ++i)
    {
        pnum[i] = pnum[i-1];
        if (is_prime[i] && is_prime[(i+1)/2]) ++pnum[i];
    }

    for (int i = 0; i < Q; ++i)
    {
        int l, r;
        cin >> l >> r;
        cout << pnum[r] - pnum[l-1] << endl;
    }

    return 0;
}
