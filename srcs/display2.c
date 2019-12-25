/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:59:29 by aait-el-          #+#    #+#             */
/*   Updated: 2019/11/20 18:00:06 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int		print_all(t_args *head, int opt)
{
	int		*max;
	int		max_str;

	max = ((opt & L) || (opt & G)) ? get_lenghts(head, opt) : 0;
	max_str = ((opt & L) || (opt & G)) ? 0 : get_max_str(head);
	if ((opt & L) || (opt & G))
	{
		while (head)
		{
			add_spaces(head->data, max, opt);
			head = head->next;
		}
		free(max);
	}
	else
		ft_print_strs(head, max_str);
	return (1);
}
