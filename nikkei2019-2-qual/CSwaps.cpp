#include <iostream>
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
#include <unordered_map>
#include <unordered_set>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> P;

class CSwaps {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        REP(i, n) cin >> a[i];
        REP(i, n) cin >> b[i];

        vector<P> sorta(n), sortb(n);
        REP(i, n) sorta[i] = {a[i], i};
        REP(i, n) sortb[i] = {b[i], i};
        sort(sorta.begin(), sorta.end());
        sort(sortb.begin(), sortb.end());

        bool ok = true;
        REP(i, n) {
            if (sorta[i].first > sortb[i].first) ok = false;
        }
        if (!ok) {
            cout << "No" << endl;
            return;
        }
        map<int, int> pos;
        REP(i, n) {
            pos[sorta[i].second] = sortb[i].second;
        }

        set<int> found;
        int cur = 0;
        while (!found.count(cur)) {
            found.insert(cur);
            cur = pos[cur];
        }

        if (found.size() < n) {
            cout << "Yes" << endl;
            return;
        }

        ok = false;
        REP(i, n - 1) {
            if (sorta[i + 1].first <= sortb[i].first) ok = true;
        }
        if (ok) {
            cout << "Yes" << endl;
            return;
        } else {
            cout << "No" << endl;
        }
    }
};
