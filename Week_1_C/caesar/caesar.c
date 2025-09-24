#include <cs50.h>
#include <stdio.h>
#include <unistd.h>

int ft_atoi(char *str)
{
    int i = 0;
    int res = 0;

    while (str[i])
    {
        res = (res * 10) + (str[i] - '0');
        i++;
    }
    return (res);
}
// faut aussi que tu vérifie que str[i] après l'incrementation n'est pas superieur a z
char *caesar(int key, char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if ((str[i] >= 'a' && str[i] < 'z'))
        {
            str[i] = 'a' + ((str[i] - 'a' + key) % 26);
        }
        if ((str[i] >= 'A' && str[i] < 'Z'))
        {
            str[i] = 'A' + ((str[i] - 'A' + key) % 26);
        }

        i++;
    }
    return (str);
}
int main(int argc, char **argv)
{
    // manage argv
    if (argc != 2)
    {
        return (1);
    }
    int k = 0;
    while (argv[1][k] != '\0')
    {
        if (!(argv[1][k] >= 1 && argv[1][k] <= 99))
        {
            return (1);
        }
        k++;
    }
    k = 0;
    char *str = get_string("plaintext : ");
    while (str[k])
    {
        if (!(str[k] >= 'a' && str[k] <= 'z') && !(str[k] >= 'A' && str[k] <= 'Z') &&
            (str[k] == ' ' && str[k] == ',' && str[k] == '!'))
        {
            str = get_string("plaintext :");
        }
        k++;
    }
    int key = ft_atoi(argv[1]);
    printf("ciphertext: %s\n", caesar(key, str));
}

