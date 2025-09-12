/*********************************************/
/*   scrabble.c*/
/*                                           */
/*   By: mr-burns*/
/*   Created: 2025/09/12 22:26:29*/
/*   Updated: 2025/09/12 22:26:29*/
/*                                           */
/*********************************************/
#include <cs50.h>
#include <stdio.h>

int additional_points(char *str)
{
    int point[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    char alphabet[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int i = 0;
    int j = 0;
    int sum = 0;

    while (str[i])
    {
        while (alphabet[j])
        {
            if (alphabet[j] == str[i])
            {
                sum += point[j];
            }
            j++;
        }
        j = 0;
        i++;
    }
    return (sum);
}

void ft_uppercase(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
        i++;
    }
}

void scrabble(char *player1, char *player2)
{
    char winner;
    int i = 0;
    int result_player1 = 0;
    int result_player2 = 0;
    int point[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    char alphabet[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int sum_player1 = 0;
    int sum_player2 = 0;
    sum_player1 = additional_points(player1);
    sum_player2 = additional_points(player2);

    if (sum_player1 > sum_player2)
    {
        printf("Player 1 wins!");
    }
    else if (sum_player1 < sum_player2)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!\n");
    }
}

int main()
{
    char *player1 = get_string("Player1 : ");
    char *player2 = get_string("Player2 : ");
    ft_uppercase(player1);
    ft_uppercase(player2);
    scrabble(player1, player2);
}

