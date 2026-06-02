class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                          vector<int>& waterStartTime, vector<int>& waterDuration) {
        int landFirstFinishTime = calculateEarliestFinish(landStartTime, landDuration,
                                                          waterStartTime, waterDuration);

        int waterFirstFinishTime = calculateEarliestFinish(waterStartTime, waterDuration,
                                                           landStartTime, landDuration);

        return min(landFirstFinishTime, waterFirstFinishTime);
    }

private:
    int calculateEarliestFinish(vector<int>& firstSegmentStart, vector<int>& firstSegmentDuration,
                                vector<int>& secondSegmentStart, vector<int>& secondSegmentDuration) {
        int earliestFirstSegmentEnd = INT_MAX;
        for (int i = 0; i < firstSegmentStart.size(); ++i) {
            int currentEndTime = firstSegmentStart[i] + firstSegmentDuration[i];
            earliestFirstSegmentEnd = min(earliestFirstSegmentEnd, currentEndTime);
        }

        int overallEarliestFinish = INT_MAX;
        for (int i = 0; i < secondSegmentStart.size(); ++i) {
            int actualSecondStart = max(earliestFirstSegmentEnd, secondSegmentStart[i]);
            int totalFinishTime = actualSecondStart + secondSegmentDuration[i];
            overallEarliestFinish = min(overallEarliestFinish, totalFinishTime);
        }

        return overallEarliestFinish;
    }
};