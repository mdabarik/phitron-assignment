#include <iostream>
#include <climits>
using namespace std;

int nums[100005];

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        int l = 0, r = n - 1;
        int maxH = INT_MIN;
        int lIdx = 0, rIdx = 0;

        while (l < r)
        {
            int minH = min(nums[l], nums[r]);

            if (maxH < minH)
            {
                maxH = minH;
                lIdx = l;
                rIdx = r;
            }

            if (nums[l] < nums[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }

        cout << lIdx << " " << rIdx << endl;
    }

    return 0;
}
