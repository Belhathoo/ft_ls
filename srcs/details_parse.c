/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   details_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:17:55 by belhatho          #+#    #+#             */
/*   Updated: 2019/11/18 04:36:35 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

char	*do_path(char *name, char *d_name)
{
	char	*path;
	char	*tmp;

	if (ft_strcmp(name, ".") == 0 && d_name[0] == '/')
		path = ft_strdup(d_name);
	else if ((name[0] == '/' && name[1] == '\0') ||
					name[ft_strlen(name) - 1] == '/' || d_name[0] == '/')
		path = ft_strjoin(name, d_name);
	else
	{
		tmp = ft_strjoin(name, "/");
		path = ft_strjoin(tmp, d_name);
		ft_strdel(&tmp);
	}
	return (path);
}

char	associate_type(struct stat st)
{
	char c;

	if (S_ISBLK(st.st_mode))
		c = 'b';
	else if (S_ISCHR(st.st_mode))
		c = 'c';
	else if (S_ISFIFO(st.st_mode))
		c = 'p';
	else if (S_ISLNK(st.st_mode))
		c = 'l';
	else if (S_ISSOCK(st.st_mode))
		c = 's';
	else if (S_ISDIR(st.st_mode))
		c = 'd';
	else if (S_ISREG(st.st_mode))
		c = '-';
	else
		c = '?';
	return (c);
}

char	*associate_chmod(struct stat st)
{
	char *chmod;

	chmod = ft_strnew(10);
	chmod[0] = associate_type(st);
	chmod[1] = (st.st_mode & S_IRUSR) ? 'r' : '-';
	chmod[2] = (st.st_mode & S_IWUSR) ? 'w' : '-';
	chmod[3] = (st.st_mode & S_IXUSR) ? 'x' : '-';
	chmod[4] = (st.st_mode & S_IRGRP) ? 'r' : '-';
	chmod[5] = (st.st_mode & S_IWGRP) ? 'w' : '-';
	chmod[6] = (st.st_mode & S_IXGRP) ? 'x' : '-';
	chmod[7] = (st.st_mode & S_IROTH) ? 'r' : '-';
	chmod[8] = (st.st_mode & S_IWOTH) ? 'w' : '-';
	chmod[9] = (st.st_mode & S_IXOTH) ? 'x' : '-';
	if (S_ISUID & st.st_mode)
		chmod[3] = chmod[3] == '-' ? 'S' : 's';
	if (S_ISGID & st.st_mode)
		chmod[6] = chmod[6] == '-' ? 'S' : 's';
	if (S_ISVTX & st.st_mode)
		chmod[9] = chmod[9] == '-' ? 'T' : 't';
	return (chmod);
}
