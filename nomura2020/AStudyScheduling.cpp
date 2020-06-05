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

class AStudyScheduling {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int H1, M1, H2, M2, K;
        cin >> H1 >> M1 >> H2 >> M2 >> K;

        int difm = 0;
        if (H2 == H1) {
            difm = M2 - M1;
        } else {
            difm = 60 - M1 + M2 + (H2-H1-1) * 60;
        }
        if (difm <= K) {
            cout << 0 << endl;
            return;
        }

        int H3 = K / 60;
        int M3 = K % 60;
        H2 -= H3;
        M2 -= M3;
        if (M2 < 0) {
            M2 += 60;
            H2--;
        }
        if (H2 == H1) {
            difm = M2 - M1;
        } else {
            difm = 60 - M1 + M2 + (H2-H1-1) * 60;
        }
        cout << difm << endl;
    }
};
