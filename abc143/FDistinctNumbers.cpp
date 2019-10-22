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

class FDistinctNumbers {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int N;
    vector<int> cnt, sum;

    bool check(int k, int n) {
        if (k * n > N) return false;

        int idx = lower_bound(cnt.begin(), cnt.end(), n) - cnt.begin();

        int num = ((int)cnt.size() - idx) * n;
        num += sum[idx];
        return num >= k * n;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> N;
        vector<int> A(N);
        map<int, int> mp;
        REP(i, N) {
            cin >> A[i];
            mp[A[i]]++;
        }
        for (auto kv : mp) {
            cnt.push_back(kv.second);
        }
        sort(cnt.begin(), cnt.end());
        sum = vector<int>(cnt.size() + 1, 0);
        REP(i, cnt.size()) {
            sum[i+1] = sum[i] + cnt[i];
        }

        FOR(k, 1, N) {
            int l = 0;
            int r = N + 1;
            while (r - l > 1) {
                int m = (r + l) / 2;
                if (check(k, m)) {
                    l = m;
                } else {
                    r = m;
                }
            }
            cout << l << endl;
        }
    }
};
