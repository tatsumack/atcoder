#include<iostream>
#include <unordered_set>

using namespace std;

int main()
{

    string result = "";
    for (int i = 0; i < 3; ++i)
    {
        string s;
        cin >> s;
        result += s[i];
    }

    cout << result << endl;

    return 0;
}
