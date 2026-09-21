/* calculator.c - basic calculator with powers, roots and modulus
 * Build: gcc calculator.c -o calculator -lm
 * Run:   ./calculator
 */

#include <stdio.h>
#include <math.h>

/* nth root that also handles negative values for odd integer n */
static int nth_root(double x, double n, double *out)
{
    if (n == 0.0)
        return 0;                       /* 0th root is undefined */

    if (x < 0.0) {
        /* only defined for odd integer n, e.g. 3rd, 5th root */
        if (n != floor(n) || fmod(n, 2.0) == 0.0)
            return 0;
        *out = -pow(-x, 1.0 / n);
    } else {
        *out = pow(x, 1.0 / n);
    }
    return 1;
}

static void menu(void)
{
    printf("\n===== SIMPLE C CALCULATOR =====\n");
           " 1. Add            a + b\n"
           " 2. Subtract       a - b\n"
           " 3. Multiply       a * b\n"
           " 4. Divide         a / b\n"
           " 5. Modulus        a %% b   (integer)\n"
           " 6. Modulus        fmod(a, b)  (real)\n"
           " 7. Square         x^2\n"
           " 8. Cube           x^3\n"
           " 9. Power of 10    x^10\n"
           "10. Power of n     x^n\n"
           "11. Square root    sqrt(x)\n"
           "12. Cube root      cbrt(x)\n"
           "13. nth root       x^(1/n)\n"
           " 0. Quit\n"
           "Choice: ";
}

int main(void)
{
    int choice;
    double a, b, x, n, r;

    for (;;) {
        menu();

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input, exiting.\n");
            return 1;
        }
        if (choice == 0) {
            printf("Bye.\n");
            return 0;
        }

        switch (choice) {
        case 1: case 2: case 3: case 4: case 5: case 6:
            printf("Enter a and b: ");
            if (scanf("%lf %lf", &a, &b) != 2) {
                printf("Invalid input.\n");
                return 1;
            }
            break;

        case 10: case 13:
            printf("Enter x and n: ");
            if (scanf("%lf %lf", &x, &n) != 2) {
                printf("Invalid input.\n");
                return 1;
            }
            break;

        case 7: case 8: case 9: case 11: case 12:
            printf("Enter x: ");
            if (scanf("%lf", &x) != 1) {
                printf("Invalid input.\n");
                return 1;
            }
            break;

        default:
            printf("Unknown choice.\n");
            continue;
        }

        switch (choice) {
        case 1:
            printf("Result: %g\n", a + b);
            break;
        case 2:
            printf("Result: %g\n", a - b);
            break;
        case 3:
            printf("Result: %g\n", a * b);
            break;
        case 4:
            if (b == 0.0)
                printf("Error: division by zero.\n");
            else
                printf("Result: %g\n", a / b);
            break;
        case 5: {
            long ia = (long)a;
            long ib = (long)b;
            if (ib == 0)
            printf("Error: modulus by zero.\n");
            else
            printf("Result: %ld\n", ia % ib);
            break;
        }
        case 6:
            if (b == 0.0)
                printf("Error: modulus by zero.\n");
            else
                printf("Result: %g\n", fmod(a, b));
            break;
        case 7:
            printf("Result: %g\n", x * x);
            break;
        case 8:
            printf("Result: %g\n", x * x * x);
            break;
        case 9:
            printf("Result: %g\n", pow(x, 10.0));
            break;
        case 10:
            r = pow(x, n);
            if (isnan(r))
                printf("Error: undefined for these values.\n");
            else
                printf("Result: %g\n", r);
            break;
        case 11:
            if (x < 0.0)
                printf("Error: square root of a negative number.\n");
            else
                printf("Result: %g\n", sqrt(x));
            break;
        case 12:
            printf("Result: %g\n", cbrt(x));
            break;
        case 13:
            if (nth_root(x, n, &r))
                printf("Result: %g\n", r);
            else
                printf("Error: nth root is undefined for these values.\n");
            break;
        }
    }
}