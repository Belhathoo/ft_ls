/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_clmns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:58:37 by belhatho          #+#    #+#             */
/*   Updated: 2019/11/21 11:27:49 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int		ft_lentlst(t_args *args)
{
	int		len;

	len = 0;
	while (args)
	{
		len++;
		args = args->next;
	}
	return (len);
}

int		get_max_str(t_args *args)
{
	int		max;
	int		lent;

	max = 0;
	while (args)
	{
		lent = ft_strlen(args->data->str);
		if (lent >= max)
			max = lent;
		args = args->next;
	}
	return (max);
}

char	**get_strs(t_args *args)
{
	char	**all;
	int		i;

	all = NULL;
	i = 0;
	if (!(all = (char **)malloc(sizeof(char *) * (ft_lentlst(args) + 1))))
		return (NULL);
	i = 0;
	while (args)
	{
		all[i] = ft_strdup(args->data->str);
		i++;
		args = args->next;
	}
	all[i] = NULL;
	return (all);
}

int		get_win_width(int max)
{
	int				cln;
	struct winsize	win;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
	cln = (win.ws_col / (max + 4) == 0) ? 1 : (win.ws_col / (max + 4));
	return (cln);
}

void	ft_print_strs(t_args *args, int max)
{
	int		cl[2];
	int		len;
	char	**all;
	int		i;
	int		j;

	j = 0;
	cl[0] = get_win_width(max);
	all = get_strs(args);
	len = ft_pstrlen(all);
	cl[1] = ((len % cl[0]) == 0) ? (len / cl[0]) : ((len / cl[0]) + 1);
	i = 0;
	while (i < cl[1] && all[j])
	{
		while (j < len)
		{
			ft_putstr(all[j]);
			ft_set_spaces((max + 4) - ft_strlen(all[j]));
			j = j + cl[1];
		}
		ft_putchar('\n');
		j = ++i;
	}
	free_tab(&all);
	all = NULL;
}
