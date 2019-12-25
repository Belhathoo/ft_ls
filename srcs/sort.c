/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:41:25 by belhatho          #+#    #+#             */
/*   Updated: 2019/11/21 11:47:05 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void		ft_sortascii(char **tab)
{
	int				i;
	int				j;

	j = 0;
	while (tab[j] != NULL)
	{
		i = 0;
		while (tab[i] && tab[i + 1])
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
				switch_tab(tab, i);
			i++;
		}
		j++;
	}
}

void		ft_compare(time_t *stime, time_t *stime1, char **tab, int i)
{
	if (*stime < *stime1)
		switch_tab(tab, i);
	if ((*stime == *stime1) && (ft_strcmp(tab[i],
					tab[i + 1]) > 0))
		switch_tab(tab, i);
}

void		ft_sort_time(char **tab, int opt)
{
	int				i;
	int				j;
	struct stat		st;
	struct stat		st1;

	j = -1;
	while (tab[j++])
	{
		i = 0;
		while (tab[i] && tab[i + 1])
		{
			lstat(tab[i], &st);
			lstat(tab[i + 1], &st1);
			if (opt & U)
				ft_compare(&st.st_atime, &st1.st_atime, tab, i);
			else
				ft_compare(&st.st_mtime, &st1.st_mtime, tab, i);
			i++;
		}
	}
}

void		ft_sort_size(char **tab)
{
	int				i;
	int				j;
	struct stat		st;
	struct stat		st1;

	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[i] && tab[i + 1])
		{
			lstat(tab[i], &st);
			lstat(tab[i + 1], &st1);
			if (st.st_size < st1.st_size)
				switch_tab(tab, i);
			if ((st.st_size == st1.st_size) && (ft_strcmp(tab[i],
							tab[i + 1]) > 0))
				switch_tab(tab, i);
			i++;
		}
		j++;
	}
}
