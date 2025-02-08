class NumberContainers {
    unordered_map<int,int> num_at;
    unordered_map<int,set<int>> indices_of;
public:
    NumberContainers() {
        num_at.clear();
        indices_of.clear();
    }
    
    void change(int index, int number) {
        if(num_at.find(index)!=num_at.end()){
            int cur_num = num_at[index];
            indices_of[cur_num].erase(index);
        }
        num_at[index] = number;
        indices_of[number].insert(index);
    }
    
    int find(int number) {
        if(indices_of[number].size()){
            return *indices_of[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
