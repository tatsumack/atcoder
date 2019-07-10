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

    string origin = "abcdefghijklmnopqrstuvwxyz";

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;

        vector<vector<int>> G(26);
        map<int, int> in;
        REP(i, N) {
            string a, b;
            cin >> a >> b;
            int j = 0;
            while (j < a.size() && j < b.size()) {
                if (a[j] != b[j]) break;
                j++;
            }
            if (j >= a.size() || j >= b.size()) {
                if (a.size() > b.size()) {
                    cout << -1 << endl;
                    return;
                }
                continue;
            }
            char s = a[j];
            char t = b[j];
            G[s - 'a'].push_back(t - 'a');
            in[t - 'a']++;
        }

        priority_queue<int, vector<int>, greater<int>> q;
        REP(i, 26) {
            if (in[i] == 0) q.push(i);
        }

        string res;
        while (!q.empty()) {
            int t = q.top();
            q.pop();
            res += 'a' + t;
            REP(i, G[t].size()) {
                in[G[t][i]]--;
                if (in[G[t][i]] == 0) {
                    q.push(G[t][i]);
                }
            }
        }

        if (res.size() != 26) {
            cout << -1 << endl;
            return;
        }
        cout << res << endl;
    }
};
