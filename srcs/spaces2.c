/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 04:34:53 by aait-el-          #+#    #+#             */
/*   Updated: 2019/11/23 20:09:19 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void		ft_set_spaces(size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_putchar(' ');
		i++;
	}
}

void		spaces_usr(t_data *data, int max)
{
	ft_putstrs(data->uid, " ", " ", 0);
	ft_set_spaces(max - ft_strlen(data->uid));
}

int			get_max_lent_usr(t_args *args)
{
	int		max;
	int		lent;

	max = 0;
	while (args)
	{
		lent = ft_strlen(args->data->uid);
		if (lent >= max)
			max = lent;
		args = args->next;
	}
	return (max);
}

void		spaces_grp(t_data *data, int max)
{
	ft_putstrs(data->gid, " ", " ", " ");
	ft_set_spaces(max - ft_strlen(data->gid));
}

int			get_max_lent_grp(t_args *args)
{
	int		max;
	int		lent;

	max = 0;
	while (args)
	{
		lent = ft_strlen(args->data->gid);
		if (lent >= max)
			max = lent;
		args = args->next;
	}
	return (max);
}
