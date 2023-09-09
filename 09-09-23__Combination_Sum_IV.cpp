class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned> dp(target+1, UINT_MAX);

        function<unsigned(unsigned)> f=[&](unsigned i)->unsigned
        {
            if (i==0) return 1;//base case
            if (dp[i]!=UINT_MAX) return dp[i];//Computed before
            unsigned ans=0;
        //Everything can be chosen, for permutations with repetition
            for(int x: nums)
                if (i>=x)
                    ans+=f(i-x);//Recursion
            return dp[i]=ans; //Copy to dp array & return ans

        };
        
        return f(target);
    }
};