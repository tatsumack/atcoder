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

class DLunlunNumber {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int K;
        cin >> K;

        vector<int> res;
        res.push_back(0);
        REP(i, K) {
            int j = 0;
            while (j + 1 < res.size() && (res[j] > res[j + 1] || res[j] == 9)) j++;
            if (j == res.size() - 1) {
                if (res[j] == 9) {
                    REP(k, res.size()) res[k] = 0;
                    res.push_back(1);
                } else {
                    int val = res[j] + 1;
                    while (j >= 0) {
                        res[j] = val >= 0 ? val : 0;
                        val--;
                        j--;
                    }
                }
            } else {
                int val = res[j] + 1;
                while (j >= 0) {
                    res[j] = val >= 0 ? val : 0;
                    val--;
                    j--;
                }
            }
        }
        reverse(res.begin(), res.end());
        for (auto n : res) cout << n;
        cout << endl;
    }
};
