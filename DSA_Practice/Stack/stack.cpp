#include <bits/stdc++.h>
#define MAX_SIZE 100

using namespace std;

class Stack
{
private:
    int top;
    int data[MAX_SIZE];

public:
    // constructor
    Stack()
    {
        top = -1;
    }

    // push operation
    void push(int value)
    {
        if (top >= MAX_SIZE - 1)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            data[top++] = value;
        }
    }

    // pop operation
    void pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            top--;
        }
    }

    // peek operation
    int peek()
    {
        if (top < 0)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else
        {
            return data[top];
        }
    }

    // check if stack is empty
    bool isEmpty()
    {
        return (top == -1);
    }
};

int main()
{
    Stack myStack;

    // pushing elements
    myStack.push(32);
    myStack.push(43);
    myStack.push(23);
    myStack.push(3);

    // printing the top element using peek
    if (!myStack.isEmpty())
    {
        cout << "Top element of the stack: " << myStack.peek() << endl;
    }

    // poping elements from the stack
    if (!myStack.isEmpty())
    {
        cout << "Popped elements: ";
        while (!myStack.isEmpty())
        {
            cout << myStack.peek() << " ";
            myStack.pop();
        }
        cout << endl;
    }

    // checking if the stack is empty
    if (myStack.isEmpty())
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        cout << "Stack is not empty." << endl;
    }

    return 0;
}