/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:20:51 by belhatho          #+#    #+#             */
/*   Updated: 2019/11/21 11:35:30 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int	main(int argc, char **argv)
{
	t_arguments		args;
	t_args			*param;
	int				opt;

	param = NULL;
	opt = check_options(argv);
	if (opt & D)
		dirdata_display(argc, argv, opt);
	else
	{
		args = param_store(argc, argv, opt);
		if (args.nparam)
			param = type_param(args.param, opt);
		(args.nparam) ? param_display(param, opt, args.ndir) : 0;
		directories_display(args.directories, args.nparam, opt);
		ft_clean_l_args(args);
	}
	return (0);
}
