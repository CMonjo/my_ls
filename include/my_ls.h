/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** Définition fonctions
*/

#ifndef _MY_LS_
	#define _MY_LS_
	char *my_find_name(char *str);
	void my_type_2(struct stat sb);
	void my_type(struct stat sb);
	char *my_time(char *mytime, struct stat sb);
	void my_right(struct stat sb, char *mytime);
	int flag_l(DIR *dir, struct dirent *file, char *av[]);
	int without_flag(DIR *dir, struct dirent *file);
	int flag_a(DIR *dir, struct dirent *file);
#endif
