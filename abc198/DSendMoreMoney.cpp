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

class DSendMoreMoney {
public:
    string cand = "0123456789";
    map<char, int> id;
    string s1, s2, s3;

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> s1 >> s2 >> s3;
        if (s3.size() < s1.size() || s3.size() < s2.size()) {
            cout << "UNSOLVABLE" << endl;
            return;
        }
        set<char> s;
        REP(i, s1.size()) s.insert(s1[i]);
        REP(i, s2.size()) s.insert(s2[i]);
        REP(i, s3.size()) s.insert(s3[i]);
        if (s.size() > 10) {
            cout << "UNSOLVABLE" << endl;
            return;
        }

        int cur = 0;
        for (auto c : s) {
            id[c] = cur++;
        }

        vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int val1, val2, val3;
        bool ok = false;
        do {
            if (v[id[s1[0]]] == 0) continue;
            if (v[id[s2[0]]] == 0) continue;
            if (v[id[s3[0]]] == 0) continue;
            val1 = 0;
            REP(i, s1.size()) {
                val1 *= 10;
                val1 += v[id[s1[i]]];
            }
            val2 = 0;
            REP(i, s2.size()) {
                val2 *= 10;
                val2 += v[id[s2[i]]];
            }
            val3 = 0;
            REP(i, s3.size()) {
                val3 *= 10;
                val3 += v[id[s3[i]]];
            }
            if (val1 + val2 == val3) {
                ok = true;
                break;
            }
        } while (std::next_permutation(v.begin(), v.end()));
        if (!ok) {
            cout << "UNSOLVABLE" << endl;
            return;
        }
        cout << val1 << endl;
        cout << val2 << endl;
        cout << val3 << endl;
    }

};
