class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        // iterate through each asteroid
        for(auto &it: asteroids) {
            // if the current asteroid is positive or the stack is empty, push it into the stack
            if(it > 0 || st.empty()) {
                st.push(it);
            }
            else {
                // while there are asteroids in the stack and the top asteroid is positive and smaller than the current asteroid
                while(!st.empty() && st.top() > 0 && st.top() < abs(it)) {
                    st.pop(); // remove the top asteroid from the stack
                }
                
                // if there is an asteroid in the stack with the same size as the current asteroid, remove it from the stack
                if(!st.empty() && st.top() == abs(it)) {
                    st.pop();
                }
                else {
                    // if there is no asteroid in the stack or the top asteroid in the stack is negative, push the current asteroid into the stack
                    if(st.empty() || st.top() < 0) {
                        st.push(it);
                    }
                }
            }
        }
        
        // create a vector to store the remaining asteroids in the stack
        vector<int> ans(st.size());
        for(int i=st.size() - 1; i>=0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        
        return ans;
    }
};