#include "ft_ls.h"

void    ft_exit(char c)
{
    if (c == 1)
    {
        ft_putstr("Invalid input, please use flag -Rlart or no flag to run the program.\n"); 
        exit(1);
    }
}

void    store_flags(char **av, t_flag *flag)
{
    if (*av[1] == '-')
    {
        if (!*(av[1] + 1))
            ft_exit(1);              
        while (*av[1])
        {
            av[1]++;
            if (*av[1] && ft_strchr("Rlart", *av[1]) == NULL)
                ft_exit(1);
            if (*av[1])
            {
                (*av[1] == 'R') ? (flag->f_R = 1) : flag->f_R;
                (*av[1] == 'l') ? (flag->f_l = 1) : flag->f_l;
                (*av[1] == 'a') ? (flag->f_a = 1) : flag->f_a;
                (*av[1] == 'r') ? (flag->f_r = 1) : flag->f_r;
                (*av[1] == 't') ? (flag->f_t = 1) : flag->f_t;
                // 注意，此處有flag則為非0值，而不一定是1；無flag則為0。
            }        
        }
    }
    else
        ft_exit(1);  
}

//  考慮儲存，不考慮排序。(遍歷所有！)
//  再使用lstnew來完成

void    temp()
{
    DIR             *mydir;
    struct dirent   *files;
    struct stat     buf;






//    t_list          *list;
    t_info          *info;

    int             namelen;
    long long       blocks;
    unsigned int    linklen;
    unsigned int    sizelen;

    mydir = opendir(".");
    info = (t_info *)ft_memalloc(sizeof(t_info));

//  以下四個參數，每個文件夾各不同。考慮清楚如何儲存？
    blocks = 0;
    namelen = 0;
    linklen = 0;
    sizelen = 0;

    while ((files = readdir(mydir)) != NULL)
    {
        stat(files->d_name, &buf);
        info->file_mode = set_mode(buf.st_mode, files->d_type, files->d_name);
        info->nlink = buf.st_nlink;
        info->pw_name = ft_strdup(getpwuid(buf.st_uid)->pw_name);
        info->gr_name = ft_strdup(getgrgid(buf.st_gid)->gr_name);
        info->size = buf.st_size;
        info->time = ft_strsub(ctime(&buf.st_mtimespec.tv_sec), 4, 12);
        info->name = ft_strdup(files->d_name);
        info->addr = ft_strdup(".");
        info->dir = NULL;

        blocks += buf.st_blocks;
        if (files->d_namlen > namelen)
            namelen = files->d_namlen;
        if (info->nlink > linklen)
            linklen = info->nlink;
        if (info->size > sizelen)
            sizelen = info->size;

        ft_printf("%s %8s %s\n", info->file_mode, info->name, info->time);

        free(info->file_mode);
        free(info->pw_name);
        free(info->gr_name);
        free(info->time);
        free(info->name);
        free(info->addr);
    }
    linklen = ft_nbrlen(linklen);
    sizelen = ft_nbrlen(sizelen);

    ft_printf("linklen: %d, sizelen: %d, namelen: %d\n", linklen, sizelen, namelen);
//    ft_printf("total: %d\n", blocks);

    free(info);
    closedir(mydir);
}

int     main(int ac, char **av)
{
    t_flag     *flag;
    t_list     *store;

    flag = (t_flag *)ft_memalloc(sizeof(t_flag));
    if (ac < 2)
        temp();
//        ft_putstr("Working on it!\n");
    if (ac == 2)
    {
        store_flags(av, flag);
//      ft_printf("R: %d, l: %d, a: %d, r: %d, t: %d\n", flag->f_R, flag->f_l, flag->f_a, flag->f_r, flag->f_t);      
    }
//    system("leaks ft_ls");    
    return (0);    
}

//  下一步：完成ac < 2的情況
//  先把主要功能做出來，不考慮錯誤!
//  sortname