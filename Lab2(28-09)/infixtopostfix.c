#include <stdio.h>

char stack[50];
int top = -1;

int prec(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    char infix[50], postfix[50];
    int j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (stack[top] != '(')
                postfix[j++] = stack[top--];
            top--;                          // remove '('
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (top != -1 && prec(stack[top]) >= prec(c))
                postfix[j++] = stack[top--];
            stack[++top] = c;
        } else {
            postfix[j++] = c;               // operand
        }
    }

    while (top != -1)
        postfix[j++] = stack[top--];
    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
    return 0;
}