#include <stdio.h>

enum direction_t
{
    BACK,
    FORWARD
};

typedef enum direction_t direction_t;

int compare_int(const void *num1, const void *num2);

int create_array(int **arr_begin, int **arr_end, size_t len);

size_t find_index_of_min(const int *arr_begin, const int *arr_end);

size_t find_index_of_max(const int *arr_begin, const int *arr_end);

int copy_array(const int *pb_src, const int *pe_src, int *pb_dst, int *pe_dst);
