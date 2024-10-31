class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> factoryPositions;
        for (auto& f : factory)
            for (int i = 0; i < f[1]; i++) factoryPositions.push_back(f[0]);

        int robotCount = robot.size(), factoryCount = factoryPositions.size();
        vector<vector<long long>> dp(robotCount,
                                       vector<long long>(factoryCount, -1));
        return calculateMinDistance(0, 0, robot, factoryPositions,dp);
    }

    long long calculateMinDistance(int robotIdx, int factoryIdx,
                                   vector<int>& robot,
                                   vector<int>& factoryPositions,
                                   vector<vector<long long>> &dp) {

        if (robotIdx == robot.size()) return 0;
        if (factoryIdx == factoryPositions.size()) return 1e12;

        if(dp[robotIdx][factoryIdx]!=-1)
            return dp[robotIdx][factoryIdx];

        long long assign = abs(robot[robotIdx] - factoryPositions[factoryIdx]) +
                           calculateMinDistance(robotIdx + 1, factoryIdx + 1,
                                                robot, factoryPositions,dp);

        long long skip = calculateMinDistance(robotIdx, factoryIdx + 1, robot,
                                              factoryPositions,dp);

        return dp[robotIdx][factoryIdx] = min(assign, skip);
    }
};
