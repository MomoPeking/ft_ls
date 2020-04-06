#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <stdlib.h>        // exit();
# include <dirent.h>        // opendir(), readdir(), closedir();
# include <sys/stat.h>      // stat();
# include <sys/xattr.h>     // listxattr();
# include <pwd.h>           // getpwuid();
# include <grp.h>           // getgrgid();
# include <time.h>          // ctime();

typedef struct  s_flag
{
    int     f_R : 1;
    int     f_l : 1;
    int     f_a : 1;
    int     f_r : 1;
    int     f_t : 1;
}               t_flag;

typedef struct  s_dir
{
    t_list          *list;
    int             namelen;
    long long       blocks;
    unsigned int    linklen;
    unsigned int    sizelen;
}               t_dir;

typedef struct  s_info
{
    char            *file_mode;
    unsigned short  nlink;
    char            *pw_name;
    char            *gr_name;
    long long       size;
    char            *time;
    char            *name;
    char            *addr;
    t_dir           *dir;
}               t_info;

//  if (file_mode[0] == 'd', dir != NULL)

char            *set_mode(unsigned short mode, unsigned char tof, char *name);

/*
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
*/

#endif