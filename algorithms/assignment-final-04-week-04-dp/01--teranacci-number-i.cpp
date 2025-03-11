#include <bits/stdc++.h>
using namespace std;

int recursion(int n) 
{
    if (n == 0) return 0;
    if (n <= 2) return 1;
    if (n == 3) return 2;
    
    return recursion(n-1) 
         + recursion(n-2) 
         + recursion(n-3) 
         + recursion(n-4);
}

int main() 
{
    int val; 
    cin >> val;
    
    int result = recursion(val);
    
    cout << result << endl;
    
    return 0;
}
