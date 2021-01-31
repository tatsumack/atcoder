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

class ERotateAndFlip {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int N, M, Q;
        cin >> N;
        vector<int> X(N), Y(N);
        REP(i, N) cin >> X[i] >> Y[i];
        cin >> M;
        vector<int> first(3), second(3);
        first[0] = 1;
        second[1] = 1;
        vector<vector<int>> fv(M + 1), sv(M + 1);
        fv[0] = first;
        sv[0] = second;
        REP(i, M) {
            int t, p;
            cin >> t;
            if (t == 1) {
                swap(first, second);
                REP(j, 3) {
                    second[j] *= -1;
                }
            }
            if (t == 2) {
                swap(first, second);
                REP(j, 3) {
                    first[j] *= -1;
                }
            }
            if (t == 3) {
                cin >> p;
                REP(j, 3) {
                    first[j] *= -1;
                }
                first[2] += 2 * p;
            }
            if (t == 4) {
                cin >> p;
                REP(j, 3) {
                    second[j] *= -1;
                }
                second[2] += 2 * p;
            }
            fv[i + 1] = first;
            sv[i + 1] = second;
        }
        cin >> Q;
        REP(i, Q) {
            int a, b;
            cin >> a >> b;
            b--;
            int x = fv[a][0] * X[b] + fv[a][1] * Y[b] + fv[a][2];
            int y = sv[a][0] * X[b] + sv[a][1] * Y[b] + sv[a][2];
            cout << x << " " << y << endl;
        }
    }

};
