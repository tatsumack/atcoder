#include<iostream>
#include <unordered_set>

using namespace std;

int main()
{
    int N;
    cin >> N;

    unordered_set<char> arareSet;
    for (int i = 0; i < N; ++i)
    {
        char c;
        cin >> c;
        arareSet.insert(c);
    }

    const char* result = arareSet.size() == 4 ? "Four" : "Three";
    cout << result << endl;

    return 0;
}
