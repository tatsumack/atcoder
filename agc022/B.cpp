
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

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    if (N == 3) {
        cout << "2 5 63" << endl;
        return 0;
    }
    if (N == 4) {
        cout << "2 5 20 63" << endl;
        return 0;
    }

    vector<int> two;
    vector<int> three;
    vector<int> six;
    FOR(i, 1, 30000) {
        if (i % 6 == 0) continue;
        if (i % 2 == 0) {
            two.push_back(i);
        }
    }
    FOR(i, 1, 30000) {
        if (i % 6 == 0) continue;
        if (i % 3 == 0) {
            three.push_back(i);
        }
    }
    FOR(i, 1, 30000) {
        if (i % 6 == 0) {
            six.push_back(i);
        }
    }

    vector<int> ans;

    int cnt = 0;
    for (int i = 0; i < two.size(); i += 2) {
        ans.push_back(two[i]);
        ans.push_back(two[i + 1]);
        cnt += 2;
        if (cnt + 2 >= N - 2) break;
    }
    for (int i = 0; i < three.size(); i += 2) {
        ans.push_back(three[i]);
        ans.push_back(three[i + 1]);
        cnt += 2;
        if (cnt + 2 > N) break;
    }
    REP(i, six.size()) {
        if (cnt == N) {
            break;
        }
        ans.push_back(six[i]);
        cnt++;
    }
    sort(ans.begin(), ans.end());

    REP(i, ans.size()) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
