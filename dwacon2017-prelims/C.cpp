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
#include <queue>
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
#define INF (LLONG_MAX - 1e5)

using namespace std;

int N, A[100005];
bool used[100005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    queue<int> q1, q2, q3;
    REP(i, N) {
        cin >> A[i];
        switch (A[i]) {
            case 3:
                q3.push(i);
                break;
            case 2:
                q2.push(i);
                break;
            case 1:
                q1.push(i);
                break;
        }
    }

    int ans = 0;
    REP(i, N) {
        if (used[i]) continue;
        ans++;
        used[i] = true;
        int res = 4 - A[i];
        while (res >= 3 && !q3.empty()) {
            while (!q3.empty() && used[q3.front()])
                q3.pop();
            if (q3.empty()) break;
            int j = q3.front();
            q3.pop();
            used[j] = true;
            res -= 3;
        }
        while (res >= 2 && !q2.empty()) {
            while (!q2.empty() && used[q2.front()])
                q2.pop();
            if (q2.empty()) break;
            int j = q2.front();
            q2.pop();
            used[j] = true;
            res -= 2;
        }
        while (res >= 1 && !q1.empty()) {
            while (!q1.empty() && used[q1.front()])
                q1.pop();
            if (q1.empty()) break;
            int j = q1.front();
            q1.pop();
            used[j] = true;
            res -= 1;
        }
    }
    cout << ans << endl;
    return 0;
}
