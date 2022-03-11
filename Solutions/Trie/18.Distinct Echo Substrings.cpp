
class Solution {
public:
    bool check(string &s){
        int len=s.length();
        if(len&1)return false;
        for(int i=0;i<len/2;i++){
            if(s[i]!=s[i+len/2])
                return false;
        }
        return true;
    }
    int distinctEchoSubstrings(string text) {
        unordered_set<string> hash;
        int len=text.length();
        string sub;
        for(int i=0;i<len;i++){
            sub="";
            for(int j=i;j<len;j++){
                sub+=text[j];
                if(check(sub))
                    hash.insert(sub);
            }
        }
        return (int)hash.size();
    }
};