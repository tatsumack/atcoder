#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

#define int long long

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define FOR(i,a,b) for(int i=(a), i##_len=(b);i< i##_len; ++i)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

int N;

int prime[300005];
bool is_prime[300015];

int sieve(int n)
{
    int p = 0;
    REP(i, n) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            prime[p++] = i;
            for (int j = 2*i; j <= n; j+=i) is_prime[j] = false;
        }
    }
    return p;
}

signed main()
{
    cin >> N;
    sieve(300000);

    int index = 0;
    REP(i, N)
    {
        if (i != 0) cout << " ";
        while (prime[index] % 5 != 1) ++index;
        cout << prime[index];
        ++index;
    }
    cout << endl;

    return 0;
}
