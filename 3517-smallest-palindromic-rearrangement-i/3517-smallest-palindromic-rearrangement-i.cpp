#include <bits/stdc++.h>
class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.length();
        int hl=n/2;
        string half=s.substr(0,hl);

        sort(half.begin(),half.end());

        string rhalf=half;
        reverse(rhalf.begin(),rhalf.end());

        if(n%2==1){
            return half+s[hl]+rhalf;
        }
        else{
            return half+rhalf;
        }
    }
};