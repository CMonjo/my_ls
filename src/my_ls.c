/*
** EPITECH PROJECT, 2017
** Project my_ls
** File description:
** Main file
*/

#include "my_ls.h"

void which_flag_exception(char *my_path, int nbr_flags, int nbr_path)
{
	if (nbr_flags == 0)
		without_flag(my_path);
	if (nbr_path > 1)
		my_printf("\n");
}

void which_flag(char *my_path, char *my_flag, int nbr_flags, int nbr_path)
{
	if (my_flag[3] == '1')
		flag_my_ls_a(my_path);
	else if (my_flag[0] == '1')
		flag_my_ls_l(my_path);
	which_flag_exception(my_path, nbr_flags, nbr_path);
}

void calculate_path(int ac, char **av, char *my_flag)
{
	char *my_path = malloc(sizeof(char) * ac * 3);
	int nbr_path = 0;
	int nbr_flags = 0;
	int count = 1;
	int count_flags = 0;
	int key = 0;

	nbr_path = nbr_of_path(av, nbr_path);
	nbr_flags = nbr_of_flags(av, count_flags);
	key = nbr_path;
	if (nbr_path == 0)
		which_flag(".", my_flag, nbr_flags, nbr_path);
	while (nbr_path > 0) {
		my_path = which_paths(av, &count);
		if (key > 1)
			my_printf("%s:\n", my_path);
		which_flag(my_path, my_flag, nbr_flags, nbr_path);
		nbr_path--;
	}
}

int calculate_flags(int ac, char **av)
{
	char *my_flag = malloc(sizeof(char *) * 100);
	int i = 0;

	if (my_flag == NULL)
		return (84);
	my_flag[0] = '0';
	my_flag[1] = '0';
	my_flag[2] = '0';
	my_flag[3] = '0';
	while (av[i]) {
		if (av[i][0] == '-')
			my_flag = flags_for_my_ls(av[i], my_flag);
		i++;
	}
	calculate_path(ac, av, my_flag);
	free(my_flag);
	return (0);
}

int main(int ac, char **av)
{
	char *my_path = malloc(sizeof(char) * ac * 3);

	if (my_path == NULL)
		return (84);
	if (ac == 1) {
		my_path = ".";
		without_flag(my_path);
	}
	else if (ac == 2 && av[1][0] != '-') {
		my_path = av[1];
		without_flag(my_path);
	} else
		calculate_flags(ac, av);
	return (0);
}
