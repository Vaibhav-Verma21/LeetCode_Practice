class Solution {
public:
    bool checkOnesSegment(string s) {
        int done = false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                if (done) return false;
            } else done = true;
        }
        return true;
    }
};
