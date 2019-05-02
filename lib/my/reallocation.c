/*
** EPITECH PROJECT, 2019
** reallocation.c
** File description:
** reallocation
*/

#include <stddef.h>
#include <stdlib.h>

char *my_strcpy(char *desp, char const *src);
int my_strlen(char const *str);

char **reallocation(char **str, int taille)
{
    char **tmp = NULL;
    int i = 0;

    tmp =  malloc(sizeof(char *) * (taille + 2));
    if (tmp == NULL)
        return (NULL);
    while (str[i] != NULL && i != taille) {
        tmp[i] = malloc(sizeof(char) * (my_strlen(str[i]) + 1));
        if (tmp == NULL)
            return (NULL);
        tmp[i] = my_strcpy(tmp[i], str[i]);
        free(str[i]);
        i++;
    }
    tmp[i] = NULL;
    tmp[i + 1] = NULL;
    free(str);
    return (tmp);
}
