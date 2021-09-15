#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    // MENU DATA
    char OPERATION_ANSWER[2];

    // BINARY DATA
    char BINARY[16];
    int BINARY_DECIMALVALUE = 1;
    short BINARY_REPEAT = 0;
    int BIT_VALUE;
    int BIT_INDEX;

    // DECIMAL DATA
    int DECIMAL;

    printf("|########|\n");
    printf("| BITPAD |\n");
    printf("|########|\n\n");

    printf("|#######################|#######################|\n");
    printf("| DECIMAL TO BINARY: DB | BINARY TO DECIMAL: BD |\n");
    printf("|#######################|#######################|\n\n");

    do
    {
        printf("ANSWER (DB/BD): ");
        scanf("%s", OPERATION_ANSWER);

        printf("\n"); // | LINE BREAKER |
    } while (strcmp(OPERATION_ANSWER, "DB") && strcmp(OPERATION_ANSWER, "BD"));

    // DECIMAL TO BINARY CALCULATOR
    if (strcmp(OPERATION_ANSWER, "DB") == 0)
    {
        printf("|###################|\n");
        printf("| DECIMAL TO BINARY |\n");
        printf("|###################|\n\n");

        printf("ENTER DECIMAL NUMBER --> ");
        scanf("%d", &DECIMAL);

        printf("\n"); // | LINE BREAKER |

        while (BINARY_DECIMALVALUE <= DECIMAL)
        {
            BINARY_DECIMALVALUE = BINARY_DECIMALVALUE * 2;
            BINARY_REPEAT++;
        }

        BINARY_DECIMALVALUE = BINARY_DECIMALVALUE / 2;

        printf("BINARY RESULT --> ");

        for (int i = BINARY_REPEAT -1; i >= 0; i--)
        {
            BIT_VALUE = pow(2, i);

            if (DECIMAL >= BIT_VALUE)
            {
                printf("1");
                DECIMAL = DECIMAL - BIT_VALUE;
            }
            else
            {
                printf("0");
            }
        }
        printf("\n"); // | LINE BREAKER |
    }
    // BINARY TO DECIMAL CALCULATOR
    else if (strcmp(OPERATION_ANSWER, "BD") == 0)
    {
        printf("|###################|\n");
        printf("| BINARY TO DECIMAL |\n");
        printf("|###################|\n\n");

        printf("ENTER BINARY NUMBER --> ");
        scanf("%s", BINARY);

        printf("\n"); // | LINE BREAKER |

        BIT_INDEX = sizeof(BINARY) - 1;

        for (int i = 0; i < sizeof(BINARY); i++)
        {
            if (BINARY[i] == '1')
            {
                DECIMAL = DECIMAL + pow(2, BIT_INDEX);
            }

            BIT_INDEX--;
        }

        printf("DECIMAL RESULT --> %d\n", DECIMAL);
    }

    return 0;
}
