/*
** EPITECH PROJECT, 2019
** Navy
** File description:
** Unit Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "prototype.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

/*Test(utils, usage_attempt_1)
{
    cr_assert(usage() == 0);
}*/

Test(lib_strlen1, simple_string, .init = redirect_all_std)
{
    char *str = NULL;
    int result = 0;

    result = my_strlen(str);
    cr_expect_eq(result, -1);
}

Test(lib_strlen2, simple_string, .init = redirect_all_std)
{
    char *str = "salut";
    int result = 0;

    result = my_strlen(str);
    cr_expect_eq(result, 5);
}

Test(lib_strlen3, simple_string, .init = redirect_all_std)
{
    char *str = "salut\0 ca va ?";
    int result = 0;

    result = my_strlen(str);
    cr_expect_eq(result, 5);
}

Test(lib_getnbr1, simple_string, .init = redirect_all_std)
{
    char *str = "42";
    int result = 0;

    result = my_getnbr(str);
    cr_expect_eq(result, 42);
}

Test(lib_getnbr2, simple_string, .init = redirect_all_std)
{
    char *str = "42salutlama";
    int result = 0;

    result = my_getnbr(str);
    cr_expect_eq(result, 42);
}

Test(lib_getnbr3, simple_string, .init = redirect_all_std)
{
    char *str = "salutlama42";
    int result = 0;

    result = my_getnbr(str);
    cr_expect_eq(result, 0);
}

Test(lib_str1, simple_string, .init = redirect_all_std)
{
    char *str = "lama";
    char *str2 = "lama";
    int result = 0;

    result = my_str(str, str2);
    cr_expect_eq(result, 0);
}

Test(lib_str2, simple_string, .init = redirect_all_std)
{
    char *str = "lama";
    char *str2 = "lamascotte";
    int result = 0;

    result = my_str(str, str2);
    cr_expect_eq(result, 0);
}

Test(lib_str3, simple_string, .init = redirect_all_std)
{
    char *str = "lama";
    char *str2 = "lamascotte";
    int result = 0;

    result = my_str(str2, str);
    cr_expect_eq(result, 1);
}

Test(lib_putstr1, simple_string, .init = redirect_all_std)
{
    my_putstr("hello world\n");
    cr_assert_stdout_eq_str("hello world\n");
}

Test(lib_putstr2, simple_string, .init = redirect_all_std)
{
    char *str = NULL;
    int result = my_putstr(str);

    cr_expect_eq(result, 0);
}

Test(lib_putstr3, simple_string, .init = redirect_all_std)
{
    my_putstr("\\");
    cr_assert_stdout_eq_str("\\");
}

Test(lib_str_isalpha1, simple_string, .init = redirect_all_std)
{
    char *str = NULL;
    int result = my_str_isalpha(str);

    cr_expect_eq(result, 1);
}

Test(lib_str_isalpha2, simple_string, .init = redirect_all_std)
{
    char *str = "abcdefghijklmnopqrstuvwxyz1234567890";
    int result = my_str_isalpha(str);

    cr_expect_eq(result, 0);
}

Test(lib_str_isalpha3, simple_string, .init = redirect_all_std)
{
    char *str = "#";
    int result = my_str_isalpha(str);

    cr_expect_eq(result, 1);
}

Test(lib_str_isnum1, simple_string, .init = redirect_all_std)
{
    char *str = "#";
    int result = my_str_isnum(str);

    cr_expect_eq(result, 1);
}

Test(lib_str_isnum2, simple_string, .init = redirect_all_std)
{
    char *str = NULL;
    int result = my_str_isnum(str);

    cr_expect_eq(result, 1);
}

Test(lib_str_isnum3, simple_string, .init = redirect_all_std)
{
    char *str = "0123456789";
    int result = my_str_isnum(str);

    cr_expect_eq(result, 0);
}

Test(lib_str_isnum4, simple_string, .init = redirect_all_std)
{
    char *str = "j'ai 4 ans";
    int result = my_str_isnum(str);

    cr_expect_eq(result, 1);
}

Test(lib_put_nbr1, simple_string, .init = redirect_all_std)
{
    int i = 21;

    my_put_nbr(i);
    cr_assert_stdout_eq_str("21");
}

Test(lib_put_nbr2, simple_string, .init = redirect_all_std)
{
    int i = 0;

    my_put_nbr(i);
    cr_assert_stdout_eq_str("0");
}

Test(lib_put_nbr3, simple_string, .init = redirect_all_std)
{
    int i = -42;

    my_put_nbr(i);
    cr_assert_stdout_eq_str("-42");
}

Test(lib_my_printf1, simple_string, .init = redirect_all_std)
{
    my_printf("hello world\n");
    cr_assert_stdout_eq_str("hello world\n");
}

Test(lib_my_printf2, simple_string2, .init = redirect_all_std)
{
    my_printf("abcdefghijklmnopqrstuvwxyz0123456789()+-*/%\n");
    cr_assert_stdout_eq_str("abcdefghijklmnopqrstuvwxyz0123456789()+-*/%\n");
}

Test(lib_my_printf3, simple_string3, .init = redirect_all_std)
{
    my_printf("je fais une phrase, pour tester un cas courant...!?\n");
    cr_assert_stdout_eq_str("je fais une phrase, pour tester un cas courant...!?\n");
}

