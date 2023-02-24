class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int minVal = INT_MAX;
        for (int num : nums) {
            if (num % 2 == 1)
                num = num * 2;
            pq.push(num);
            minVal = min(minVal, num);
        }
        int minDeviation = INT_MAX;
        while (true) {
            int maxVal = pq.top();
            pq.pop();
            minDeviation = min(minDeviation, maxVal - minVal);
            //The reason we need to break out of the loop when the maximum value is odd is that we have already transformed all odd numbers in the input array to even numbers by multiplying them by 2. Therefore, if the maximum value in the priority queue is odd, it must have been obtained by performing the "multiply by 2" operation on some even number. We cannot undo this operation by performing the "divide by 2" operation, so we cannot reduce the maximum value any further.
            if (maxVal % 2 == 1)
                break;
            maxVal = maxVal / 2;
            minVal = min(minVal, maxVal);
            pq.push(maxVal);
        }
        return minDeviation;
    }
};