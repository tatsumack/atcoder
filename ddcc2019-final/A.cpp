
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

typedef pair<int, int> P;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    string s;
    cin >> s;

    vector<double> sum(N + 1);
    vector<int> knum(N + 1);
    int k = 0;
    REP(i, s.size()) {
        char c = s[i];
        if (c == '>') {
            sum[i + 1] = sum[i] + 1.0f / (k + 2);
            knum[i] = k;
            k++;
        } else {
            sum[i + 1] = sum[i] + 1;
            k = 0;
            knum[i] = k;
        }
    }

    double ans = INF;
    REP(i, s.size()) {
        char c = s[i];
        if (c == '>') continue;

        int l = i;

        int k = l > 0 ? knum[l - 1] : 0;

        double tmp = 1.0f / (2 + k);
        while (i + 1 < N && s[i + 1] == '>') {
            k++;
            tmp += 1.0f / (2 + k);
            i++;
        }
        ans = min(ans, sum[l] + tmp + (sum[N] - sum[i + 1]));
    }

    fcout << ans << endl;

    return 0;
}