Test(lib_my_printf4, simple_string_modulo, .init = redirect_all_std)
{
    my_printf("modulo %%\n");
    cr_assert_stdout_eq_str("modulo %\n");
}

Test(lib_my_printf5, simple_string_modulo2, .init = redirect_all_std)
{
    my_printf("le symbole %% est un simple modulo\n");
    cr_assert_stdout_eq_str("le symbole % est un simple modulo\n");
}

Test(lib_my_printf6, simple_string_modulo3, .init = redirect_all_std)
{
    my_printf("on peut mettre plusieurs %% a la suite, regarder %% %% %%\n");
    cr_assert_stdout_eq_str("on peut mettre plusieurs % a la suite, regarder % % %\n");
}

Test(lib_my_printf7, simple_string_binary, .init = redirect_all_std)
{
    int ui = 29659143;

    my_printf("binary = %b\n", ui);
    cr_assert_stdout_eq_str("binary = 1110001001001000000000111\n");
}

Test(lib_my_printf8, simple_string_binary2, .init = redirect_all_std)
{
    int ui = 19462507;

    my_printf("binary = %b\n", ui);
    cr_assert_stdout_eq_str("binary = 1001010001111100101101011\n");
}

Test(lib_my_printf9, simple_string_binary3, .init = redirect_all_std)
{
    int ui = 93773055;

    my_printf("binary = %b\n", ui);
    cr_assert_stdout_eq_str("binary = 101100101101101110011111111\n");
}

Test(lib_my_printf10, simple_string_char, .init = redirect_all_std)
{
    char c = 'c';

    my_printf("char = %c\n", c);
    cr_assert_stdout_eq_str("char = c\n");
}

Test(lib_my_printf11, simple_string_char2, .init = redirect_all_std)
{
    char c = 'q';

    my_printf("char = %c\n", c);
    cr_assert_stdout_eq_str("char = q\n");
}

Test(lib_my_printf12, simple_string_char3, .init = redirect_all_std)
{
    char c = 'r';

    my_printf("char = %c\n", c);
    cr_assert_stdout_eq_str("char = r\n");
}

Test(lib_my_printf13, simple_string_intd, .init = redirect_all_std)
{
    int i = 42;

    my_printf("int = %d\n", i);
    cr_assert_stdout_eq_str("int = 42\n");
}

Test(lib_my_printf14, simple_string_intd2, .init = redirect_all_std)
{
    int i = 84000;

    my_printf("int = %d\n", i);
    cr_assert_stdout_eq_str("int = 84000\n");
}

Test(lib_my_printf15, simple_string_intd3, .init = redirect_all_std)
{
    int i = 1000000000;

    my_printf("int = %d\n", i);
    cr_assert_stdout_eq_str("int = 1000000000\n");
}

Test(lib_my_printf16, simple_string_double, .init = redirect_all_std)
{
    double l = 54321;

    my_printf("double = %f\n", l);
    cr_assert_stdout_eq_str("double = 54321\n");
}

Test(lib_my_printf17, simple_string_double2, .init = redirect_all_std)
{
    double l = 504321;

    my_printf("double = %f\n", l);
    cr_assert_stdout_eq_str("double = 504321\n");
}

Test(lib_my_printf18, simple_string_double3, .init = redirect_all_std)
{
    double l = 7654321;

    my_printf("double = %f\n", l);
    cr_assert_stdout_eq_str("double = 7654321\n");
}

Test(lib_my_printf19, simple_string_inti, .init = redirect_all_std)
{
    int i = 42;

    my_printf("int = %i\n", i);
    cr_assert_stdout_eq_str("int = 42\n");
}

Test(lib_my_printf20, simple_string_inti2, .init = redirect_all_std)
{
    int i = 84000;

    my_printf("int = %i\n", i);
    cr_assert_stdout_eq_str("int = 84000\n");
}

Test(lib_my_printf21, simple_string_inti3, .init = redirect_all_std)
{
    int i = 1000000000;

    my_printf("int = %i\n", i);
    cr_assert_stdout_eq_str("int = 1000000000\n");
}

Test(lib_my_printf22, simple_string_long, .init = redirect_all_std)
{
    long l = 42000000000;

    my_printf("long = %l\n", l);
    cr_assert_stdout_eq_str("long = 42000000000\n");
}

Test(lib_my_printf23, simple_string_long2, .init = redirect_all_std)
{
    long l = 42000000000000;

    my_printf("long = %l\n", l);
    cr_assert_stdout_eq_str("long = 42000000000000\n");
}

Test(lib_put_long1, simple_string, .init = redirect_all_std)
{
    long i = 42000000000000;

    my_put_long(i);
    cr_assert_stdout_eq_str("42000000000000");
}

Test(lib_put_long2, simple_string, .init = redirect_all_std)
{
    long i = 0;

    my_put_long(i);
    cr_assert_stdout_eq_str("0");
}

Test(lib_put_long3, simple_string, .init = redirect_all_std)
{
    long i = -42000000000000;

    my_put_long(i);
    cr_assert_stdout_eq_str("-42000000000000");
}
