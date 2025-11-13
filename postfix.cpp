#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct IntStack {
    int arr[MAX];
    int top = -1;

    bool empty()
    {
        return top == -1;
    }
    bool full()
    {
        return top == MAX - 1;
    }

    void push(int x)
    {
        if (!full())
            arr[++top] = x;
    }
    int pop()
    {
        return (!empty()) ? arr[top--] : 0;
    }
};

bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

int evaluatePostfix(string exp) {
    IntStack st;

    for (size_t i = 0; i < exp.size(); ++i) {
        char ch = exp[i];

        if (isDigit(ch))
            st.push(ch - '0');
        else {
            int b = st.pop();
            int a = st.pop();
            switch(ch) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }
    return st.pop();
}

int main() {
    string expr;
    cout << "Enter postfix expression (digits only): ";
    getline(cin, expr);
    cout << "Result: " << evaluatePostfix(expr) << endl;
    return 0;
}
