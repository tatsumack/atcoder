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

class EActiveInfants {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> A(N);
        REP(i, N) cin >> A[i];

        int l = 0;
        int r = N - 1;
        priority_queue<pair<int, int>> pq;
        set<int> used;
        while (r >= l) {
            REP(i, N) {
                if (used.count(i)) continue;
                pq.push({A[i] * max(abs(i - l), abs(i-r)), i});
            }
            auto kv = pq.top();


        }

    }
};
