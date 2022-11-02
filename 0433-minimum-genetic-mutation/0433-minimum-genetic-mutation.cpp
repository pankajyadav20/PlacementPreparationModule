class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        unordered_set<string> st{bank.begin(),bank.end()};
        int count = 0;
        char genes[] = {'A' , 'C' , 'G' , 'T'};
        queue<string> q;
        q.push(start);
        
        while(!q.empty()){
            int s = q.size();
            
             while(s--){
                string cur = q.front();
                q.pop();
                 if(cur == end){
                     return count;
                 }
                 st.erase(cur);
                for(int i = 0 ; i < 8 ; i++){
                    string t=cur;
                    t[i]='A';
                    if(st.count(t)!=0)
                        q.push(t);
                    t[i]='C';
                    if(st.count(t)!=0)
                        q.push(t);
                    t[i]='G';
                    if(st.count(t)!=0)
                        q.push(t);
                    t[i]='T';
                    if(st.count(t)!=0)
                        q.push(t);
                }
            }
            count++;
        }
        return -1;
    }
};