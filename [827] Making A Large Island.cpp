class Solution {
public:
    int path_list[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
    vector<vector<int>> *map;
    vector<int> map_count;
    int n;
    int largestIsland(vector<vector<int>>& grid) {
        this->map = &grid;
        n = grid.size();
        vector<int> zero_index;
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                if(grid.at(i).at(j) == 1){
                    int count = calc(i*n+j, 2+map_count.size(), 0, -1);
                    map_count.push_back(count);
                }else if(grid.at(i).at(j) == 0){
                    zero_index.push_back(i*n+j);
                }
            }
        }
        if(zero_index.empty()){
            return map_count.at(0);
        }else{
            int max = 0, value;
            set<int> index;
            for(auto &it : zero_index){
                index.clear();
                value = 0;
                for(int j=0;j<4;++j){
                    int new_y = it/n+path_list[j][0];
                    int new_x = it%n+path_list[j][1];
                    if(new_y>=0 && new_y<n && new_x>=0 && new_x<n && grid.at(new_y).at(new_x)){
                        int index_length = index.size();
                        index.insert(grid.at(new_y).at(new_x));
                        value += index.size() > index_length ? map_count.at(grid.at(new_y).at(new_x)-2) : 0;
                    }
                }
                max = max > value+1 ? max : value+1;
            }
            return max;
        }
        return 0;
    }
    
    int calc(int i, int index, int value, int path_type) {
        map->at(i/n).at(i%n) = index;
        value++;
        for(int j=0;j<4;++j){
            if(path_type == (j+2)%4)continue;
            int new_y = i/n+path_list[j][0];
            int new_x = i%n+path_list[j][1];
            if(new_y>=0 && new_y<n && new_x>=0 && new_x<n && map->at(new_y).at(new_x) == 1){
                int new_value = calc(new_y*n+new_x, index, value, j);
                value = new_value > value ? new_value : value;
            }
        }
        return value;
    }
};