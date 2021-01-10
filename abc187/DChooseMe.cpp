#include <bits/stdc++.h>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> P;

class DChooseMe {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<pair<int, int>> v(N);
        int suma = 0;
        REP(i, N) {
            int a, b;
            cin >> a >> b;
            v[i] = {a, b};
            suma += a;
        }
        sort(v.begin(), v.end(), [](auto const& lhs, auto const& rhs) {
            return lhs.first * 2 + lhs.second > rhs.first * 2 + rhs.second;
        });
        int res = 0;
        int cur = 0;
        REP(i, N) {
            res++;
            cur += v[i].first + v[i].second;
            suma -= v[i].first;
            if (cur > suma) {
                break;
            }
        }
        cout << res << endl;
    }
};
