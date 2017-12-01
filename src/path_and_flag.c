/*
** EPITECH PROJECT, 2017
** Project my_ls
** File description:
** Path and flag file
*/

#include "my_ls.h"

int nbr_of_path(char **av, int count)
{
	int i = 1;

	while (av[i] != NULL) {
		if (av[i][0] != '-')
			count++;
		i++;
	}
	return (count);
}

int nbr_of_flags(char **av, int count)
{
	int i = 1;

	while (av[i] != NULL) {
		if (av[i][0] == '-')
			count++;
		i++;
	}
	return (count);
}

char *ls_flags(char *av, char *my_flag)
{
	int i = 1;

	while (av[i] != '\0') {
		switch (av[i]) {
			case 'l':
				my_flag[0] = '1';
				break;
			case 'r':
				my_flag[1] = '1';
				break;
			case 'R':
				my_flag[2] = '1';
				break;
			case 'a':
				my_flag[3] = '1';
				break;
		}
		i++;
	}
	return (my_flag);
}

char *paths(char **av, int *count)
{
	char *path = " ";

	while (av[*count] != NULL) {
		if (av[*count][0] != '-') {
			path = av[*count];
			(*count)++;
			return (path);
		} else
			(*count)++;
	}
	return (path);
}
