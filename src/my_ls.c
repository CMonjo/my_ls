/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** .c
*/

#include "my_ls.h"

void which_flag(char **av, char *my_path, char *my_flag, int nbr_flags)
{
	if (nbr_flags == 0) {
		without_flag(my_path);
	}
	if (my_flag[0] == '0' && my_flag[1] == '0' && my_flag[2] == '0' && my_flag[3] == '1') {
		flag_a(my_path);
	}
	else if (my_flag[0] == '1' && my_flag[1] == '0' && my_flag[2] == '0' && my_flag[3] == '0') {
		flag_l(my_path);
	}
	else if (av[1][0] == '-' && av[1][1] == 'r') {
		flag_r(my_path);
	}
}

//FAIRE STRUCT
int calculate_path(int ac, char **av, char *my_flag)
{
	char *my_path = malloc(sizeof(char) * ac * 3);
	int nbr_path = 0;
	int nbr_flags = 0;
	int count = 1;
	int count_flags = 0;
	int key = 0;

	if (my_path == NULL)
		return (84);
	nbr_path = nbr_of_path(av, nbr_path);
	nbr_flags = nbr_of_flags(av, count_flags);
	key = nbr_path;
	if (nbr_path == 0)
		which_flag(av, ".", my_flag, nbr_flags);
	while (nbr_path > 0) {
		my_path = paths(av, &count);
		if (key > 1)
			my_printf("%s:\n", my_path);
		which_flag(av, my_path, my_flag, nbr_flags);
		nbr_path--;
	}
	return (0);
}

int calculate_flags(int ac, char **av)
{
	char *my_flag = malloc(sizeof(char) * 5);
	int i = 0;

	if (my_flag == NULL)
		return (84);
	my_flag[0] = '0';
	my_flag[1] = '0';
	my_flag[2] = '0';
	my_flag[3] = '0';
	while (av[i] != '\0') {
		if (av[i][0] == '-')
			my_flag = ls_flags(av[i], my_flag);
		i++;
	}
	//my_printf("FLAGS l | r | R | a == %s\n", my_flag);
	calculate_path(ac, av, my_flag);
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
