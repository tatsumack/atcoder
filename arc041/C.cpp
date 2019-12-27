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

    int calc(vector<int>& vr, vector<int>& vl) {
        int p;
        int res = 0;
        if (vr.size() > vl.size()) {
            p = vl.front();
        } else {
            p = vr.back();
        }
        int cur = 0;
        REP(j, vr.size()) {
            if (p == vr[j]) continue;
            res += p - vr[j] - 1 - cur;
            cur++;
        }
        cur = 0;
        REP(j, vl.size()) {
            if (p == vl[j]) continue;
            res += vl[j] - p - 1 - cur;
            cur++;
        }
        return res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N, L;
        cin >> N >> L;

        vector<pair<int, char>> v(N);
        REP(i, N) {
            int x;
            char d;
            cin >> x >> d;
            v[i] = {x, d};
        }

        int res = 0;
        int l = N;
        // 左から左向きをカウント
        REP(i, N) {
            if (v[i].second == 'R') {
                l = i;
                break;
            }
            res += v[i].first - (i + 1);
        }
        // 右から右向きをカウント
        int r = -1;
        REV(i, N - 1, 0) {
            if (v[i].second == 'L') {
                r = i;
                break;
            }
            res += L - v[i].first - (N - 1 - i);
        }

        // 向かい合ってるやつたち
        vector<int> vr;
        vector<int> vl;
        FOR(i, l, r) {
            if (v[i].second == 'R') {
                if (vl.empty()) {
                    vr.push_back(v[i].first);
                } else {
                    res += calc(vr, vl);
                    vl.clear();
                    vr.clear();
                    vr.push_back(v[i].first);
                }
            }
            if (v[i].second == 'L') {
                vl.push_back(v[i].first);
            }
        }
        if (!vr.empty() && !vl.empty()) {
            res += calc(vr, vl);
        }
        cout << res << endl;
    }
};
