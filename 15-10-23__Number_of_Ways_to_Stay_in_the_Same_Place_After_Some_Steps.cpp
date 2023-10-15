const int MOD = 1e9 + 7;

const int maxPositions = 250 + 3;
const int maxSteps = 500 + 3;

class Solution {
public:
    int dp[maxSteps][maxPositions];

    int calculateWays(int currentPosition, int remainingSteps, int maxPosition) {
        if (remainingSteps == 0)
            return dp[remainingSteps][currentPosition] = (currentPosition == 0) ? 1 : 0;

        if (dp[remainingSteps][currentPosition] != -1)
            return dp[remainingSteps][currentPosition];

        int ways = 0;
        for (int dir = -1; dir <= 1; dir++) {
            int nextPosition = currentPosition + dir;

            if (nextPosition >= remainingSteps)
                continue;

            if (nextPosition >= 0 && nextPosition < maxPosition) {
                ways += calculateWays(nextPosition, remainingSteps - 1, maxPosition);
                ways %= MOD;
            }
        }

        return dp[remainingSteps][currentPosition] = ways;
    }

    int numWays(int steps, int maxPosition) {
        memset(dp, -1, sizeof(dp));
        return calculateWays(0, steps, maxPosition);
    }
};