/*
** EPITECH PROJECT, 2017
** CSFML MyHunter
** File description:
** Bootstrap
*/

struct stat {
	dev_t     st_dev;      /* ID du périphérique contenant le fichier */
	ino_t     st_ino;      /* Numéro inœud */
	mode_t    st_mode;     /* Protection */
	nlink_t   st_nlink;    /* Nb liens matériels */
	uid_t     st_uid;      /* UID propriétaire */
	gid_t     st_gid;      /* GID propriétaire */
	dev_t     st_rdev;     /* ID périphérique (si fichier spécial) */
	off_t     st_size;     /* Taille totale en octets */
	blksize_t st_blksize;  /* Taille de bloc pour E/S */
	blkcnt_t  st_blocks;   /* Nombre de blocs alloués */
	time_t    st_atime;    /* Heure dernier accès */
	time_t    st_mtime;    /* Heure dernière modification */
	time_t    st_ctime;    /* Heure dernier changement état */
};

struct dirent {
	ino_t          d_ino;       /* numéro d'inœud */
	off_t          d_off;       /* décalage jusqu'à la dirent suivante */
	unsigned short d_reclen;    /* longueur de cet enregistrement */
	unsigned char  d_type;      /* type du fichier */
	char           d_name[256]; /* nom du fichier */
};
