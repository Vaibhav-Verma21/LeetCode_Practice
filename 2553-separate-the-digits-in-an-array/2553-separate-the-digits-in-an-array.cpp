class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> answer;

        for (int num : nums) {
            vector<int> temp;

            while (num > 0) {
                temp.push_back(num % 10);
                num /= 10;
            }

            reverse(temp.begin(), temp.end());

            for (int digit : temp) {
                answer.push_back(digit);
            }
        }

        return answer;
    }
};