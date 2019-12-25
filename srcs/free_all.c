/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 03:21:52 by belhatho          #+#    #+#             */
/*   Updated: 2019/11/21 11:32:19 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	ft_clean_l_args(t_arguments args)
{
	int		i;

	i = 0;
	while (i < args.ndir)
	{
		ft_strdel(&args.directories[i]);
		i++;
	}
	free(args.directories);
	i = 0;
	while (i < args.nparam)
	{
		ft_strdel(&args.param[i]);
		i++;
	}
	(args.nparam != 0) ? free(args.param) : 0;
}

void	ft_clean_lst(t_args **args, int opt)
{
	t_args	*h;
	t_args	*n;

	h = *args;
	while (h)
	{
		n = h->next;
		ft_clean_data(&h->data, opt);
		free(h);
		h = n;
	}
	free(h);
}

void	ft_clean_data(t_data **data, int opt)
{
	t_data	*d;

	d = *data;
	if (d->chmod[0] == 'l')
		ft_strdel(&d->linkto);
	if (d->chmod[0] == 'b' || d->chmod[0] == 'c')
	{
		ft_strdel(&d->maj);
		ft_strdel(&d->min);
	}
	if ((opt & L) || (opt & G))
	{
		(opt & G) ? 0 : ft_strdel(&d->uid);
		ft_strdel(&d->gid);
		ft_strdel(&d->size);
		ft_strdel(&d->nlink);
		ft_strdel(&d->time_month);
		ft_strdel(&d->time_rest);
	}
	ft_strdel(&d->str);
	ft_strdel(&d->path);
	ft_strdel(&d->chmod);
	free(d);
}

void	free_tab(char ***tab)
{
	int		i;
	char	**tmp;

	tmp = *tab;
	i = 0;
	while (tmp[i])
	{
		ft_strdel(&tmp[i]);
		i++;
	}
	free(tmp);
	tmp = NULL;
}
