/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:04:05 by belhatho          #+#    #+#             */
/*   Updated: 2019/11/19 15:43:52 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	sort_ascii(t_args *p1)
{
	t_args	*tmp1;
	t_args	*tmp2;

	tmp1 = p1;
	if (!p1)
		return ;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (ft_strcmp(tmp1->data->str, tmp2->data->str) > 0)
				switch_data(tmp1, tmp2);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

void	sort_time(t_args *p1)
{
	t_args	*tmp1;
	t_args	*tmp2;

	tmp1 = p1;
	if (!p1)
		return ;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->data->time_sort < tmp2->data->time_sort)
				switch_data(tmp1, tmp2);
			if (tmp1->data->time_sort == tmp2->data->time_sort)
			{
				if (ft_strcmp(tmp1->data->str, tmp2->data->str) > 0)
					switch_data(tmp1, tmp2);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

void	sort_size(t_args *p1)
{
	t_args	*tmp1;
	t_args	*tmp2;

	tmp1 = p1;
	if (!p1)
		return ;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->data->tsize < tmp2->data->tsize)
				switch_data(tmp1, tmp2);
			if (tmp1->data->tsize == tmp2->data->tsize)
			{
				if (ft_strcmp(tmp1->data->str, tmp2->data->str) > 0)
					switch_data(tmp1, tmp2);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}
