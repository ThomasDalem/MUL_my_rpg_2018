/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** Fonction
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int a = 0;

    if (my_strlen(s1) != my_strlen(s2))
        return (1);
    while (s1[a]) {
        if (s1[a] != s2[a])
            return (1);
        a ++;
    }
    return (0);
}
