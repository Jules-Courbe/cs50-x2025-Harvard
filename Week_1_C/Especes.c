#include <cs50.h>
#include <stdio.h>

void coin_calculator(int own)
{
    int coin_total = 0;
    int coin_25 = 25;
    int coin_10 = 10;
    int coin_5 = 5;
    int coin_1 = 1;

    while (own != 0)
    {
        while (own / coin_25)
        {
            printf("%d\n", own);
            own -= 25;
            coin_total++;
        }
        while (own / coin_10)
        {
            printf("%d\n", own);
            own -= 10;
            coin_total++;
        }
        while (own / coin_5)
        {
            printf("%d\n", own);
            own -= 5;
            coin_total++;
        }
        while (own / 1)
        {
            printf("%d\n", own);
            own -= 1;
            coin_total++;
        }
        printf("\n");
        printf("Need : %d coins\n", coin_total);
    }
}
int main()
{
    int own = get_int("How much own in cents : ");
    while (own <= 0)
    {
        own = get_int("How much own in cents : ");
    }
    coin_calculator(own);
}
