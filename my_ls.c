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

int my_right(struct stat sb, char *mytime)
{
	struct passwd *name;
	struct group *group;

	name = getpwuid(sb.st_uid);
	group = getgrgid(sb.st_gid);
	my_type(sb);
	my_printf((sb.st_mode & S_IRUSR) ? "r" : "-");
	my_printf((sb.st_mode & S_IWUSR) ? "w" : "-");
	my_printf((sb.st_mode & S_IXUSR) ? "x" :  "-");
	my_printf((sb.st_mode & S_IRGRP) ? "r" : "-");
	my_printf((sb.st_mode & S_IWGRP) ? "w" : "-");
	my_printf((sb.st_mode & S_IXGRP) ? "x" : "-");
	my_printf((sb.st_mode & S_IROTH) ? "r" : "-");
	my_printf((sb.st_mode & S_IWOTH) ? "w" : "-");
	my_printf((sb.st_mode & S_IXOTH) ? "x" : "-");
	my_printf(" %d", (int)sb.st_nlink);
	my_printf(" %s", name->pw_name);
	my_printf(" %s", group->gr_name);
	my_printf(" %lld", sb.st_size);
	my_time(mytime, sb);
	my_printf(" %s", mytime);
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
	my_printf("slt\n");
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
