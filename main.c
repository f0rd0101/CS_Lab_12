#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void input_array(double *arr, int n, char name) {
    printf("Введіть %d елемент(ів) масиву %c:\n", n, name);
    for (int i = 0; i < n; ++i) {
        printf("%c[%d] = ", name, i);
        scanf("%lf", &arr[i]);
    }
}


double compute_A(double *x, int n) {
    double sum = 0;
    for (int i = 0; i < n; ++i)
        sum += x[i] * sin(x[i]) + pow(x[i], 2) * cos(x[i]);
    return sum;
}


double compute_B(double *y, int n) {
    double sum = 0;
    for (int i = 0; i < n; ++i)
        sum += y[i] * cos(y[i]) + pow(y[i], 2) * sin(y[i]);
    return sum;
}


double compute_C(double *z, int n) {
    double sum = 0;
    for (int i = 0; i < n; ++i)
        sum += z[i] * sin(z[i]) + pow(z[i], 2) * sin(z[i]);
    return sum;
}


double compute_D(double *q, int n) {
    double sum = 0;
    for (int i = 0; i < n; ++i)
        sum += q[i] * cos(q[i]) + pow(q[i], 2) * cos(q[i]);
    return sum;
}

int main() {
    int nx, ny, nz, nq;
    printf("Введіть кількість елементів для масивів x, y, z, q:\n");
    printf("nx = "); scanf("%d", &nx);
    printf("ny = "); scanf("%d", &ny);
    printf("nz = "); scanf("%d", &nz);
    printf("nq = "); scanf("%d", &nq);

    double *x = (double*)malloc(nx * sizeof(double));
    double *y = (double*)malloc(ny * sizeof(double));
    double *z = (double*)malloc(nz * sizeof(double));
    double *q = (double*)malloc(nq * sizeof(double));

    input_array(x, nx, 'x');
    input_array(y, ny, 'y');
    input_array(z, nz, 'z');
    input_array(q, nq, 'q');

    char choice;
    printf("\nОберіть функцію для обчислення (A, B, C, D): ");
    scanf(" %c", &choice);  

    double result;
    switch (choice) {
        case 'A': result = compute_A(x, nx); break;
        case 'B': result = compute_B(y, ny); break;
        case 'C': result = compute_C(z, nz); break;
        case 'D': result = compute_D(q, nq); break;
        default:
            printf("Неправильний вибір функції.\n");
            free(x); free(y); free(z); free(q);
            return 1;
    }

    printf("Результат обчислення %c = %.4lf\n", choice, result);

    free(x);
    free(y);
    free(z);
    free(q);
    return 0;
}
