/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** .c
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

char *my_find_name(char *str)
{
	char* tmp = malloc(sizeof(char) * my_strlen(str));
	int i = 0;

	if (tmp == NULL)
		exit (84);
	my_revstr(str);
	while (str[i] != '/') {
		tmp[i] = str[i];
		i++;
	}
	my_revstr(tmp);
	free(tmp);
	return (tmp);
}

void which_flag(char **av, char *my_path)
{
	// DIR *dir = NULL;
	// struct dirent *file = NULL;

	printf("my_path : %s\n", my_path);
	// int a = 0;
	// int l = 0;
	// int r = 0;
	// int R = 0;
	// int d = 0;

	if (av[1][0] == '-' && av[1][1] == 'a') {
		flag_a(my_path);
	}
	else if (av[1][0] == '-' && av[1][1] == 'l') {
		flag_l(my_path);
	}
	else if (av[1][0] == '-' && av[1][1] == 'r') {
		flag_r(my_path);
	}
}

int main(int ac, char **av)
{
	char *my_path = malloc(sizeof(char *) * ac * 3);
	int nbr_path = 0;
	int count = 1;

	if (my_path == NULL)
		return (84);
	if (ac == 1) {
		my_path = ".";
		without_flag(my_path);
	}
	else if (ac == 2 && av[1][0] != '-') {
		my_path = av[1];
		without_flag(my_path);
	} else {
		//FAIRE PAREIL AVEC LES - POUR LES FLAGS
		nbr_path = nbr_of_path(av, nbr_path);
		while (nbr_path > 0) {
			my_path = paths(av, &count);
			//printf("%s:\n", my_path);
			which_flag(av, my_path);
			nbr_path--;
		}
	}
	return (0);
}
