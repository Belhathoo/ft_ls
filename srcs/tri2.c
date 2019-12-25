/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 04:14:23 by aait-el-          #+#    #+#             */
/*   Updated: 2019/11/21 11:40:12 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	sort_list(t_args *args, int opt)
{
	if (opt & S)
		sort_size(args);
	else if (opt & T)
		sort_time(args);
	else
		sort_ascii(args);
}

t_args	*ft_reverse_lst(t_args *lst)
{
	t_args	*a;
	t_args	*b;
	t_args	*c;

	a = NULL;
	b = lst;
	c = NULL;
	while (b)
	{
		c = b->next;
		b->next = a;
		a = b;
		b = c;
	}
	return (a);
}

void	switch_data(t_args *d1, t_args *d2)
{
	t_data	*tmp;

	tmp = d1->data;
	d1->data = d2->data;
	d2->data = tmp;
}
