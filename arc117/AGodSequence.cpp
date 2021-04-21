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

class AGodSequence {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int A, B;
        cin >> A >> B;
        if (A > B) {
            REP(i, A) {
                cout << i + 1 << " ";
            }
            int num = A / B;
            REP(i, B) {
                int l = num * i + 1;
                int r = l + num;
                int val = 0;
                while (l < r) {
                    val += l;
                    l++;
                }
                if (i == B - 1) {
                    while (l <= A) {
                        val += l;
                        l++;
                    }
                }
                cout << -val << " ";
            }
        } else if (A < B) {
            REP(i, B) {
                cout << -(i + 1) << " ";
            }
            int num = B / A;
            REP(i, A) {
                int l = num * i + 1;
                int r = l + num;
                int val = 0;
                while (l < r) {
                    val += l;
                    l++;
                }
                if (i == A - 1) {
                    while (l <= B) {
                        val += l;
                        l++;
                    }
                }
                cout << val << " ";
            }
        } else {
            REP(i, A) {
                cout << i + 1 << " ";
            }
            REP(i, B) {
                cout << -(i + 1) << " ";
            }
        }
    }
};
