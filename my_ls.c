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

int without_flag(DIR *dir, struct dirent *file)
{
	dir = opendir(".");
	if (dir == NULL)
		return (84);
	while ((file = readdir(dir)) != NULL) {
		if (file->d_name[0] != '.')
			my_printf("%s\n", file->d_name);
	}
	closedir(dir);
	return (0);
}

int flag_a(DIR *dir, struct dirent *file)
{
	dir = opendir(".");
	if (dir == NULL)
		return (84);
	while ((file = readdir(dir)) != NULL) {
		my_printf("%s\n", file->d_name);
	}
	closedir(dir);
	return (0);
}

int flag_l(DIR *dir, struct dirent *file, char *av[])
{
	struct stat sb;
	char *mytime = malloc(sizeof(char) * 14);

	if (mytime == NULL)
		return (84);
	dir = opendir(av[2]);
	if (dir == NULL)
		return (84);
	my_printf("total %d\n", sb.st_blksize * 2);
	while ((file = readdir(dir)) != NULL) {
		if (file->d_name[0] != '.') {
			stat(file->d_name, &sb);
			my_right(sb, mytime);
			my_printf(" %s\n", file->d_name);
		}
	}
	closedir(dir);
	return (0);
}

int flag_r(DIR *dir, struct dirent *file)
{
	my_printf("test\n");
	dir = opendir(".");
	if (dir == NULL)
		return (84);
	while ((file = readdir(dir)) != NULL) {
		my_printf("%s\n", file->d_name);
	}
	closedir(dir);
	return (0);
}

int main(int ac, char **av)
{
	DIR *dir = NULL;
	struct dirent *file = NULL;
	char *str = malloc(sizeof(char *) * ac);

	if (str == NULL)
		return (84);
	if (ac == 1 || av[1][0] == '.')
		without_flag(dir, file);
	else if (av[1][0] == '-' && av[1][1] == 'a')
		flag_a(dir, file);
	else if (av[1][0] == '-' && av[1][1] == 'l')
		flag_l(dir, file, av);
	else if (av[1][0] == '-' && av[1][1] == 'r')
		flag_r(dir, file);

	return 0;
}
