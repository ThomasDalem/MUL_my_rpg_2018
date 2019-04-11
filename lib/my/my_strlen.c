/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** affiche la longueur d'une chaine
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        i++;
    }
    return (i);
}
