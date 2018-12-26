
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

int B = 0;
int R = 1;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    string s;
    cin >> s;

    vector<int> a(M), b(M);
    REP(i, M) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }

    vector<int> one(N);
    REP(i, M) {
        if (s[a[i]] == 'B') {
            one[b[i]] |= 1 << B;
        } else {
            one[b[i]] |= 1 << R;
        }
        if (s[b[i]] == 'B') {
            one[a[i]] |= 1 << B;
        } else {
            one[a[i]] |= 1 << R;
        }
    }

    vector<int> two(N);
    REP(i, M) {
        if (one[a[i]] == (1 << B)) {
            two[b[i]] |= 1 << B;
        }
        if (one[a[i]] == (1 << R)) {
            two[b[i]] |= 1 << R;
        }
        if (one[b[i]] == (1 << B)) {
            two[a[i]] |= 1 << B;
        }
        if (one[b[i]] == (1 << R)) {
            two[a[i]] |= 1 << R;
        }
    }


    bool isEven = (K % 2 == 0);
    REP(i, N) {
        if (isEven) {
            if (s[i] == 'R') {
                cout << "Second" << endl;
                continue;
            }
            if (two[i] & (1 << B)) {
                cout << "First" << endl;
            } else {
                cout << "Second" << endl;
            }
        } else {
            if (one[i] & (1 << B)) {
                cout << "First" << endl;
            } else {
                cout << "Second" << endl;
            }
        }
    }

    return 0;
}
