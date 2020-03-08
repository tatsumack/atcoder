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

class DStringFormation {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        string s;
        cin >> s;
        deque<char> deq;
        for (auto c : s) deq.push_back(c);
        int Q;
        cin >> Q;
        int front = 0;
        while (Q--) {
            int t;
            cin >> t;
            if (t == 1) {
                front ^= 1;
            } else {
                int f;
                char c;
                cin >> f >> c;
                if (f == 1) {
                    if (front == 0) {
                        deq.push_front(c);
                    } else {
                        deq.push_back(c);
                    }
                } else {
                    if (front == 0) {
                        deq.push_back(c);
                    } else {
                        deq.push_front(c);
                    }
                }
            }
        }
        string res;
        while (!deq.empty()) {
            if (front == 0) {
                res += deq.front();
                deq.pop_front();
            } else {
                res += deq.back();
                deq.pop_back();
            }
        }
        cout << res << endl;
    }
};
