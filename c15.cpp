#include <iostream>
#include <vector>
using namespace std;
int fib(int n, int dp[])
{
    if (n <= 1)
        return dp[n] = 1;

    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

int countWays(int n)
{
    int dp[n + 1];
    for (int i=0;i<n+1;i++)
    {
        dp[i] = -1;  
    }
    dp[1] =1 ;
    dp[0] = 1;
    fib(n, dp);
    return dp[n];
}

int main()
{
    cout<< (countWays(7));
    return 0;
}