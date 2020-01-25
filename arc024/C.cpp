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
    void solve(std::istream& cin, std::ostream& cout) {
        int N, K;
        cin >> N >> K;
        string s;
        cin >> s;

        vector<int> cnt(26);
        set<vector<int>> found;
        REP(i, K - 1) {
            cnt[s[i] - 'a']++;
        }

        queue<vector<int>> q;
        FOR(i, K - 1, N - 1) {
            cnt[s[i] - 'a']++;
            if (found.count(cnt)) {
                cout << "YES" << endl;
                return;
            }
            q.push(cnt);
            if (q.size() == K) {
                found.insert(q.front());
                q.pop();
            }
            cnt[s[i - (K - 1)] - 'a']--;
        }

        cout << "NO" << endl;
    }
};
