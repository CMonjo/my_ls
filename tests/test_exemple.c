/*
** EPITECH PROJECT, 2017
** Units tests exemple
** File description:
** Exemple on my_strlen
*/

#include <criterion/criterion.h>

Test(Length, str_equal_1)
{
  cr_assert_eq(my_strlen("A"), 1);
}

Test(Length, str_equal_19)
{
  cr_assert_eq(my_strlen("Ceci est une string"), 19);
}

Test(Length, str_equal_deux)
{
  cr_assert_eq(my_strlen("Deux"), 1);
}
