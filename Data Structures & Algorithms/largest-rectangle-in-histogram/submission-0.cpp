class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(0);
        heights.push_back(0);
        long long area = 0;
        for(int i = 1; i < heights.size(); i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int h = heights[st.top()];
                st.pop();
                int w;
                if(st.empty()) w = i;
                else w = i - st.top() - 1; 
                area = max(area, 1LL * h * w);
            }
            st.push(i);
        }
        return area;
    }
};
