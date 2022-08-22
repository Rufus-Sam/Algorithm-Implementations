// Leetcode problem of burst balloons

class Solution {
public:
   
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        int n = nums.size();
        int dp[305][305] = {0};
        
        function<int(int,int)>dfs;
        //[&] => capture outside variable by reference
        //[=] => capture outside variable by value
        dfs = [&](int l,int r){
            
            if(l>r) return 0;
            if(dp[l][r]>0) return dp[l][r];
            int res=0;
            
            for(int i=l;i<=r;i++){
                int curr = nums[l-1]*nums[i]*nums[r+1]; //  [3,1,  5  ,4] => 1[5]1 = l,r ; l-1 = 1;r+1=1;
                int rem = dfs(l,i-1) + dfs(i+1,r);      //   ___       __ =>these two are sub probs and 5 will be burst last
                res = max(res,curr+rem);
            }
            
            dp[l][r] = res;
            return res;
        };
        return dfs(1,n-2);
    }
};