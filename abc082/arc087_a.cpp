#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;

int main()
{
    int N;
    cin >> N;

    unordered_map<int, int> map;
    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;

        if (map.find(a) != map.end())
        {
            map[a] += 1;
        }
        else
        {
            map[a] = 1;
        }
    }

    int ans = 0;
    for (auto& kv: map)
    {
        if (kv.first < kv.second) ans += kv.second - kv.first;
        if (kv.first > kv.second) ans += kv.second;
    }
    cout << ans << endl;

    return 0;
}
