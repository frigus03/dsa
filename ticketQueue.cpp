#include <iostream>
#define MAX 5
using namespace std;

class TicketCircularQueue {
  int arr[MAX];
  int front, rear, count;
public:
  TicketCircularQueue() {
    front = 0; rear = -1; count = 0;
  }
  bool isEmpty() { return count == 0; }
  bool isFull() { return count == MAX; }

  void enqueue(int ticket) {
    if (isFull()) {
      cout << "Queue full! Cannot add ticket " << ticket << endl;
      return;
    }
    rear = (rear + 1) % MAX;
    arr[rear] = ticket;
    count++;
  }

  int dequeue() {
    if (isEmpty()) {
      cout << "Queue empty! Cannot dequeue." << endl;
      return -1;
    }
    int t = arr[front];
    front = (front + 1) % MAX;
    count--;
    return t;
  }

  void display() {
    if (isEmpty()) {
      cout << "Queue is empty." << endl;
      return;
    }
    for (int i = 0; i < count; i++)
      cout << arr[(front + i) % MAX] << " ";
    cout << endl;
  }

  int Size() { return count; }
};

int main() {
  TicketCircularQueue booking, cancellation;
  int ticket_counter = 1, rchoice;

  cout << "\n--- Railway Reservation System ---\n";
  do {
    cout << "\n1. Book Ticket\n2. Cancel Ticket\n3. Show Booked Tickets\n4. Show Cancelled Tickets\n5. Exit\n";
    cout << "Enter your choice: ";
    cin >> rchoice;

    switch (rchoice) {
      case 1:
        if (booking.isFull()) {
          cout << "All tickets booked! No more tickets available.\n";
        } else {
          booking.enqueue(ticket_counter);
          cout << "Ticket booked! Ticket number: " << ticket_counter << endl;
          ticket_counter++;
        }
        break;
      case 2:
        if (booking.isEmpty()) {
          cout << "No tickets to cancel.\n";
        } else {
          int cancelled = booking.dequeue();
          cancellation.enqueue(cancelled);
          cout << "Ticket " << cancelled << " cancelled.\n";
        }
        break;
      case 3:
        cout << "Booked Tickets: ";
        booking.display();
        break;
      case 4:
        cout << "Cancelled Tickets: ";
        cancellation.display();
        break;
      case 5:
        cout << "Exiting Railway Reservation System.\n";
        break;
      default:
        cout << "Invalid choice! Try again.\n";
    }
  } while (rchoice != 5);

  return 0;
}
