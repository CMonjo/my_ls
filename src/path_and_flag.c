/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** which flags and paths.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>
#include "my.h"
#include "printf.h"
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










char *ls_flags(char *av, char *my_flags)
{
	int i = 1;

	while (av[i] != '\0') {
		switch (av[i]) {
			case 'l':
				my_flags[0] = '1';
				break;
			case 'r':
				my_flags[1] = '1';
				break;
			case 'a':
				my_flags[2] = '1';
				break;
			case 'R':
				my_flags[3] = '1';
				break;
		}
		i++;
	}
	return (my_flags);
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
