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
};

bool isBalanced(string exp) {
    CharStack st;
    for (size_t i = 0; i < exp.size(); ++i) {
        char ch = exp[i];
        if (ch == '(' || ch == '{' || ch == '[')
            st.push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty()) return false;
            char top = st.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
                return false;
        }
    }
    return st.empty();
}

int main() {
    string expr;
    cout << "Enter expression: ";
    getline(cin, expr);

    if (isBalanced(expr))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
    return 0;
}
