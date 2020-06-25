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

class ERedScarf {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> a(N);
        REP(i, N) {
            cin >> a[i];
        }

        vector<int> res(N);
        int sum = 0;
        for (int i = 0; i < N; i +=2) {
            sum ^= (a[i] ^ a[i+1]);
        }
        REP(i, N) {
            cout << (sum ^ a[i]) << " ";
        }
        cout << endl;
    }
};
