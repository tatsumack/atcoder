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

class ETree {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        string s;
        cin >> s;
        if (s.front() == '0' || s.back() == '1') {
            cout << -1 << endl;
            return;
        }

        int n = s.size();

        int l = 0;
        int r = n - 2;
        bool ok = true;
        while (l <= r) {
            if (s[l] != s[r]) {
                ok = false;
                break;
            }
            l++;
            r--;
        }

        if (!ok) {
            cout << -1 << endl;
            return;
        }

        vector<int> par(n);
        int last = n - 1;
        REV(i, n - 1, 0) {
            par[i] = last;
            if (s[i] == '1') {
                last = i;
            }
        }

        REP(i, n - 1) {
            cout << i + 1 << " " << par[i] + 1 << endl;
        }
    }
};
