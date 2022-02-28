#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define ERR_OK 0
#define ERR_IO 1

double calc_sum(size_t *current_iter);

int main(void)
{
    int exit_code = ERR_OK;
    size_t current_iter = 1;
    double sum = calc_sum(&current_iter);
    if (current_iter == 1)
    {
        exit_code = ERR_IO;
    }
    if (!exit_code)
    {
        printf("%lf", sin(sum));
    }

    return exit_code;
}

double calc_sum(size_t *current_iter)
{
    double x = 0;
    double sum = 0;
    int res = 0;
    while ((res = scanf("%lf", &x)) != -1 && x >= 0)
    {
        sum += sqrt(x / *current_iter);
        ++(*current_iter);
    }
    return sum;
}