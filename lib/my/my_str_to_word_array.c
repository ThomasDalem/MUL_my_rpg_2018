/*
** EPITECH PROJECT, 2018
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stddef.h>

int my_strlen(char const *str);

int alphanum(char const *str, int i, char ch)
{
    if (str[i] != '\0' && str[i] != '\n' && str[i] != ch)
        return (1);
    else
        return (0);
}

int taille_mot(char const *str, int i, int ch)
{
    int t = 0;

    while (alphanum(str, i, ch) == 1) {
        i++;
        t++;
    }
    return (t);
}

int nb_word(char const *str, char ch)
{
    int nb = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (alphanum(str, i, ch) == 1) {
            nb++;
            i = taille_mot(str, i, ch) + i - 1;
        }
        if (i < my_strlen(str))
            i++;
    }
    return (nb);
}

char *file_array(char const *str, int *i, char ch)
{
    char *str2 = malloc(sizeof(char) * (taille_mot(str, *i, ch) + 1));
    int k = 0;

    if (str2 == NULL)
        return (NULL); 
    while (alphanum(str, *i, ch) == 1) {
        str2[k] = str[*i];
        (*i)++;
        k++;
    }
    str2[k] = '\0';
    return (str2);
}

char **my_str_to_word_array(char const *str, char ch)
{
    char **array = NULL;
    int i = 0;
    int j = 0;

    array = malloc(sizeof(char *) * ((nb_word(str, ch)) + 1));
    if (array == NULL)
        return (NULL);
    while (str[i] != '\0' && str[i] != '\n') {
        if (alphanum(str, i, ch) == 1) {
            array[j] = file_array(str, &i, ch);
            j++;
        }
        if (str[i] != '\0')
            i++;
    }
    array[j] = NULL;
    return (array);
}
