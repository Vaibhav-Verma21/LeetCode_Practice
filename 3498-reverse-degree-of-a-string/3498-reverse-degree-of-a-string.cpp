class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            int rI='z'-s[i]+1;
            int pos=i+1;
            ans+=rI*pos;
        }
        return ans;
        
    }
};