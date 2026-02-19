class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long sa=0,so=0, saq=0,soq=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sa+=nums[i];
            saq+=(long long)nums[i]*nums[i];

            so+=(i+1);
            soq+=(long long)(i+1)*(i+1);
        }

            long long diff=so-sa;
            long long diffsq=soq-saq;

            long long sum=diffsq/diff;
            int dup= (diff+sum)/2;
            int miss=dup-diff;
            return {miss,dup};
            
            
    }
};