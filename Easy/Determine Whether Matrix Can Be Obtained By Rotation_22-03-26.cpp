class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int rowCount=mat.size()-1;
        int colCount=rowCount;
        int counter=0;
        if(mat==target) return true;
        while(counter<3){
            vector<vector<int>> newArr;
            for(int i=0;i<=rowCount;i++){
                vector<int> arr;
                for(int j=rowCount;j>=0;j--){
                    arr.push_back(mat[j][i]);
                }
                newArr.push_back(arr);
            }
            if(newArr==target) return true;
            mat=newArr;
            counter++;
        }

        return false;
        
    }
};