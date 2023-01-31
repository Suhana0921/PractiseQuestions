class Solution {class Solution {
public:
public:
    int findMaxScore(vector<pair<int, int>>& ageScorePair) {
    int findMaxScore(vector<pair<int, int>>& ageScorePair) {
        int n = (int) ageScorePair.size();
        int n = (int) ageScorePair.size();
        int answer = 0;
        int answer = 0;
        
        
        vector<int> dp(n);
        vector<int> dp(n);

        for (int i = 0; i < n; i++) {
        for (int i = 0; i < n; i++) {
            dp[i] = ageScorePair[i].second;
            dp[i] = ageScorePair[i].second;
            answer = max(answer, dp[i]);
            answer = max(answer, dp[i]);
        }
        }
        
        
        for (int i = 0; i < n; i++) {
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
            for (int j = i - 1; j >= 0; j--) {

                if (ageScorePair[i].second >= ageScorePair[j].second) {
                if (ageScorePair[i].second >= ageScorePair[j].second) {
                    // Update the maximum score for the ith player.
                    // Update the maximum score for the ith player.
                    dp[i] = max(dp[i], ageScorePair[i].second + dp[j]);
                    dp[i] = max(dp[i], ageScorePair[i].second + dp[j]);
                }
                }
            }
            }

            answer = max(answer, dp[i]);
            answer = max(answer, dp[i]);
        }
        }
        
        
        return answer;
        return answer;
    }
    }
    
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> ageScorePair;
        vector<pair<int, int>> ageScorePair;
        for (int i = 0; i < scores.size(); i++) {
        for (int i = 0; i < scores.size(); i++) {
            ageScorePair.push_back({ages[i], scores[i]});
            ageScorePair.push_back({ages[i], scores[i]});
        }
        }

        sort(ageScorePair.begin(), ageScorePair.end());
        sort(ageScorePair.begin(), ageScorePair.end());
        return findMaxScore(ageScorePair);
        return findMaxScore(ageScorePair);
    }
    }
};
};
