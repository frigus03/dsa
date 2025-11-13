#include <iostream>
using namespace std;

class JosephusCircularQueue {
  int *arr;
  int front, rear, count, maxsize;
public:
  JosephusCircularQueue(int n) {
    maxsize = n;
    arr = new int[maxsize];
    front = 0;
    rear = -1;
    count = 0;
  }
  ~JosephusCircularQueue() { delete[] arr; }

  bool isEmpty() { return count == 0; }

  void enqueue(int x) {
    if (count == maxsize) return;
    rear = (rear + 1) % maxsize;
    arr[rear] = x;
    count++;
  }

  int dequeue() {
    if (isEmpty()) return -1;
    int val = arr[front];
    front = (front + 1) % maxsize;
    count--;
    return val;
  }

  void rotate(int k) {
    for (int i = 0; i < k; ++i)
      enqueue(dequeue());
  }

  int Size() { return count; }
  int Front() { return isEmpty() ? -1 : arr[front]; }
};

int josephus(int n, int k) {
  JosephusCircularQueue q(n);
  for (int i = 1; i <= n; ++i)
    q.enqueue(i);

  while (q.Size() > 1) {
    q.rotate(k - 1);
    int eliminated = q.dequeue();
    cout << "Person " << eliminated << " is eliminated.\n";
  }
  return q.Front();
}

int main() {
  int n, k;
  cout << "--- Josephus Problem ---\n";
  cout << "Enter number of people (n): ";
  cin >> n;
  cout << "Enter step count (k): ";
  cin >> k;

  int survivor = josephus(n, k);
  cout << "The survivor is person: " << survivor << endl;
  return 0;
}
