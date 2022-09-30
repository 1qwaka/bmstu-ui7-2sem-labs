#include <malloc.h>
#include <stdlib.h>

#include "../inc/array_t.h"
#include "../inc/utils.h"
#include "../inc/error_t.h"

int init_array(array_t *arr)
{
    error_t rc = OK;

    if (arr->len > 0)
    {
        arr->p = calloc(arr->len, sizeof(int));

        if (arr->p == NULL)
        {
            rc = ERR_INV_PTR;
        }
    }
    else
    {
        rc = ERR_BAD_LEN;
    }

    return rc;
}

int free_array(array_t *arr)
{
    error_t rc = OK;

    arr->len = 0;

    if (arr->p != NULL)
    {
        free(arr->p);
        arr->p = NULL;
    }
    else
    {
        rc = ERR_INV_PTR;
    }

    return rc;
}

int get_array_len(FILE *fp, array_t *arr)
{
    error_t rc = OK;
    int num = 0;
    arr->len = 0;

    while (fscanf(fp, "%d", &num) == 1)
    {
        ++arr->len;
    }
    
    if (!feof(fp))
    {
        rc = ERR_BAD_FILE_DATA;
    }

    if (arr->len == 0)
    {
        rc = ERR_BAD_LEN;
    }

    return rc;
}

int read_array(FILE *fp, array_t *arr)
{
    error_t rc = OK;
    size_t i = 0;

    while (i < arr->len && rc == OK)
    {
        if (fscanf(fp, "%d", (arr->p + i)) == 1)
        {
            ++i;
        }
        else
        {
            rc = ERR_READING;
        }
    }

    return rc;
}

void print_array_to_file(FILE *fp, array_t *arr)
{
    for (size_t i = 0; i < arr->len; ++i)
    {
        fprintf(fp, "%d ", *(arr->p + i));
    }
}
