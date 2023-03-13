#include <iostream>
#include <stack>
#include <string>

using namespace std;

// a function for evaluating postfix expressions
int evaluatePostfix(string expression) {

    // create an empty stack
    stack<int> stack;

    // loop through each character of the expression
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];

        // if we encounter a digit
        if (isdigit(c)) {
            int num = 0;

            // Converting a char(or several) to int
            while (isdigit(c)) {
                num = num * 10 + (c - '0');

                // increasing the i and checking if the next char is also a digit so
                // that we don't miss an integer with multiple digits
                i++;
                c = expression[i];
            }

            // Push the integer onto the stack
            stack.push(num);
        }
        else if (c == ' ') {

            // Ignore whitespace characters
            continue;
        }
        else {
            // The current character is not a digit or a space,
            // which means it's an operator, so we pop the top two
            // elements off the stack and apply the operator to them
            int num2 = stack.top();
            stack.pop();

            int num1 = stack.top();
            stack.pop();

            // perform an operation depending on the symbol
            switch (c) {

                // addition if +
                case '+':
                    stack.push(num1 + num2);
                    break;

                    // subtraction if -
                case '-':
                    stack.push(num1 - num2);
                    break;

                    // multiplication if * (the only one left)
                default:
                    stack.push(num1 * num2);;
            }
        }
    }

    // the result of the expression is the last number left in stack
    return stack.top();
}

int main() {
    string expression;

    // reading the string to evaluate
    getline(cin, expression);

    // evaluating the expression and print the result
    int result = evaluatePostfix(expression);

    // printing the result
    cout << result << endl;

    return 0;
}