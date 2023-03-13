#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    // Creating a stack of chars
    stack<char> st;

    for (char c : s) {

        // check if the current character is an opening bracket, and push it onto the stack
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);

        } else {

            // check if the stack is empty, which means there is no matching opening bracket for the current closing bracket
            if (st.empty()) {
                cout << "no" << endl;
                return 0;
            }

            // get the top bracket from the stack
            char top = st.top();
            st.pop();

            // check if the top bracket matches the current closing bracket
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                cout << "no" << endl;
                return 0;
            }
        }
    }

    // Stack should be empty if we found a match for every bracket
    if (!st.empty()) {
        cout << "no" << endl;
        return 0;
    }

    cout << "yes" << endl;
    return 0;
}