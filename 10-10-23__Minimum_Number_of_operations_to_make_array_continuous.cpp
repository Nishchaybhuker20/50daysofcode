class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=nums.size(),currans=0,x=nums.size();

        int t=nums[0],j=0;
        for(int i=1;i<x;i++){     //Set duplicates to zero
            if(nums[i]==t){
                nums[i]=0;
                j++;}              //j=number of zero (duplicates)
            else{t=nums[i];}
        }

        if(j!=0){sort(nums.begin(),nums.end());}

        for(int i=j;i<x;i++){
            int endrange=nums[i]+x-1;     //maximum possible range for num[i]
            int s=i,e=x-1,mid=(s+e)/2;
            while(s<=e){    //Find element which is just smaller(or =) than endrange
                if(nums[mid]==endrange || s==e){
                    if(s==e && nums[mid]>endrange){
                            mid=mid-1;}
                    currans=(x-mid-1)+i;
                    ans=min(ans,currans);
                    break;}

                else if(nums[mid]>endrange){
                    e=mid-1;}
                else{
                    s=mid+1;}
                if(s>e){
                    currans=(x-e-1)+i;
                    ans=min(ans,currans);}
                mid=(s+e)/2;
            }
        }
        return ans;
    }
};