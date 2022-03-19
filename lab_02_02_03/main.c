#include <stdio.h>
#include <math.h>

#define ERR_OK 0
#define ERR_INVALID_NUMBER_OF_ELM 1
#define MAX_SIZE 10

int input_array(int *elements_number, int *array);

void print_array(int elements_number, int *array);

void make_array(int elements_number_of_old_array, int *elements_number_of_new_array, int *old_array, int *new_array);

int check_number(int number);

int main(void)
{
    int array[MAX_SIZE] = { 0 };
    int elements_number = 0;
    int exit_code = ERR_INVALID_NUMBER_OF_ELM;

    if (input_array(&elements_number, array))
    {

    if (elements_number <= MAX_SIZE && elements_number > 0)
    {
        int new_array[MAX_SIZE] = { 0 };
        int new_elements_number = 0;

        make_array(elements_number, &new_elements_number, array, new_array);
        print_array(new_elements_number, new_array);

        if (new_elements_number != 0)
        {
        exit_code = ERR_OK;
        }
    }
    }

    return exit_code;
}

int input_array(int *elements_number, int *array)
{
    int is_correct = 1;

    if (scanf("%d", elements_number) != 1)
    {
        is_correct = 0;
    }

    for (int current_element = 0; current_element < *elements_number; ++current_element)
    {
        if (scanf("%d", (array + current_element)) != 1)
        {
            is_correct = 0;
        }
    }

    return is_correct;
}

void print_array(int elements_number, int *array)
{
    for (int current_element = 0; current_element < elements_number; ++current_element)
    {
        printf("%d ", array[current_element]);
    }
}

int check_number(int number)
{
    int number_cp = number;
    int digits[10] = { 0 };
    int sum = 0;
    int current_digit = 0;
    int digits_counter = 0;
    int is_amstrong_number = 1;

    while (number > 0)
    {
        current_digit = number % 10;
        number /= 10;
        digits[digits_counter] = current_digit;
        ++digits_counter;
    }

    for (int current_digit = 0; current_digit < digits_counter; ++current_digit)
    {
        sum += pow(digits[current_digit], digits_counter);
    }

    if (sum != number_cp || number_cp == 0)
    {
        // printf("sum: %d, number: %d", sum, number_cp);
        is_amstrong_number = 0;
    }

    return is_amstrong_number;
}

void make_array(int elements_number_of_old_array, int *elements_number_of_new_array, int *old_array, int *new_array)
{
    *elements_number_of_new_array = 0;

    for (int current_element = 0; current_element < elements_number_of_old_array; ++current_element)
    {
        // printf("number: %d IS: %d ", check_number(old_array[current_element]), old_array[current_element]);
        if (check_number(old_array[current_element]))
        {
            new_array[*elements_number_of_new_array] = old_array[current_element];
            ++*elements_number_of_new_array;
        }
    }
}
