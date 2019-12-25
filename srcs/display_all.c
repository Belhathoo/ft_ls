/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirdata_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 01:58:33 by belhatho          #+#    #+#             */
/*   Updated: 2019/11/19 18:59:16 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

char		**check_all(int ac, char **av, int opt)
{
	int		i;
	int		j;
	char	**all;

	i = 1;
	j = 0;
	while (av[i] && av[i][0] == '-' && av[i][1] && ft_strcmp(av[i], "--"))
		i++;
	if (av[i] && !ft_strcmp(av[i], "--"))
		i++;
	if (i == ac)
	{
		all = (char **)malloc(sizeof(char *) * 2);
		all[0] = ft_strdup(".");
		all[1] = NULL;
		return (all);
	}
	if (!(all = (char **)malloc(sizeof(char *) * (ac - i + 2))))
		return (NULL);
	while (av[i])
		all[j++] = ft_strdup(av[i++]);
	all[j] = NULL;
	(opt & F) ? 0 : ft_sortascii(all);
	ft_check(all);
	return (all);
}

void		dirdata_display(int ac, char **av, int opt)
{
	char	**all;
	t_args	*dir;
	int		i;

	all = check_all(ac, av, opt);
	(opt & F) ? 0 : ft_sortargs(all, opt);
	dir = dirdata(all, opt);
	i = 0;
	free_tab(&all);
	print_all(dir, opt);
	ft_clean_lst(&dir, opt);
}

void		param_display(t_args *param, int opt, int ndir)
{
	if (!(opt & F))
	{
		sort_list(param, opt);
		param = (opt & R) ? ft_reverse_lst(param) : param;
	}
	print_all(param, opt);
	(ndir) ? ft_putchar('\n') : 0;
	ft_clean_lst(&param, opt);
}

void		directories_display(char **dirs, int nparam, int opt)
{
	int		i;

	i = 0;
	while (dirs[i])
	{
		if (ft_pstrlen(dirs) > 1 || nparam)
			ft_putstrs("", dirs[i], " : ", "\n");
		read_dir(dirs[i], opt);
		i++;
		if (dirs[i])
			ft_putchar('\n');
	}
}
