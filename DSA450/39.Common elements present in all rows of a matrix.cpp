#include<unordered_set>
vector<int> findCommonElements(vector<vector<int>> &mat)
{
    unordered_set<int> present,temp;
    int n=mat.size(),m=mat[0].size();
    for(int i=0;i<n;i++){
        temp.clear();
        for(int j=0;j<m;j++){
            if(i==0){
                temp.insert(mat[i][j]);
            }else{
                if(present.count(mat[i][j]))temp.insert(mat[i][j]);
            }
        }
        present=temp;
    }
    vector<int> common(present.begin(),present.end());
    return common;
}
