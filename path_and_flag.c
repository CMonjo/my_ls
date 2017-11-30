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


int nbr_of_path(char **av, int count) {
	int i = 1;

	while (av[i] != NULL) {
		if (av[i][0] != '-')
			count++;
		i++;
	}
	return (count);
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
