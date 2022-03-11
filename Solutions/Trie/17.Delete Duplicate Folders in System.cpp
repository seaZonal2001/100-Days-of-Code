struct Node{
  string name;
  map<string,Node*> next;
  bool isdeleted=false;
  Node(string n=""):name(n){}
};

class Solution {
public:
    void addPath(Node* node,vector<string>& path){
        for(auto &s:path){
            if(node->next.count(s)==0)node->next[s]=new Node(s);
            node=node->next[s];
        }
    }
    
    unordered_map<string,Node*> seen;
    string dedupe(Node *node){
        string subfolder;
        for(auto &[name,next]:node->next){
            subfolder+=dedupe(next);
        }
        
        if(subfolder.size()){
            if(seen.count(subfolder)){
                seen[subfolder]->isdeleted=node->isdeleted=true;
            }else{
                seen[subfolder]=node;
            }
        }
        
        return "("+node->name+subfolder+")";
    }
    
    vector<vector<string>> ans;
    vector<string> path;
    
    void getPath(Node* node){
        if(node->isdeleted)return ;
        path.push_back(node->name);
        ans.push_back(path);
        for(auto &[name,next]:node->next){
            getPath(next);
        }
        path.pop_back();
    }
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node root;
        for(auto &path:paths)addPath(&root,path);
        dedupe(&root);
        for(auto &[name,next]:root.next)getPath(next);
        return ans;
    }
};