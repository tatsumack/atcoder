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

#define int long long

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define REV(i, a) for (int i = (a); i >= 0; --i)
#define CLR(a) memset((a), 0, sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

int N;
string S;

int A[100005];  // 1: S, 2: W

void solve() {
    REP(i, N) {
        char c = S[i];
        int n1 = i > 0 ? i - 1 : N - 1;  // 隣1
        int n2 = i < N - 1 ? i + 1 : 0;  // 隣2

        if (c == 'o') {
            if (A[i] == 1) {
                A[n2] = A[n1];
            } else {
                A[n2] = A[n1] == 1 ? 2 : 1;
            }
        } else {
            if (A[i] == 1) {
                A[n2] = A[n1] == 1 ? 2 : 1;
            } else {
                A[n2] = A[n1];
            }
        }
    }
}

void output() {
    REP(i, N) {
        if (A[i] == 1) {
            cout << "S";
        } else {
            cout << "W";
        }
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> S;
    CLR(A);

    A[0] = 1;
    A[N - 1] = 1;
    solve();
    if (A[0] == 1 && A[N - 1] == 1) {
        output();
        return 0;
    }

    A[0] = 1;
    A[N - 1] = 2;
    solve();
    if (A[0] == 1 && A[N - 1] == 2) {
        output();
        return 0;
    }

    A[0] = 2;
    A[N - 1] = 1;
    solve();
    if (A[0] == 2 && A[N - 1] == 1) {
        output();
        return 0;
    }

    A[0] = 2;
    A[N - 1] = 2;
    solve();
    if (A[0] == 2 && A[N - 1] == 2) {
        output();
        return 0;
    }

    cout << -1 << endl;

    return 0;
}
