/*
** EPITECH PROJECT, 2017
** Project my_ls
** File description:
** Flag l file
*/

#include "my_ls.h"

void my_type_of_file_second(struct stat sb)
{
	switch (sb.st_mode & S_IFMT) {
		case S_IFIFO:
			printf("p");
			break;
		case S_IFLNK:
			printf("l");
			break;
		case S_IFREG:
			printf("-");
			break;
		case S_IFSOCK:
			printf("s");
			break;
	}
}

void my_type_of_file(struct stat sb)
{
	switch (sb.st_mode & S_IFMT) {
		case S_IFBLK:
			printf("b");
			break;
		case S_IFCHR:
			printf("c");
			break;
		case S_IFDIR:
			printf("d");
			break;
	}
	my_type_of_file_second(sb);
}

char *my_time(char *mytime, struct stat sb)
{
	mytime[0] = ctime(&sb.st_mtime)[4] + 32;
	mytime[1] = ctime(&sb.st_mtime)[5];
	mytime[2] = ctime(&sb.st_mtime)[6];
	mytime[3] = '.';
	mytime[4] = ' ';
	mytime[5] = ctime(&sb.st_mtime)[8];
	mytime[6] = ctime(&sb.st_mtime)[9];
	mytime[7] = ' ';
	mytime[8] = ctime(&sb.st_mtime)[11];
	mytime[9] = ctime(&sb.st_mtime)[12];
	mytime[10] = ':';
	mytime[11] = ctime(&sb.st_mtime)[14];
	mytime[12] = ctime(&sb.st_mtime)[15];
	mytime[13] = '\0';
	return (mytime);
}

void my_right(struct stat sb, char *mytime)
{
	struct passwd *name;
	struct group *group;

	name = getpwuid(sb.st_uid);
	group = getgrgid(sb.st_gid);
	my_type_of_file(sb);
	printf((sb.st_mode & S_IRUSR) ? "r" : "-");
	printf((sb.st_mode & S_IWUSR) ? "w" : "-");
	printf((sb.st_mode & S_IXUSR) ? "x" : "-");
	printf((sb.st_mode & S_IRGRP) ? "r" : "-");
	printf((sb.st_mode & S_IWGRP) ? "w" : "-");
	printf((sb.st_mode & S_IXGRP) ? "x" : "-");
	printf((sb.st_mode & S_IROTH) ? "r" : "-");
	printf((sb.st_mode & S_IWOTH) ? "w" : "-");
	printf((sb.st_mode & S_IXOTH) ? "x" : "-");
	printf(" %d", (int)sb.st_nlink);
	printf(" %s", name->pw_name);
	printf(" %s", group->gr_name);
	//printf(" %lld", sb.st_size);
	printf(" %s", my_time(mytime, sb));
}
