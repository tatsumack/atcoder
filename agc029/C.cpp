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
#define INF (LLONG_MAX - 1e5)
#define fcout cout << fixed << setprecision(10)

using namespace std;


void flat(vector<pair<int,int>>& cur) {
    if (cur.size() > 1) {
        int ll = cur.size() - 1;
        if (cur[ll].first == cur[ll-1].first) {
            cur[ll-1].second += cur[ll].second;
            cur.pop_back();
        }
    }
}

void increment(vector<pair<int,int>>& cur) {
    auto& last = cur.back();
    if (last.second > 1) {
        last.second--;
        cur.emplace_back(last.first + 1, 1);
    } else {
        last.first++;
    }
    flat(cur);
}


bool check(const vector<int>& A, int n) {
    vector<pair<int, int>> cur;
    cur.emplace_back(0, A[0]);
    FOR(i, 1, A.size() - 1) {
        if (A[i] > A[i - 1]) {
            cur.emplace_back(0, A[i] - A[i - 1]);
            flat(cur);
            continue;
        }

        int del = 0;
        while (cur.size() > 0 && A[i - 1] - (del + cur.back().second) >= A[i]) {
            del += cur.back().second;
            cur.pop_back();
        }

        cur.back().second -= A[i - 1] - A[i] - del;
        if (cur.back().first == n - 1) {
            int t = cur.back().second;
            cur.pop_back();
            if (cur.size() == 0) {
                return false;
            }
            increment(cur);
            cur.emplace_back(0, t);
        } else {
            increment(cur);
        }
        flat(cur);
    }

    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    REP(i, N) cin >> A[i];

    int l = 0;
    int r = N;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (check(A, mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;

    return 0;
}
