/*
** EPITECH PROJECT, 2024
** MY_STRCAT
** File description:
** Cat 2 str
*/
#include "my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int length = my_strlen(dest);
    int i = 0;

    for (; src[i] != '\0'; i++) {
        dest[length + i] = src[i];
    }
    dest[length + i + 1] = '\0';
    return dest;
}

char *my_strccat(char const c, char *str)
{
    int len = my_strlen(str);
    char *temp = my_strdup(str);

    str = malloc(len + 2);
    my_strcpy(str, temp);
    str[len] = c;
    str[len + 1] = '\0';
    free(temp);
    return str;
}
