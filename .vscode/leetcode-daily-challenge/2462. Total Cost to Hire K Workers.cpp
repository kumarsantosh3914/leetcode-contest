#define ll long long
class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        // using min heap to store the cost of each candidate in the current window of size k
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        // total cost
        ll cost = 0;
        // left to right pointer of the window
        int i = 0, j = costs.size() - 1;
        while (k--)
        {
            // adding the first k candidates to the window
            while (pq1.size() < candidates && i <= j)
            {
                pq1.push(costs[i++]);
            }
            // adding the last candidates to the window
            while (pq2.size() < candidates && j >= i)
            {
                pq2.push(costs[j--]);
            }
            // if the first window is full, then the top
            // of the first window is the minimum cost of the first candidates
            int top1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
            // if the last window is full, then the top of the last window is
            // the minimum cost of the last candidates
            int top2 = pq2.size() > 0 ? pq2.top() : INT_MAX;
            // if the first window is cheaper, then add the first candidate to the window
            if (top1 <= top2)
            {
                cost += top1;
                pq1.pop();
            }
            // if the last window is cheaper, then add the last candidate to the window
            else
            {
                cost += top2;
                pq2.pop();
            }
            // cnt++;
        }
        // return the total cost
        return cost;
    }
};