#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void InsertInHeap(int val)
    {
        size++;          // making space for insertion
        arr[size] = val; // inserting new node at the end

        int index = size;
        while (index > 1) // until it reaches root node
        {
            int parent = index / 2;
            if (arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void DeleteHeap()
    {
        if (size == 0)
        {
            cout << "heap is empty nothing to delete" << endl;
        }

        arr[1] = arr[size]; // copying data from last node to root node
        size--;             // deleting last node(data of first node is gone )

        int index = 1;
        while (index < size)
        { // until last child reached
            int leftchild = 2 * index;
            int rightchild = 2 * index + 1;

            if (leftchild < size && arr[index] < arr[leftchild] && arr[leftchild] > arr[rightchild])
            {
                swap(arr[index], arr[leftchild]);
                index = leftchild;
            }
            else if (rightchild < size && arr[index] < arr[rightchild] && arr[rightchild] > arr[leftchild])
            {
                swap(arr[index], arr[rightchild]);
                index = rightchild;
            }
            else
            {
                return;
            }
        }
    }

    void printHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftchild = 2 * i+1;
    int rightchild = 2 * i + 2;

    if (leftchild <= n && arr[leftchild] > arr[largest])
    {
        swap(arr[leftchild], arr[largest]);
        largest = leftchild;
    }

    else if (rightchild <= n && arr[rightchild] > arr[largest])
    {
        swap(arr[rightchild], arr[largest]);
        largest = rightchild;
    }

    if (largest != i)
    {
        heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {

        // swapping last node with first node
        swap(arr[size], arr[1]);
        size--; // deleting first node or decresing size as vo to set ho gaya

        heapify(arr, size, 1); // jo swap kiya hai root node pe usko heapify kro {sort ho jayega }
    }
}
int main()
{
    // heap hp;
    // hp.InsertInHeap(55);
    // hp.InsertInHeap(54);
    // hp.InsertInHeap(53);
    // hp.InsertInHeap(50);
    // hp.InsertInHeap(52);
    // hp.printHeap();
    // hp.InsertInHeap(60);
    // hp.printHeap();

    // hp.DeleteHeap();

    // hp.printHeap();

    // heap creation from array (t.c.=> O(nlog(n)))
    int n = 5;
    int arr[6] = {54, 53, 55, 52, 50};
    for (int i = n / 2 -1 ; i >= 0; i--)
    {
        heapify(arr, n, i); // tc=O(N)
    }

    cout << "printed output of heap is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    HeapSort(arr, n); // t.c = O(nLog(n))

    cout<<endl;
    cout << "printed output of heap sort is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }


    // priority_queue<int> pq; 
    // pq.push(2);
    // pq.push(5);
    // pq.push(3);
    // pq.push(1);

    // cout<<"root ka element for this heap is : "<<pq.top()<<endl;

    // pq.pop();

    // cout<<"root ka element for this heap is : "<<pq.top();


    return 0;
}