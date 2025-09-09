#include <cs50.h>
#include <stdio.h>

void pyramide(int hauteur)
{
    int ligne = 0;
    int counter = 0;
    int temp = hauteur - 1;
    int i = 0;
    while (ligne <= temp)
    {
        ligne++;
        while (counter < hauteur - 1)
        {
            printf(" ");
            counter++;
        }
        while (i < ligne)
        {
            printf("#");
            i++;
        }
        i = 0;
        counter = 0;
        hauteur--;
        printf("\n");
    }
}
int main()
{
    int hauteur = get_int("Height : ");
    while (hauteur <= 0)
    {
        hauteur = get_int("Height : ");
    }
    pyramide(hauteur);
}
