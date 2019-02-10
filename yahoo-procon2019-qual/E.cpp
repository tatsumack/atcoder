
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(10)

using namespace std;

typedef pair<int, int> P;
typedef vector<int> Vec;
typedef vector<Vec> Mat;

int N, M;
int mod = 998244353;

int Gauss(Mat& A) {
    int rank = 0;

    REP(j, M) {
        int pivot = -1;
        FOR(i, rank, N - 1) {
            if (A[i][j] == 1) {
                pivot = i;
                break;
            }
        }
        if (pivot == -1) continue;
        swap(A[rank], A[pivot]);
        REP(i, N) {
            if (i == rank) continue;
            if (A[i][j] == 0) continue;
            REP(k, M) {
                A[i][k] ^= A[rank][k];
            }
        }
        ++rank;
    }
    return rank;
}

int binpow(int x, int p) {
    if (p == 0) return 1;

    if (p % 2 == 0)
        return binpow((x * x) % mod, p / 2);
    else
        return (x * binpow(x, p - 1)) % mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;

    Mat A(N, Vec(M));
    REP(i, N) REP(j, M) cin >> A[i][j];

    int rank = Gauss(A);
    cout << (binpow(2, N + M - 1) - binpow(2, N + M - rank - 1) + mod) % mod << endl;

    return 0;
}
