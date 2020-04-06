#include "ft_ls.h"

static void     set_mode_et(unsigned char tof, char *str)
{
    if (tof == 6)
        *str = 'b';
    else if (tof == 2)
        *str = 'c';
    else if (tof == 4)
        *str = 'd';
    else if (tof == 10)
        *str = 'l';
    else if (tof == 12)
        *str = 's';
    else if (tof == 1)
        *str = 'p';
    else
        *str = '-';
}

static void     set_mode_p(unsigned short i, char *str)
{
    (i % 2 == 0) ? (*(str + 2) = '-') : (*(str + 2) = 'x');
    (i / 2 % 2 == 0) ? (*(str + 1) = '-') : (*(str + 1) = 'w');
    (i / 4 % 2 == 0) ? (*str = '-') : (*str = 'r');
}

char            *set_mode(unsigned short mode, unsigned char tof, char *name)
{
    char    *str;
    char    *temp;

    str = ft_strnew(11);
    temp = ft_strjoin("./", name);
    set_mode_et(tof, str);
    set_mode_p((mode / 64) % 8, &str[1]);
    set_mode_p((mode / 8) % 8, &str[4]);
    set_mode_p(mode % 8, &str[7]);
    if (listxattr(temp, NULL, 0, XATTR_NOFOLLOW) <= 0)
        str[10] = ' ';
    else
        str[10] = '@';
    free(temp);
    return (str);
}