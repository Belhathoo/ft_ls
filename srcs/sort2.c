/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:41:24 by aait-el-          #+#    #+#             */
/*   Updated: 2019/11/21 11:42:05 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void		switch_tab(char **t, int i)
{
	char *tmp;

	tmp = t[i];
	t[i] = t[i + 1];
	t[i + 1] = tmp;
}

void		ft_rev_sort(char **tab)
{
	int				i;
	int				j;
	char			*tmp;

	i = 0;
	j = 0;
	while (tab[j])
		j++;
	j--;
	while (i <= j)
	{
		tmp = tab[j];
		tab[j] = tab[i];
		tab[i] = tmp;
		i++;
		j--;
	}
}

void		ft_sortargs(char **tab, int opt)
{
	if (opt & S)
		ft_sort_size(tab);
	else if (opt & T)
		ft_sort_time(tab, opt);
	else
		ft_sortascii(tab);
	if (opt & R)
		ft_rev_sort(tab);
}
