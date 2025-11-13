#include <iostream>
#define MAX 5
using namespace std;

class LinearQueue {
  int arr[MAX];
  int front, rear;
public:
  LinearQueue() {
    front = -1;
    rear = -1;
  }
  bool isEmpty() {
    return (front == -1 || front > rear);
  }
  bool isFull() {
    return (rear == MAX - 1);
  }
  void enqueue(int x) {
    if (isFull()) {
      cout << "Queue Overflow! Cannot insert " << x << endl;
      return;
    }
    if (front == -1) front = 0;
    arr[++rear] = x;
    cout << x << " enqueued to queue." << endl;
  }
  void dequeue() {
    if (isEmpty()) {
      cout << "Queue Underflow! Cannot dequeue." << endl;
      return;
    }
    cout << arr[front] << " dequeued from queue." << endl;
    front++;
  }
  int Front() {
    if (isEmpty()) {
      cout << "Queue is empty." << endl;
      return -1;
    }
    return arr[front];
  }
  int Rear() {
    if (isEmpty()) {
      cout << "Queue is empty." << endl;
      return -1;
    }
    return arr[rear];
  }
  int Size() {
    if (isEmpty()) return 0;
    return rear - front + 1;
  }
  void display() {
    if (isEmpty()) {
      cout << "Queue is empty." << endl;
      return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++)
      cout << arr[i] << " ";
    cout << endl;
  }
};

int main() {
  LinearQueue q;
  int choice, val;
  do {
    cout << "\n--- Linear Queue Menu ---\n";
    cout << "1. Enqueue\n2. Dequeue\n3. Front\n4. Rear\n5. Size\n6. Display\n7. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Enter value to enqueue: ";
        cin >> val;
        q.enqueue(val);
        break;
      case 2:
        q.dequeue();
        break;
      case 3:
        val = q.Front();
        if (val != -1) cout << "Front element: " << val << endl;
        break;
      case 4:
        val = q.Rear();
        if (val != -1) cout << "Rear element: " << val << endl;
        break;
      case 5:
        cout << "Queue size: " << q.Size() << endl;
        break;
      case 6:
        q.display();
        break;
      case 7:
        cout << "Exiting..." << endl;
        break;
      default:
        cout << "Invalid choice! Try again." << endl;
    }
  } while (choice != 7);
  return 0;
}
