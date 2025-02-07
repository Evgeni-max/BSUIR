#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long swapCount(string s)
{
    
    vector<int> pos;
    for (int i = 0; i < s.length(); ++i)
        if (s[i] == '(')
            pos.push_back(i);

    int count = 0; 
    int p = 0; 
    long sum = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '(')
        {
            ++count;
            ++p;
        }
        else if (s[i] == ')')
            --count;

        
        if (count < 0)
        {

            sum += pos[p] - i;
            swap(s[i], s[pos[p]]);
            ++p;

            count = 1;
        }
    }
    return sum;
}


int main()
{
    int n;
    cin >> n;

    string str;

    for (int i = 0; i < n; ++i) {
        cin >> str;
        cout << swapCount(str) << "\n";
    }
    return 0;
}

