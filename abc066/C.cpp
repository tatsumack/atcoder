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
int A[200005];

signed main()
{
    cin >> N;
    REP(i, N) cin >> A[i];

    deque<int> dq;
    REP(i, N)
    {
        if (N%2 == 0)
        {
            i%2 != 0 ? dq.push_front(A[i]) : dq.push_back(A[i]);
        }
        else
        {
            i%2 == 0 ? dq.push_front(A[i]) : dq.push_back(A[i]);
        }
    }

    int index = 0;
    for (int x : dq)
    {
        if (index != 0) printf(" ");
        printf("%lld", x);
        ++index;
    }
    printf("\n");

    return 0;
}
