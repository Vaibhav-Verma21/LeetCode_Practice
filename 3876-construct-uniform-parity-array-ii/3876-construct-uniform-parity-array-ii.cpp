class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd=INT_MAX;
        for(int n:nums1){
            if(n%2==1){
                minOdd=min(minOdd,n);
            }
        }
        for(int n:nums1){
            if(n%2==0 && n<minOdd && minOdd!=INT_MAX){
                return false;
            }
        }
        return true;
    }
};