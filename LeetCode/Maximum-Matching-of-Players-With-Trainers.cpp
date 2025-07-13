class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int n = players.size();
        int m = trainers.size();

        int p = 0;
        int t = 0;

        while(t < m && p < n){
            if(players[p] <= trainers[t]){
                p++;
            }
            t++;   
        }

        return p;
    }
};