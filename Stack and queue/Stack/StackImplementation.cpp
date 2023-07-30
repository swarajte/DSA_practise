#include <bits/stdc++.h>
using namespace std;

class Stack
{

public:
    int size;
    int top;
    int *arr;

    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        this->arr = new int[size];
    }

    void push(int ele)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = ele;
        }

        else
        {
            cout << "stack is overflown" << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "stack is empty" << endl;
        }
        else
        {
            top--;
        }
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "stack is empty" << endl;
            return -1000;
        }
        else
        {
            return arr[top];
        }
    }

    void IsEmpty()
    {
        if (top == -1)
        {
            cout << "stack is empty" << endl;
        }
        else
        {
            cout << "stack is not empty" << endl;
        }
    }
};
int main()
{
    Stack st(4);
    st.push(1);
    cout << st.peek() << endl;
    st.push(2);
    cout << st.peek() << endl;
    st.push(3);
    cout << st.peek() << endl;
    st.push(4);
    cout << st.peek() << endl;
    st.push(5);
    st.pop();
    cout << st.peek() << endl;
    st.push(5);
    cout << st.peek() << endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout<<st.peek();
    st.IsEmpty(); 

    st.pop();
    return 0;
}