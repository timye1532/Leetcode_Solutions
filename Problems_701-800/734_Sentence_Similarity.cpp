class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) return false;
        unordered_map<string, unordered_set<string>> sim_map;
        for (auto &pair : similarPairs) {
            sim_map[pair[0]].emplace(pair[1]);
            sim_map[pair[1]].emplace(pair[0]);
        }

        for (int i = 0; i < sentence1.size(); i++) {
            if ((sentence1[i] != sentence2[i]) && (sim_map.count(sentence1[i]) == 0 || (sim_map[sentence1[i]].count(sentence2[i]) == 0))) return false;
        }
        return true;
    }
};