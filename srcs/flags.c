/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:59:47 by belhatho          #+#    #+#             */
/*   Updated: 2019/11/18 04:55:30 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void		add_option(int *opt, char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i] && av[i][j] && av[i][0] == '-' && av[i][1] != '\0'
								&& ft_strcmp(av[i], "--"))
	{
		j = 1;
		while (av[i][j] && av[i][0] == '-')
		{
			((av[i][j] == 'u') && (!(*opt & U))) ? *opt += U : 0;
			((av[i][j] == 'a') && (!(*opt & A))) ? *opt += A : 0;
			((av[i][j] == 'R') && (!(*opt & RR))) ? *opt += RR : 0;
			((av[i][j] == 'l') && (!(*opt & L))) ? *opt += L : 0;
			((av[i][j] == 'r') && (!(*opt & R))) ? *opt += R : 0;
			((av[i][j] == 'f') && (!(*opt & F))) ? *opt += F : 0;
			((av[i][j] == 't') && (!(*opt & T))) ? *opt += T : 0;
			((av[i][j] == 'S') && (!(*opt & S))) ? *opt += S : 0;
			((av[i][j] == 'g') && (!(*opt & G))) ? *opt += G : 0;
			((av[i][j] == 'F') && (!(*opt & FF))) ? *opt += FF : 0;
			((av[i][j] == 'd') && (!(*opt & D))) ? *opt += D : 0;
			j++;
		}
		i++;
	}
}

int			check_options(char **av)
{
	int opt;
	int i;
	int j;

	i = 0;
	opt = 0;
	while (av[++i])
	{
		j = 0;
		while (av[i] && av[i][++j] && av[i][0] == '-' && av[i][1] != '\0'
							&& ft_strcmp(av[i], "--"))
		{
			if (av[i][j] != 'a' && av[i][j] != 'l' && av[i][j] != 'R'
					&& av[i][j] != 'r' && av[i][j] != 'f' && av[i][j] != 't'
					&& av[i][j] != 'u' && av[i][j] != 'S' && av[i][j] != 'g'
					&& av[i][j] != 'F' && av[i][j] != 'd')
			{
				ft_putstrs("ft_ls: illegal opt -- ", &av[i][j], 0,
						"\nusage: ./ft_ls [-alRruftGgS] [file ...]\n");
				exit(0);
			}
		}
	}
	add_option(&opt, av);
	return (opt);
}
