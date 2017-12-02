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
			printf("%s\n", file->d_name);
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
	while ((file = readdir(dir)) != NULL)
		printf("%s\n", file->d_name);
	closedir(dir);
	return (0);
}

int flag_l(char *my_path)
{
	DIR *dir = NULL;
	struct dirent *file = NULL;
	struct stat sb;
	char *mytime = malloc(sizeof(char) * 14);

	dir = opendir(my_path);
	if (mytime == NULL || dir == NULL)
		return (84);
	//printf("total %d\n", sb.st_blksize * 2);
	while ((file = readdir(dir)) != NULL) {
		if (file->d_name[0] != '.') {
			stat(file->d_name, &sb);
			my_right(sb, mytime);
			printf(" %s\n", file->d_name);
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
		printf("%s\n", file->d_name);
	}
	closedir(dir);
	return (0);
}
