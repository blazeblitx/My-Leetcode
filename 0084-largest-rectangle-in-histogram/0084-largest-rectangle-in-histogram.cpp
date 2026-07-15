class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> s; h.push_back(0);
        int ans=0;
        for(int i=0;i<h.size();i++){
            while(!s.empty()&&h[s.top()]>h[i]){
                int ht=h[s.top()]; s.pop();
                int w=s.empty()?i:i-s.top()-1;
                ans=max(ans,ht*w);
            }
            s.push(i);
        }
        return ans;
    }
};
