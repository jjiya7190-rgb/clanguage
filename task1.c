#include <stdio.h>

// Function prototype
void calculate(float a, float b, char operator);

int main() {
    float num1 ;
    float num2 ;
    printf("enter num1 : ");
    scanf("%f",&num1);
    printf("enter num2 :");
    scanf("%f",&num2);
    
    // We pass the two numbers and the operator character to the function
    calculate(num1, num2, '+');
    calculate(num1, num2, '-');
    calculate(num1, num2, '*');
    calculate(num1, num2, '/');
    calculate(num1, num2, 'x'); //  for Testing an invalid operator
    
    return 0;
}

// Void function that uses switch-case to select the operation
void calculate(float a, float b, char operator) {
    float result;

    switch (operator) {
        case '+':
            result = a + b;
            printf("%f + %f = %f\n", a, b, result);
            break;

        case '-':
            result = a - b;
            printf("%f - %f = %f\n", a, b, result);
            break;

        case '*':
            result = a * b;
            printf("%f * %f = %f\n", a, b, result);
            break;

        case '/':
            // in case of division by zero
            if (b == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                result = a / b;
                printf("%f / %f = %f\n", a, b, result);
            }
            break;
             // The default case handles any input that doesn't match the cases above
        default:
            printf("Error: '%c' is an invalid operator.\n", operator);
            break;
    }
}