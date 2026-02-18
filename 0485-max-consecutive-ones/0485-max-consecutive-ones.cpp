class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxC=0;
        int currC=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                currC++;
                maxC=max(maxC,currC);
            }
            else{
                currC=0;
            }
        }
        return maxC;
    }
};