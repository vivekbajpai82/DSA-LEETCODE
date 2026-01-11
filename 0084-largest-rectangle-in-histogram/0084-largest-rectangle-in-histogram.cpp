class Solution {
public:
    void nextSmallerFunc(vector<int>& heights, int n, vector<int>& nextSmaller){
        stack<int> st;
        st.push(n-1);
        for(int i=n-2; i>=0; i--){

            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }

            if(!st.empty())  
                nextSmaller[i] = st.top();
            else
                nextSmaller[i] = n;
            
            st.push(i);
        }
    }

    void prevSmallerFunc(vector<int>& heights, int n, vector<int>& prevSmaller){
        stack<int> st;
        st.push(0);
        for(int i=1; i<n; i++){

            while(!st.empty() && heights[i] <= heights[st.top()]){
                st.pop();
            }

            if(!st.empty())  
                prevSmaller[i] = st.top();
            else
                prevSmaller[i] = -1;
            
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prevSmaller(n, -1);
        vector<int> nextSmaller(n, n);

        prevSmallerFunc(heights, n, prevSmaller);
        nextSmallerFunc(heights, n, nextSmaller);

        int maxArea = INT_MIN;
        for(int i=0; i<n; i++){
            int width = (nextSmaller[i] - prevSmaller[i] - 1);
            int currArea = heights[i]*width;

            maxArea = max(maxArea, currArea);
        }

        return maxArea;
    }
};