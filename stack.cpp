#include<iostream>
#include<iomanip>
#include<time.h>
using namespace std;

class Stack

{
private:
    static const int maxSize = 5;
    int top = -1;
    int stack[maxSize];

public:

    bool isFull()
    {
        return top == maxSize - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(int item)
    {
        if(isFull())
        {
            cout<<"sTACK OOVerflow";


        }
        else
        {
            top++;
            stack[top] = item;
            cout<<item<<"Pushed into the stack";

        }

    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow";

        }
        else
        {

            cout<<"Popped Item"<<stack[top];
            top--;
        }

    }

    void peek()
    {

        if(isEmpty())
        {
            cout<<"Stack Empty";
        }
        else
        {
            cout<<"Top Element"<<stack[top];
        }
    }

    void display()
    {

        if(isEmpty())
        {

            cout<<"Stack Empty";

        }
        else
        {
            cout<<"Elements: ";
            for(int i=top;i>=0;i--)
            {
                cout<<stack[i]<<",";
            }
        }
    }

};

int main()
{
    clock_t start, end;
    double cpu_time_used;
    Stack s;
    int choice, num;
    start = clock();

    do {
        cout << "\nStack Operations Menu\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Check if Empty\n6. Check if Full\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number to push: ";
                cin >> num;
                s.push(num);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << (s.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
                break;
            case 6:
                cout << (s.isFull() ? "Stack is full\n" : "Stack is not full\n");
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    cout << fixed << setprecision(5);
    cout << "\nCPU Time used: " << cpu_time_used << " seconds\n";

    return 0;
}
