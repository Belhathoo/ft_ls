/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 04:36:06 by aait-el-          #+#    #+#             */
/*   Updated: 2019/11/23 20:09:28 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int				get_max_lent_size(t_args *args)
{
	int			max;
	int			len;

	max = 0;
	while (args)
	{
		len = ft_strlen(args->data->size);
		(len >= max) ? max = ft_strlen(args->data->size) : 0;
		args = args->next;
	}
	return (max);
}

void			spaces_size(t_data *data, int max)
{
	ft_set_spaces(max - ft_strlen(data->size));
	ft_putstrs(data->size, " ", 0, 0);
}

int				get_max_lent_nlink(t_args *args)
{
	int			max;
	int			lent;

	max = 0;
	while (args)
	{
		lent = ft_strlen(args->data->nlink);
		if (lent >= max)
			max = lent;
		args = args->next;
	}
	return (max);
}

void			spaces_nlink(t_data *data, int max)
{
	ft_set_spaces(max - ft_strlen(data->nlink));
	ft_putstrs(data->nlink, " ", 0, 0);
}
