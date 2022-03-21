#include <stdio.h>

#define ERR_OK 0
#define ERR_NO_ELM 1
#define ERR_INVALID_NUMBER_OF_ELM 100
#define MAX_SIZE 10
#define SIZE 200

int input_array(int *elements_number, int *array);

void print_array(int elements_number, int *array);

void insertion_sort(int elements_number, int *array);

int main(void)
{
    int array[SIZE] = { 0 };
    int elements_number = 0;
    int res = ERR_OK;

    if ((res = input_array(&elements_number, array)) != ERR_NO_ELM)
    {
        insertion_sort(elements_number, array);

        if (elements_number > MAX_SIZE)
        {
            elements_number = MAX_SIZE;
        }

        print_array(elements_number, array);
    }

    return res;
}

int input_array(int *elements_number, int *array)
{
    int current_element = 0;
    int is_correct = 0;
    int res = 0;

    while ((res = scanf("%d", array + current_element)) == 1)
    {
        ++current_element;
    }

    if (!current_element)
    {
        is_correct = ERR_NO_ELM;
    }

    if (res != 1 && current_element > 10)
    {
        is_correct = ERR_INVALID_NUMBER_OF_ELM;
    }

    *elements_number = current_element;

    return is_correct;
}

void print_array(int elements_number, int *array)
{
    for (int current_element = 0; current_element < elements_number; ++current_element)
    {
        printf("%d ", array[current_element]);
    }
}

void insertion_sort(int elements_number, int *array)
{
    for (int current_element = 1; current_element < elements_number; ++current_element)
    {
        int key = array[current_element];
        int j = current_element - 1;

        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }

        array[j + 1] = key;
    }
}
