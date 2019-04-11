/*
** EPITECH PROJECT, 2018
** RevSTR
** File description:
** Fonction Revstr
*/

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    int loop = 0;

    while (str[i] != '\0')
        i++;
    i--;
    while (j < i) {
        loop = str[i];
        str[i] = str[j];
        str[j] = loop;
        i--;
        j++;
    }
    return (str);
}
