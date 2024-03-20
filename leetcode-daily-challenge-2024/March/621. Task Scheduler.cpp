class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> ump;
        for (const auto &it : tasks)
        {
            ump[it]++;
        }

        priority_queue<int> pq;
        for (const auto &it : ump)
        {
            pq.push(it.second);
        }

        int ans = 0;
        int cycle = n + 1;
        while (!pq.empty())
        {
            int time = 0;
            vector<int> temp;
            for (int i = 0; i < cycle; i++)
            {
                if (!pq.empty())
                {
                    temp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for (int cnt : temp)
            {
                if (--cnt)
                {
                    pq.push(cnt);
                }
            }
            ans += !pq.empty() ? cycle : time;
        }
        return ans;
    }
};

/**

- A - 3 - done
- B - 3 - done
n = 2

let's perform the tasks - A B Idle
                        - A B Idle
                        - A B.


 - A - 2 - done
 - B - 2 - done
 - C - 1 - done
 - D - 1 - done
 n = 1

 let's perform the taks - A - A B
                        - C - C D
                        - A - A B

*/