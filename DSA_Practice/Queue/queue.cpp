#include <bits/stdc++.h>
#define MAX_SIZE 100

using namespace std;

// Queue class
class Queue
{
private:
    int front, rear;
    int queue[MAX_SIZE];

public:
    // constructor
    Queue()
    {
        front = -1;
        rear = -1;
    }

    // enqueue operation
    void enqueue(int item)
    {
        if (rear == MAX_SIZE - 1)
        {
            cout << "Queue is full, cannot enqueue." << endl;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear++;
            queue[rear] = item;
            cout << item << "enqueue to the queue." << endl;
        }
    }

    // dequeue operation
    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty, cannot dequeue." << endl;
        }
        else
        {
            cout << queue[front] << " dequeue from the queue." << endl;
            front++;
        }
    }

    // peek operation
    int peek()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty, peek operation cannot be performed." << endl;
            return -1;
        }
        else
        {
            return queue[front];
        }
    }

    // check if queue is empty
    bool isEmpty()
    {
        return (front == -1 || front > rear);
    }
};

int main()
{
    Queue myQueue;

    // enqueue elements
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    // dequeue elements
    myQueue.dequeue();

    // peek the front element
    if (!myQueue.isEmpty())
    {
        cout << "Front element of the queue: " << myQueue.peek() << endl;
    }

    return 0;
}