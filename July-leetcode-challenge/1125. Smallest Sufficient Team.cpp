class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        unordered_map<int, vector<int>> ans; // Map to store the combination of skills and the corresponding team
        ans.reserve(1 << n);
        ans[0] = {}; // Initialize the map with an empty team for the initial combination (no skills)
        unordered_map<string, int> skill_mp; // Map to store the mapping of skills to their indices

        // Assign indices to each skill
        for(int i=0; i<req_skills.size(); i++) {
            skill_mp[req_skills[i]] = i;
        }

        // Iterate over each person
        for(int i=0; i<people.size(); i++) {
            int curr_skill = 0;

            // Calculate the bitmask for the skills of the current person
            for(int j=0; j<people[i].size(); j++) {
                curr_skill |= 1 << skill_mp[people[i][j]];
            }

            // Iterate over the current combinations of skills in the map
            for(auto it = ans.begin(); it != ans.end(); it++) {
                int comb = it->first | curr_skill; // Calculate the combination of skills by merging the current and existing skills

                // If the combination does not exist in the map or if the new team is smaller than the existing team for the combination
                if(ans.find(comb) == ans.end() || ans[comb].size() > 1 + ans[it->first].size()) {
                    ans[comb] = it->second; // Assign the existing team for the combination
                    ans[comb].push_back(i); // Add the current person to the team
                }
            }
        }
        // Return the team corresponding to the full combination of skills
        return ans[(1 << n) - 1]; 
    }
};