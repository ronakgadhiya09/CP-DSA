class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, 
                                  vector<vector<string>>& ingredients, 
                                  vector<string>& supplies) {

        unordered_set<string> canMake;
        int prevSize = -1;
        unordered_set<string> sup(supplies.begin(), supplies.end());

        while (prevSize != canMake.size()){
            prevSize = canMake.size();
            for (int i = 0; i < recipes.size(); i++){
                if (canMake.find(recipes[i]) != canMake.end()) continue;

                bool haveAllIng = true;
                for (auto& ing : ingredients[i]){
                    if (sup.find(ing) == sup.end()){
                        haveAllIng = false;
                        break;
                    }
                }

                if (haveAllIng){
                    canMake.insert(recipes[i]);
                    sup.insert(recipes[i]);
                }
            }
        }

        vector<string> ans(canMake.begin(), canMake.end());
        return ans;
    }
};
