class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int l=0;
        int odd=0;
        int ans=0;

        for(int r=0;r<nums.size();r++){
            if(nums[r]%2) odd++;
            while(odd>k){
                if(nums[l]%2) odd--;
                l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};