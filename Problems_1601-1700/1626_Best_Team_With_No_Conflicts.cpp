class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int res = 0;
        int n = scores.size();
        int dp[n];

        // use a vector to store the pair({age, score})
        vector<pair<int, int>> players;
        for (int i = 0; i < n; i++)
        {
            players.push_back({ages[i], scores[i]});
        }

        // sort the vector by age
        sort(players.begin(), players.end());

        // dp[i] means the highest score we can get for age=i
        for (int i = 0; i < n; i++)
        {
            // for start, the highest score we can get at age=i is the player[i].score
            dp[i] = players[i].second;

            // check all the players with age smaller than the current player
            // if he's score is strict higher than current player's score, we pass him
            // otherwise, we can add him in the team, with the highest score he get
            
            // we compare all the scores that we can get from players before the current player
            // and find the max score for current player
            for (int j = 0; j < i; j++)
            {
                if (players[j].second <= players[i].second)
                    dp[i] = max(dp[i], dp[j] + players[i].second);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
