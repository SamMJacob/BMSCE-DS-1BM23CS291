#include <stdio.h>
#include <ctype.h>

const int max = 100;
char stack[100];
int top = -1;

void push(char op) {
    if (top < max - 1) {
        top++;
        stack[top] = op;
    }
}

char pop() {
    if (top != -1) {
        char c = stack[top];
        top--;
        return c;
    }
    return '\0'; // Return null character if stack is empty
}

char peek() {
    if (top != -1) {
        return stack[top];
    }
    return '\0'; // Return null character if stack is empty
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}



int main() {
    char infix[max];
    printf("Enter infix expression: ");
    fgets(infix, max, stdin); // Use fgets instead of gets for safety
   
    int i = 0;
    while (infix[i])
    {
        if (isalnum(infix[i]))
        {
            printf("%c", infix[i]);
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (top != -1 && peek() != '(')
            {
                printf("%c", pop());
            }
            pop(); // Remove the '(' from stack
           
        }
        else if (is_operator(infix[i]))
        {
            while (top != -1 && precedence(peek()) >= precedence(infix[i]))
            {
                if (infix[i] == '^' && peek() == '^')
                {
                    break; // Right associative
                }
                printf("%c", pop());
            }
            push(infix[i]);
        }
        i++;
    }

    // Pop all the operators from the stack
    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");
    return 0;
}
