#include<bits/stdc++.h>
using namespace std;
int ar[100005]={},dp[100005][2]={};
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,i,j;
        cin >> n;
        for(i=0; i<n; i++)
            cin >> ar[i];
        for(i=0; i<n-1; i++)
        {
            dp[i+1][0]=max(dp[i][0],dp[i][1]+abs(ar[i]-1));
			printf("S1: dp[%d][0] = %d, dp[%d][1]+abs(ar[%d]-1) = %d, final: dp[%d][0] = %d\n", i, dp[i][0], i, i, dp[i][1]+abs(ar[i]-1), i+1, dp[i+1][0]);
            dp[i+1][1]=max(dp[i][0]+abs(ar[i+1]-1),dp[i][1]+abs(ar[i]-ar[i+1]));
			printf("\tS2: dp[%d][0]+abs(ar[%d]-1) = %d dp[%d][1]+abs[ar[%d]-ar[%d] = %d final dp[%d][1]: %d\n",i, i+1, dp[i][0]+abs(ar[i+1]-1),i, i, i+1, dp[i][1]+abs(ar[i]-ar[i+1]), i+1, dp[i+1][1]);
        }
        cout << max(dp[n-1][0],dp[n-1][1]) << endl;
    }
    return 0;
}
