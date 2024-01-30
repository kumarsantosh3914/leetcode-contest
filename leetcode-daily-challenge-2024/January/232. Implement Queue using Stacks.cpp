class MyQueue
{
private:
    stack<int> input, output;

public:
    MyQueue() {}

    void push(int x)
    {
        // pop out all elements from the stack input
        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }
        // Insert the desired element in the stack input
        input.push(x);
        while (!output.empty())
        {
            input.push(output.top());
            output.pop();
        }
    }

    int pop()
    {
        int val = input.top();
        input.pop();
        return val;
    }

    int peek()
    {
        return input.top();
    }

    bool empty()
    {
        return input.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */