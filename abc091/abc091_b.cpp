#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;

int main()
{

    int N;
    cin >> N;

    unordered_map<string, int> map;
    for (int i = 0; i < N; ++i)
    {
        string s;
        cin >> s;

        map[s] = map.find(s) != map.end() ? map[s] + 1 : 1;
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; ++i)
    {
        string s;
        cin >> s;

        if (map.find(s) != map.end())
        {
            map[s] -= 1;
        }
    }

    int ans = 0;
    auto itr = map.begin();
    auto end = map.end();
    for (; itr != end; ++itr)
    {
        ans = max(ans, map[itr->first]);
    }
    cout << ans << endl;

    return 0;
}
