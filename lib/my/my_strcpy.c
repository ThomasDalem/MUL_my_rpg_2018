/*
** EPITECH PROJECT, 2018
** my_strcpy.c
** File description:
** copie de chaine
*/

char *my_strcpy(char *desp, char const *src)
{
    int i = 0;
    int j = 0;

    for (i = 0; src[i] != '\0'; i++)
    {
        desp[j] = src[i];
        j++;
    }
    desp[i] = '\0';
    return (desp);
}
