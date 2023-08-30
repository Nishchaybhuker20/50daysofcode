class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long op=0;
        int last=nums.back();
        for(int i=nums.size()-2; i>=0; i--){
            auto [q, r]=div(nums[i], last);
            if (q==0){
                last=r;
            }
            else if (r==0){ 
                op+=(q-1);
            }
            else{
                op+=q;
                last-=(last-r+q)/(q+1);
            }

        }
        return op;
    }
};