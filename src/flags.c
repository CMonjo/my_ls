/*
** EPITECH PROJECT, 2017
** Project my_ls
** File description:
** Flags file
*/

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

int flag_my_ls_a(char *my_path)
{
	DIR *dir = NULL;
	struct dirent *file = NULL;

	dir = opendir(my_path);
	if (dir == NULL)
		return (84);
	while ((file = readdir(dir)) != NULL)
		my_printf("%s\n", file->d_name);
	closedir(dir);
	return (0);
}

int flag_my_ls_l(char *my_path)
{
	DIR *dir = NULL;
	struct dirent *file = NULL;
	struct stat sb;
	char *mytime = malloc(sizeof(char) * 13);

	dir = opendir(my_path);
	if (mytime == NULL || dir == NULL)
		return (84);
	while ((file = readdir(dir)) != NULL) {
		if (file->d_name[0] != '.') {
			lstat(file->d_name, &sb);
			my_right(sb, mytime);
			my_printf(" %s\n", file->d_name);
		}
	}
	closedir(dir);
	return (0);
}

int flag_my_ls_R(char *my_path)
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
