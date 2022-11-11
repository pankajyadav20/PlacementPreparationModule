//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int fun(int i , int j , string &s1 , string &s2 , vector<vector<int>> &dp){
        if(i == 0 && j == 0){
            return s1[0] == s2[0];
        }
        if(i < 0 || j <  0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i] == s2[j]){
            return  dp[i][j] = 1 + fun( i - 1, j -  1, s1 , s2 , dp);
        }
        
        else return dp[i][j] = max( fun( i - 1,  j , s1 ,s2 , dp) , fun ( i ,j - 1 , s1 ,s2,dp ));
        
    }
    int lcs(int x, int y, string s1, string s2){
        // your code here
        vector<vector<int>> dp( x , vector<int>( y , -1 ));
        return fun(x - 1, y - 1, s1 ,s2 , dp);
    }
};





//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends