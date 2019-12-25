/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:29:00 by belhatho          #+#    #+#             */
/*   Updated: 2019/11/24 02:14:33 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <stdlib.h>
# include "../srcs/libft/libft.h"
# include <dirent.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <errno.h>
# include <sys/ioctl.h>

# define PATH_MAX 1024

# define A 1
# define L 2
# define RR 4
# define R 8
# define F 16
# define T 32
# define S 128
# define G 256
# define U 512
# define FF 1024
# define D 2048

struct group		*gid;
struct passwd		*uid;
struct stat			st;
struct dirent		*file;

typedef struct		s_arguments
{
	int				nparam;
	int				ndir;
	char			**directories;
	char			**param;
}					t_arguments;

typedef struct		s_data
{
	char			*str;
	char			*path;
	char			*chmod;
	char			*uid;
	char			*gid;
	char			*size;
	int				tsize;
	char			*nlink;
	char			*linkto;
	char			*maj;
	char			*min;
	char			*time_month;
	char			*time_rest;
	int				time_sort;
}					t_data;

typedef struct		s_args
{
	t_data			*data;
	struct s_args	*next;
}					t_args;

t_args				*create_args(void);
t_data				*create_data(void);

t_arguments			param_store(int ac, char **av, int opt);
t_arguments			arg_isdir(char **av, int opt);
t_args				*dirdata(char **dur, int opt);
t_args				*type_param(char **args, int opt);
t_args				*get_dir_content(char *dur, int opt);
void				read_dir(char *name, int opt);
char				**param_parse(int nparam, char **av, int opt);
char				associate_type(struct stat st);
void				ft_check(char **av);
void				ft_alloc(t_args **head, t_args **curr, t_args **tt);

int					check_options(char **av);
void				add_option(int *opt, char **av);

char				**merge_all(t_arguments args);
int					ft_pstrlen(char **tab);

char				*do_path(char *name, char *d_name);
char				*associate_chmod(struct stat st);
char				*get_uid(struct stat st);
char				*get_gid(struct stat st);
char				*get_size(struct stat st);
char				*get_nlink(struct stat st);
char				*ft_readlink(char *head);
char				*get_mod_time(struct stat st);
char				*get_acc_time(struct stat st);
void				get_maj_min(t_args *args);
void				get_total_nblocks(t_args	*args);
void				get_data(t_args *args, int opt);
void				get_all_data(t_args *curr, char *dur, char *name, int opt);

void				ft_sortargs(char **tab, int opt);
void				ft_sortascii(char **tab);
void				ft_sort_time(char **tab, int opt);
void				ft_sort_size(char **tab);
void				ft_rev_sort(char **tab);
void				switch_data(t_args *d1, t_args *d2);
void				sort_list(t_args *p1, int opt);
void				sort_size(t_args *p1);
void				sort_time(t_args *p1);
void				sort_ascii(t_args *p1);
t_args				*ft_reverse_lst(t_args *lst);
void				switch_tab(char **t, int i);

void				ft_set_spaces(size_t size);
int					get_max_lent_usr(t_args *args);
void				spaces_usr(t_data *data, int max);
int					get_max_lent_size(t_args *args);
void				spaces_size(t_data *data, int max);
int					get_max_lent_nlink(t_args *args);
void				spaces_nlink(t_data *data, int max);
int					get_max_lent_grp(t_args *args);
void				spaces_grp(t_data *data, int max);
void				spaces_minor(t_data *data, int max);
void				spaces_major(t_data *data, int max);

void				ft_putstrs(char *s1, char *s2, char *s3, char *s4);
void				ft_print_details_param(t_data *data, int opt);
void				display(t_args *args, int opt);
void				ft_option_f(t_data *data);
int					*get_lenghts(t_args *args, int opt);
void				add_spaces(t_data *data, int *max, int opt);
int					print_all(t_args *head, int opt);

void				dirdata_display(int ac, char **av, int opt);
char				**check_all(int ac, char **av, int opt);
void				param_display(t_args *param, int opt, int ndir);
void				directories_display(char **dirs, int nparam, int opt);
int					check(t_args *head);

void				ft_print_strs(t_args *args, int max);
int					get_max_str(t_args *args);

void				ft_clean_l_args(t_arguments args);
void				ft_clean_lst(t_args **args, int opt);
void				ft_clean_data(t_data **data, int opt);
void				free_tab(char ***tab);

#endif
