#include <stdio.h>

int no_of_element()
{
    int n;
    printf("Enter the total no of elements: ");
    scanf("%d", &n);
    return n;
}

int input_in_array(int *p, int n)
{
    printf("Enter the elements one by one:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
}

int sum_of_elements(int *p, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += p[i];
    }
    return sum;
}

float average_of_numbers(int sum, int n)
{
    float average;
    average = (float)sum / n;
    return average;
}

int main()
{
    int a[100], n, sum;
    float avg;

    n = no_of_element();
    input_in_array(a, n);
    sum = sum_of_elements(a, n);
    avg = average_of_numbers(sum, n);

    printf("Average: %.2f\n", avg);

    return 0;
}
