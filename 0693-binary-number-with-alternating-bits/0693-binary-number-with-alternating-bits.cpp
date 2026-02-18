class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prevBit=-1;
        while(n>0){
            int currBit = n & 1;
            if(prevBit == currBit){
                return false;
            }
            prevBit=currBit;
            n>>=1;
        }
        return true;
    }
};