#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        string str1;
        string str2;
        cin >> str1;
        cin >> str2;

        if (str1.size() != str2.size())
        {
            cout << "NO" << endl;
        }
        else
        {

            vector<int> count(26, 0);
            int str_size = str1.size();
            for (int i = 0; i < str_size; i++)
            {
                count[str1[i] - 'a']++;
                count[str2[i] - 'a']--;
            }

            bool flag = true;
            for (int i = 0; i < 26; i++)
            {
                if (count[i] != 0)
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
