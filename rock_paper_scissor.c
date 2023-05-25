#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int randomNum()
{
    srand(time(NULL));
    return rand() % 3;
}
void play(char *playerName, int *result, int *points)
{
    int n, c, pu = 0, pc = 0, loop = 3;
    while (loop > 0)
    {
    repeat:
        printf("\n\nChoose one option\n  0 - Rock\n  1 - Paper\n  2 - Scissor\n");
        scanf("%d", &n);
        switch (n)
        {
        case 0:
            printf("%s : Rock\n", playerName);
            break;

        case 1:
            printf("%s : Paper\n", playerName);
            break;

        case 2:
            printf("%s : Scissor\n", playerName);
            break;

        default:
            printf("Invalid option");
            goto repeat;
            break;
        }
        c = randomNum();
        switch (c)
        {
        case 0:
            printf("Computer : Rock\n");
            break;

        case 1:
            printf("Computer : Paper\n");
            break;

        case 2:
            printf("Computer : Scissor\n");
            break;
        }
        // user win case
        if (n == 0 && c == 2)
        {
            pu++;
            printf("%s won. %d point\n", playerName, pu);
        }
        else if (n == 1 && c == 0)
        {
            pu++;
            printf("%s won. %d point\n", playerName, pu);
        }
        else if (n == 2 && c == 1)
        {
            pu++;
            printf("%s won. %d points\n", playerName, pu);
        }
        // draw case
        else if (n == c)
        {
            printf("Match Draw....no points\n");
        }
        // comp. win case
        else
        {
            pc++;
            printf("Computer won. %d points\n", pc);
        }
        loop--;
    }
    if (pu > pc)
    {
        *result = 0;
        *points = pu - pc;
    }
    else if (pc > pu)
    {
        *result = 1;
        *points = pc - pu;
    }
    else
    {
        *result = 3;
    }
}
int main()
{
    char *palyerName, ch;
    int n = 100, result, points;
    printf("\t\t\tWelcome to Rock-Paper_Scissor Game\n");
    printf("Enter Name : ");
    palyerName = (char *)malloc(n * sizeof(char));
    gets(palyerName);
    again:
        play(palyerName, &result, &points);
        if (result == 0)
            printf("\n%s Won by %d points\n", palyerName, points);
        else if (result == 1)
            printf("\nYou lost by %d points\n", points);
        else
        {
            printf("\nMatch Draw\n");
        }
        getchar();
        printf("Wanna play Again? Hit enter to play Again or any key to exit: ");
        ch = getchar();
        if (ch == 10)
        {
            goto again;
        }
        else
        {
            printf("Exiting.........");
            free(palyerName);
            return 0;
        }
        free(palyerName);
}
