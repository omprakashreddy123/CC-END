class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        st.push(-1); 
        long long maxarea=0;

        for(int i=0;i<n;++i) {
            while(st.top()!=-1 && heights[i]<heights[st.top()]) {
                int hindex = st.top();
                st.pop();
                long long height=heights[hindex];
                long long width=i-st.top()-1;
                long long area = height*width;
                maxarea = max(maxarea,area);
            }
            st.push(i);
        }

        while(st.top()!=-1) {
            int hindex=st.top();
            st.pop();
            long long height=heights[hindex];
            long long width =n-st.top() -1;
            long long area = height*width;
            maxarea = max(maxarea,area);
        }

        return maxarea;
    }
};
