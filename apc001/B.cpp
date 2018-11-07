
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> a(N);
    vector<int> b(N);
    int suma = 0;
    REP(i, N) {
        cin >> a[i];
        suma += a[i];
    }
    int sumb = 0;
    REP(i, N) {
        cin >> b[i];
        sumb += b[i];
    }

    if (suma > sumb) {
        cout << "No" << endl;
        return 0;
    }

    int num = sumb - suma;
    int one = 0;
    int two = 0;
    REP(i, N) {
        if (a[i] > b[i]) {
            one += a[i] - b[i];
        } else if (a[i] < b[i]) {
            two += (b[i] - a[i] + 1) / 2;
        }
    }
    cout << (one <= num && two <= num ? "Yes" : "No") << endl;

    return 0;
}
