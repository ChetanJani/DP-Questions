#include<bits/stdc++.h> 
using namespace std; 

//knapsack type


class Solution{   
public:
    bool isSubsetSum(vector<int>a, int sum){
        // code here
        vector <vector <int>> dp(a.size()+1,vector<int> (sum+1,0));
        for(int i=1;i<=a.size();i++){
            for(int tempsum=1;tempsum<=sum;tempsum++){
                if(a[i-1]<=tempsum){
                    dp[i][tempsum]=max(dp[i][tempsum],a[i-1]+dp[i-1][tempsum-a[i-1]]);
                }
                dp[i][tempsum]=max(dp[i][tempsum],dp[i-1][tempsum]);
            }
        }
        return dp[a.size()][sum]==sum;

        //Alternative
        // matrix
        // | 1 0 0 0 0 0 0 0 
        // | 1
        // | 1   fill here according to condition
        // | 1
        // | 1
        // vector <vector <int>> dp(a.size()+1,vector<int> (sum+1,0));
        // for(int i=0;i<=a.size();i++){
        //     dp[i][0]=1;
        // }
        // for(int i=1;i<=a.size();i++){
        //     for(int j=1;j<=sum;j++){
        //         if(a[i-1]<=j){
        //             dp[i][j]=dp[i-1][j-a[i-1]];
        //         }
        //         dp[i][j]=max(dp[i][j],dp[i-1][j]);
        //     }
        // }
        // return dp[a.size()][sum];
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
