// https://leetcode.com/problems/target-sum/

class Solution {
public:
    int dp[20][4001];
    int findTargetSumWays(vector<int>& nums, int t) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return rec(0, t, nums);
    }

    int rec(int i, int j, vector<int>& nums) {
        int k=j+2000;
        if(dp[i][k]!=-1) {
            printf("ba   %d  %d  %d\n",i,j,dp[i][k]);
            return dp[i][k];
        }
        dp[i][k]=0;
        int n=nums.size();
        if(i==n-1) {
            if(nums[i]==0) {
                dp[i][k]= j==0 ? 2: 0;
            } else
                dp[i][k]=(nums[i]==j || nums[i]==-j ? 1:0);
            printf("n-1   %d  %d  %d\n",i,j,dp[i][k]);
            return dp[i][k];
        }
        dp[i][k]+=rec(i+1,j-nums[i],nums);
        dp[i][k]+=rec(i+1,j+nums[i],nums);
        printf("fi   %d  %d  %d\n",i,j,dp[i][k]);
        return dp[i][k];
    }
};
