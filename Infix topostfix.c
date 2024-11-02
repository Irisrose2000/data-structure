#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX]; // Stack to hold operators
int top = -1;

// Function to push an operator onto the stack
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

// Function to pop an operator from the stack
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0'; // Return null character if the stack is empty
}

// Function to get precedence of operators
int precedence(char c) {
    switch (c) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0; // Non-operators have lowest precedence
    }
}

// Function to convert infix to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char token;

    while ((token = infix[i]) != '\0') {
        if (token == ' ') { // Ignore spaces
            i++;
            continue;
        }
        if (isalnum(token)) { // If the token is an operand (variable)
            postfix[j++] = token;
        } else if (token == '(') { // If the token is '('
            push(token);
        } else if (token == ')') { // If the token is ')'
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '(' from the stack
        } else { // The token is an operator
            while (top != -1 && precedence(stack[top]) >= precedence(token)) {
                postfix[j++] = pop();
            }
            push(token);
        }
        i++;
    }

    while (top != -1) { // Pop all operators from the stack
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Null terminate the postfix expression
}

// Function to evaluate a postfix expression with variables
int evaluatePostfix(char* postfix, char variables[][2], int values[], int varCount) {
    int operandStack[MAX];
    top = -1; // Reset top for operand stack
    int a, b, result;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) { // Check if the character is a variable
            // Find the value of the variable
            for (int j = 0; j < varCount; j++) {
                if (variables[j][0] == postfix[i]) {
                    operandStack[++top] = values[j]; // Push the variable's value onto the stack
                    break;
                }
            }
        } else { // The character is an operator
            b = operandStack[top--]; // Pop the top two operands
            a = operandStack[top--];
            switch (postfix[i]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }
            operandStack[++top] = result; // Push the result back to the stack
        }
    }
    return operandStack[top]; // The final result is at the top of the stack
}

int main() {
    char infix[MAX], postfix[MAX];
    char variables[MAX][2]; // Array to hold variable names
    int values[MAX]; // Array to hold variable values
    int varCount = 0;

    printf("Enter an infix expression (e.g., A + B * C): ");
    fgets(infix, MAX, stdin); // Read the infix expression

    // Remove the newline character from the input
    infix[strcspn(infix, "\n")] = 0;

    // Find unique variables in the expression
    for (int i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            int isUnique = 1;
            for (int j = 0; j < varCount; j++) {
                if (variables[j][0] == infix[i]) {
                    isUnique = 0;
                    break;
                }
            }
            if (isUnique) {
                variables[varCount][0] = infix[i]; // Store the variable
                variables[varCount][1] = '\0'; // Null terminate the string
                varCount++;
            }
        }
    }

    // Get values for the variables from the user
    for (int i = 0; i < varCount; i++) {
        printf("Enter the value for %c: ", variables[i][0]);
        scanf("%d", &values[i]);
    }

    infixToPostfix(infix, postfix); // Convert to postfix
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix, variables, values, varCount); // Evaluate the postfix expression
    printf("Result of the postfix expression: %d\n", result);
    
    return 0;
}
