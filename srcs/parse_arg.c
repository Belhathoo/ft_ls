/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:18:15 by belhatho          #+#    #+#             */
/*   Updated: 2019/11/21 11:37:27 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

char				ft_islink(mode_t m, char *av, int opt)
{
	char	*path;

	if (S_ISLNK(m))
	{
		if (av[0] == '/')
			path = do_path("/", ft_readlink(av));
		else
			path = do_path(av, ft_readlink(av));
		if ((opt & L) || (opt & G))
			return ('P');
		else
		{
			if ((lstat(path, &st) != -1) && (S_ISDIR(st.st_mode)))
				return ('D');
			else
				return ('P');
		}
	}
	return ('x');
}

char				**param_parse(int nparam, char **av, int opt)
{
	int				i;
	int				j;
	char			**param;
	struct stat		st;

	param = (char **)malloc(sizeof(char *) * (nparam + 1));
	i = 0;
	j = 0;
	while (av[i])
	{
		if ((lstat(av[i], &st) == -1) || (!(S_ISDIR(st.st_mode))
						|| (ft_islink(st.st_mode, av[i], opt) == 'P')))
		{
			param[j] = ft_strdup(av[i]);
			j++;
		}
		i++;
	}
	param[j] = NULL;
	(opt & F) ? 0 : ft_sortascii(param);
	ft_check(param);
	return (param);
}

t_arguments			arg_isdir(char **av, int opt)
{
	int				i;
	int				j;
	t_arguments		args;

	i = 0;
	j = 0;
	while (av[i++])
		if ((lstat(av[i], &st) != -1) && ((S_ISDIR(st.st_mode))
				|| ft_islink(st.st_mode, av[i], opt) == 'D'))
			args.ndir++;
	args.directories = (char **)malloc(sizeof(char*) * (args.ndir + 1));
	i = 0;
	while (av[i++])
	{
		if ((lstat(av[i], &st) != -1) && ((S_ISDIR(st.st_mode))
				|| ft_islink(st.st_mode, av[i], opt) == 'D'))
		{
			args.directories[j] = S_ISLNK(st.st_mode) ?
					ft_strjoin(av[i], "/") : ft_strdup(av[i]);
			j++;
		}
	}
	args.directories[j] = NULL;
	(opt & F) ? 0 : ft_sortargs(args.directories, opt);
	return (args);
}

t_arguments			param_store(int ac, char **av, int opt)
{
	t_arguments		args;
	int				i;

	args.nparam = 0;
	args.ndir = 0;
	i = 1;
	while (av[i] && av[i][0] == '-' && av[i][1] && ft_strcmp(av[i], "--"))
		i++;
	if (av[i] && !ft_strcmp(av[i], "--"))
		i++;
	if (i == ac)
	{
		args.directories = (char **)malloc(sizeof(char *) * 2);
		args.directories[0] = ft_strdup(".");
		args.directories[1] = NULL;
		args.ndir = 1;
		return (args);
	}
	else
		args = arg_isdir(av, opt);
	args.nparam = ac - i - args.ndir;
	if (args.nparam)
		args.param = param_parse(args.nparam, &av[i], opt);
	return (args);
}
