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

class FContrast {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> A(N), B(N);
        REP(i, N) cin >> A[i] >> B[i];
        map<int, int> cnt;
        REP(i, N) {
            if (A[i] == B[i]) cnt[A[i]]++;
        }

        int num = 0;
        vector<pair<int, int>> v;
        for (auto kv: cnt) {
            num = max(num, kv.second);
            v.push_back({-kv.second, kv.first});
        }
        if (num >= N / 2 + 1) {
            cout << "No" << endl;
            return;
        }

        sort(v.begin(), v.end());
        auto t = v;
        map<int, vector<pair<int, int>>> m;
        int j = 1;
        REP(i, N) v[i].first *= -1;
        REP(i, N) t[i].first *= -1;
        REP(i, v.size()) {
            while (v[i].first > 0 && j < v.size()) {
                if (v[i].first >= t[j].first) {
                    m[t[j].second].push_back({v[i].second, t[j].first});
                    v[i].first -= t[j].first;
                    j++;
                } else {
                    m[t[j].second].push_back({v[i].second, v[i].first});
                    v[i].first = 0;
                    t[j].first -= v[i].first;
                }
            }
        }



    }
};
