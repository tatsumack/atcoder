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

class C {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        string first, last;
        cin >> first >> last;
        int n;
        cin >> n;

        vector<string> v(n);
        REP(i, n) {
            cin >> v[i];
        }

        if (first == last) {
            cout << 0 << endl;
            cout << first << endl;
            cout << last << endl;
            return;
        }
        v.push_back(first);
        v.push_back(last);
        int firstIdx = n;
        int lastIdx = n + 1;
        n += 2;

        vector<vector<int>> G(n);
        REP(i, n) {
            string s = v[i];
            FOR(j, i + 1, n - 1) {
                string t = v[j];
                int cnt = 0;
                REP(k, s.size()) {
                    if (s[k] != t[k]) cnt++;
                }
                if (cnt == 1) {
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
            }
        }

        queue<int> q;
        vector<bool> used(n);
        vector<int> prev(n, -1);
        q.push(firstIdx);
        used[firstIdx] = true;

        while (!q.empty()) {
            int from = q.front();
            q.pop();
            for(auto to : G[from]) {
                if (used[to]) continue;
                used[to] = true;
                q.push(to);
                prev[to] = from;
            }
        }

        if (prev[lastIdx] == -1) {
            cout << -1 << endl;
            return;
        }

        vector<int> resv;
        int cur = prev[lastIdx];
        while (prev[cur] >= 0) {
            resv.push_back(cur);
            cur = prev[cur];
        }
        reverse(resv.begin(), resv.end());

        cout << resv.size() << endl;
        cout << first << endl;
        REP(i, resv.size()) {
            cout << v[resv[i]] << endl;
        }
        cout << last << endl;


    }
};
