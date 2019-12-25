/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:18:28 by belhatho          #+#    #+#             */
/*   Updated: 2019/11/19 01:12:18 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void		ft_check(char **av)
{
	struct stat		data;
	int				i;

	i = 0;
	while (av[i])
	{
		if (lstat(av[i], &data) < 0)
		{
			ft_putstrs("ft_ls: ", av[i], ": ", "");
			perror("");
		}
		i++;
	}
}

void		ft_alloc(t_args **param, t_args **curr, t_args **tt)
{
	if ((*param) == NULL)
	{
		(*param) = create_args();
		(*tt) = (*param);
		(*param)->data = (*curr)->data;
	}
	else
	{
		(*param)->next = create_args();
		(*param)->next->data = (*curr)->data;
		(*param) = (*param)->next;
	}
}

t_args		*type_param(char **args, int opt)
{
	t_args	*param;
	t_args	*curr;
	t_args	*tt;
	int		i;

	i = 0;
	param = NULL;
	tt = NULL;
	curr = create_args();
	while (args[i])
	{
		if (lstat(args[i], &st) != -1)
		{
			get_all_data(curr, ".", args[i], opt);
			ft_alloc(&param, &curr, &tt);
		}
		i++;
	}
	free(curr);
	param = tt;
	return (param);
}

t_args		*dirdata(char **dur, int opt)
{
	t_args		*head;
	t_args		*tt;
	t_args		*curr;
	int			i;

	i = 0;
	head = NULL;
	tt = NULL;
	curr = create_args();
	while (dur[i])
	{
		if (lstat(dur[i], &st) != -1)
		{
			get_all_data(curr, ".", dur[i], opt);
			ft_alloc(&head, &curr, &tt);
		}
		i++;
	}
	free(curr);
	head = tt;
	return (head);
}
