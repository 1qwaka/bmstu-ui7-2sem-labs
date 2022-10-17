#include <stdio.h>
#include <stdlib.h>

#include "../inc/matr_t.h"


#define RESIZE 2

error_t create_matr(matr_t *matr, size_t rows, size_t cols)
{
    error_t rc = OK;

    if (matr != NULL)
    {
        if (rows > 0 && cols > 0)
        {
            matr->body = malloc(rows * sizeof(double*) * RESIZE);

            if (matr->body != NULL)
            {
                for (size_t i = 0; i < rows; ++i)
                {
                    matr->body[i] = malloc(cols * sizeof(double) * RESIZE);

                    if (matr->body[i] == NULL)
                    {
                        rc = ERR_ALLOC_MATR;
                    }
                }

                if (rc == OK)
                {
                    matr->rows = rows;
                    matr->cols = cols;
                }
            }
            else
            {
                rc = ERR_ALLOC_MATR;
            }
        }
        else if (rows <= 0)
        {
            rc = ERR_BAD_ROWS;
        }
        else
        {
            rc = ERR_BAD_COLS;
        }

    }
    else
    {
        rc = ERR_INV_STRUCT_PTR;
    }

    return rc;
}


error_t free_matr(matr_t *matr)
{
    error_t rc = OK;

    if (matr != NULL)
    {
        if (matr->body != NULL)
        {
            for (size_t i = 0; i < matr->rows; ++i)
            {
                if (matr->body[i] != NULL)
                {
                    free(matr->body[i]);
                    matr->body[i] = NULL;
                }
                else
                {
                    rc = ERR_INV_PTR;
                }
            }

            free(matr->body);
            matr->body = NULL;
        }
        else
        {
            rc = ERR_INV_PTR;
        }
    }
    else
    {
        rc = ERR_INV_STRUCT_PTR;
    }

    return rc;
}

error_t read_matr(matr_t *matr)
{
    error_t rc = OK;

    if (matr != NULL)
    {
        size_t rows = 0, cols = 0;

        if (scanf("%zu %zu", &rows, &cols) == 2)
        {
            if (rows > 0 && cols > 0)
            {
                if ((rc = create_matr(matr, rows, cols)) == OK)
                {
                    for (size_t cur_row = 0; cur_row < rows; ++cur_row)
                    {
                        for (size_t cur_col = 0; cur_col < cols; ++cur_col)
                        {
                            if (scanf("%lf", &matr->body[cur_row][cur_col]) != 1)
                            {
                                rc = ERR_READING;
                            }
                        }
                    }
                }
            }
            else if (rows <= 0)
            {
                rc = ERR_BAD_ROWS;
            }
            else
            {
                rc = ERR_BAD_COLS;
            }
        }
        else
        {
            rc = ERR_READING;
        }
    }
    else
    {
        rc = ERR_INV_STRUCT_PTR;
    }

    return rc;
}

error_t print_matr(matr_t *matr)
{
    error_t rc = OK;

    if (matr != NULL)
    {
        if (matr->body != NULL)
        {
            for (size_t cur_row = 0; cur_row < matr->rows; ++cur_row)
            {
                for (size_t cur_col = 0; cur_col < matr->cols; ++cur_col)
                {
                    if (matr->body[cur_row] != NULL)
                    {
                        printf("%lf ", matr->body[cur_row][cur_col]);
                    }
                }

                printf("\n");
            }
        }
    }
    else
    {
        rc = ERR_INV_STRUCT_PTR;
    }

    return rc;
}
