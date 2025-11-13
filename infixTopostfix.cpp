#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct CharStack {
    char arr[MAX];
    int top = -1;

    bool empty()
    {
        return top == -1;
    }
    bool full()
    {
        return top == MAX - 1;
    }

    void push(char c)
    {
        if (!full())
        {
            arr[++top] = c;
        }
    }
    char pop()
    {
        return (!empty()) ? arr[top--] : '\0';
    }
    char peek() { return (!empty()) ? arr[top] : '\0'; }
};

int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

bool isAlnum(char ch) {
    return ((ch >= '0' && ch <= '9') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z'));
}

string infixToPostfix(string exp) {
    CharStack st;
    string result;

    for (size_t i = 0; i < exp.size(); ++i) {
        char ch = exp[i];

        if (isAlnum(ch)) result += ch;
        else if (ch == '(') st.push(ch);
        else if (ch == ')') {
            while (!st.empty() && st.peek() != '(')
                result += st.pop();
            if (!st.empty()) st.pop();
        }
        else {
            while (!st.empty() && precedence(st.peek()) >= precedence(ch))
                result += st.pop();
            st.push(ch);
        }
    }

    while (!st.empty()) result += st.pop();
    return result;
}

int main() {
    string expr;
    cout << "Enter infix expression: ";
    getline(cin, expr);
    cout << "Postfix: " << infixToPostfix(expr) << endl;
    return 0;
}
