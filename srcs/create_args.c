/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:18:22 by belhatho          #+#    #+#             */
/*   Updated: 2019/11/20 17:57:57 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_args				*create_args(void)
{
	t_args			*args;

	if (!(args = (t_args *)malloc(sizeof(t_args))))
		return (NULL);
	args->next = NULL;
	return (args);
}

t_data				*create_data(void)
{
	t_data			*data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	data->str = NULL;
	data->path = NULL;
	data->chmod = NULL;
	data->uid = NULL;
	data->gid = NULL;
	data->size = NULL;
	data->nlink = NULL;
	data->linkto = NULL;
	data->maj = NULL;
	data->min = NULL;
	data->time_month = NULL;
	data->time_rest = NULL;
	return (data);
}

int					ft_pstrlen(char **tab)
{
	int				i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
