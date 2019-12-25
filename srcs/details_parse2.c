/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   details_parse2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 04:00:51 by belhatho          #+#    #+#             */
/*   Updated: 2019/11/19 18:56:28 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void			get_time(t_args *param, int opt)
{
	time_t		curtime;
	char		*yearf;
	char		*yearn;
	struct stat	sb;

	lstat(param->data->path, &sb);
	param->data->time_sort = (opt & U) ? st.st_atime : st.st_mtime;
	param->data->time_month = (opt & U) ? ft_strsub(ctime(&sb.st_atime), 4, 7)
		: ft_strsub(ctime(&sb.st_mtime), 4, 7);
	time(&curtime);
	yearf = (opt & U) ? ft_strsub(ctime(&sb.st_atime), 20, 4)
		: ft_strsub(ctime(&sb.st_mtime), 20, 4);
	yearn = ft_strsub(ctime(&curtime), 20, 4);
	if ((time(&curtime) - param->data->time_sort) > 15778800)
		param->data->time_rest = ft_strdup(yearf);
	else
	{
		if (opt & U)
			param->data->time_rest = ft_strsub(ctime(&sb.st_atime), 11, 5);
		else
			param->data->time_rest = ft_strsub(ctime(&sb.st_mtime), 11, 5);
	}
	ft_strdel(&yearn);
	ft_strdel(&yearf);
}

void			get_maj_min(t_args *param)
{
	char		*strmaj;
	int			maj;
	int			min;

	maj = major(st.st_rdev);
	min = minor(st.st_rdev);
	strmaj = ft_itoa(maj);
	param->data->maj = ft_strjoin(strmaj, ",");
	param->data->min = ft_itoa(min);
	free(strmaj);
}

char			*ft_readlink(char *path)
{
	char		*buf;
	size_t		bufsize;

	bufsize = st.st_size + 1;
	if (st.st_size == 0)
		bufsize = PATH_MAX;
	buf = ft_strnew(bufsize);
	readlink(path, buf, bufsize);
	return (buf);
}

void			get_data(t_args *args, int opt)
{
	if ((opt & L) || (opt & G))
	{
		args->data->uid = (opt & G) ? 0 : ft_strdup(get_uid(st));
		args->data->gid = ft_strdup(get_gid(st));
		args->data->size = get_size(st);
		args->data->nlink = get_nlink(st);
		get_time(args, opt);
	}
	args->data->time_sort = (opt & U) ? st.st_atime : st.st_mtime;
	args->data->chmod = associate_chmod(st);
	args->data->tsize = st.st_size;
	if (args->data->chmod[0] == 'l')
		args->data->linkto = ft_readlink(args->data->path);
}

void			get_all_data(t_args *curr, char *dur, char *name, int opt)
{
	curr->data = create_data();
	curr->data->path = do_path(dur, name);
	lstat(curr->data->path, &st);
	curr->data->str = ft_strdup(name);
	get_data(curr, opt);
	if (curr->data->chmod[0] == 'c' || curr->data->chmod[0] == 'b')
		get_maj_min(curr);
}
