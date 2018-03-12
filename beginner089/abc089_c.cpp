#include<iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int N;
    cin >> N;

    unordered_map<char, long long> charMap;
    for (int i = 0; i < N; ++i)
    {
        string s;
        cin >> s;
        char c = s[0];
        switch (c)
        {
            case 'M':
            case 'A':
            case 'R':
            case 'C':
            case 'H':
                if (charMap.find(c) != charMap.end())
                {
                    charMap[c]++;
                }
                else
                {
                    charMap[c] = 1;
                }
                break;
            default:
                break;
        }
    }

    long long result = 0;
    string target = "MARCH";
    for (int i = 0; i < target.size(); ++i)
    {
        if (charMap.find(target[i]) == charMap.end()) continue;
        for (int j = i + 1; j < target.size(); ++j)
        {
            if (charMap.find(target[j]) == charMap.end()) continue;
            for (int k = j + 1; k < target.size(); ++k)
            {
                if (charMap.find(target[k]) == charMap.end()) continue;
                result += charMap[target[i]] * charMap[target[j]] * charMap[target[k]];
            }
        }
    }
    cout << result << endl;

    return 0;
}
