#include <iostream>
using namespace std;

// /adding an element at a specific index
void insertElement(int arr[], int &size, int idx, int element)
{
    // check invalid case
    if (idx > size || idx < 0)
    {
        cout << " Invalid index for insertion " << endl;
        return;
    }

    for (int i = size; i >= idx; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[idx] = element;
    size++;
}

// removing an element from a specific index
void deleteElement(int arr[], int &size, int idx)
{
    if (idx >= size || idx < 0)
    {
        cout << "Invalid index for deletion" << endl;
        return;
    }

    for (int i = idx; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}

// Accessing each element of the array one by one
void traverseArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

// Finding the index of a particular element
int searchElement(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    // element not found
    return -1;
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;

    // insert 10 at index 2
    insertElement(arr, size, 2, 10);

    // removes the element at index 2
    deleteElement(arr, size, 2);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}