/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** flags.c
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

int without_flag(char *my_path)
{
	DIR *dir = NULL;
	struct dirent *file = NULL;

	dir = opendir(my_path);
	if (dir == NULL)
		return (84);
	while ((file = readdir(dir)) != NULL) {
		if (file->d_name[0] != '.')
			my_printf("%s\n", file->d_name);
	}
	closedir(dir);
	return (0);
}

int flag_a(char *my_path)
{
	DIR *dir = NULL;
	struct dirent *file = NULL;

	dir = opendir(my_path);
	if (dir == NULL)
		return (84);
	while ((file = readdir(dir)) != NULL) {
		my_printf("%s\n", file->d_name);
	}
	closedir(dir);
	return (0);
}

int flag_l(char *my_path)
{
	DIR *dir = NULL;
	struct dirent *file = NULL;
	struct stat sb;
	char *mytime = malloc(sizeof(char) * 14);

	if (mytime == NULL)
		return (84);
	dir = opendir(my_path);
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

int flag_r(char *my_path)
{
	DIR *dir = NULL;
	struct dirent *file = NULL;

	dir = opendir(my_path);
	if (dir == NULL)
		return (84);
	while ((file = readdir(dir)) != NULL) {
		my_printf("%s\n", file->d_name);
	}
	closedir(dir);
	return (0);
}
