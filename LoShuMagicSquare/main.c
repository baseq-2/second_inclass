#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isMagicSquare(int *array);
int getUnusedNumber(int *array, int count);
void printSquare(int *array);

int main()
{
    int square[3][3];
    int count = 0;
    time_t t;

    srand((unsigned)time(&t));
    
    do
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                square[i][j] = getUnusedNumber(&square[0][0], i * 3 + j);
            }
        }
        count++;
    } while (!isMagicSquare(&square[0][0]));

    printf("Number of squares generated: %d\n", count);
    printf("Final Square:\n");
    printSquare((&square[0][0]));
    return 0;
}

int isMagicSquare(int *array)
{
    int row1 = 0;
    int row2 = 0;
    int row3 = 0;
    int col1 = 0;
    int col2 = 0;
    int col3 = 0;
    int diag1 = 0;
    int diag2 = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 0)
            {
                row1 += *((array + i * 3) + j);
            }
            else if (i == 1)
            {
                row2 += *((array + i * 3) + j);
            }
            else if (i == 2)
            {
                row3 += *((array + i * 3) + j);
            }

            if (j == 0)
            {
                col1 += *((array + i * 3) + j);
            }
            else if (j == 1)
            {
                col2 += *((array + i * 3) + j);
            }
            else if (j == 2)
            {
                col3 += *((array + i * 3) + j);
            }

            if (i == j)
            {
                diag1 += *((array + i * 3) + j);
            }
            if (i+j == 2)
            {
                diag2 += *((array + i * 3) + j);
            }
        }
    }
    return row1 == 15 && row2 == 15 && row3 == 15 && col1 == 15 && col2 == 15 && col3 == 15 && diag1 == 15 && diag2 == 15;
}

int getUnusedNumber(int *array, int count)
{
    int unusedNum = rand() % 9 + 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i * 3 + j == count)
            {
                return unusedNum;
            }
            if (*((array + i * 3) + j) == unusedNum)
            {
                unusedNum = rand() % 9 + 1;
                i = -1;
            }
        }
    }
    return unusedNum;
}

void printSquare(int *array)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
            {
                printf("[");
            }
            printf("%d", *((array + i * 3) + j));
            if (j == 2)
            {
                printf("]\n");
            } else
            {
                printf(" ");
            }
        }
    }
}