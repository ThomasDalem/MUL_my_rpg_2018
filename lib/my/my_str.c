/*
** EPITECH PROJECT, 2019
** Lib
** File description:
** my_str.c
*/

int my_str(char *str1, char *str2)
{
    int a = 0;

    while (str1[a]) {
        if (str1[a] != str2[a])
            return (1);
        a ++;
    }
    return (0);
}
