/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 20:58:46 by aait-el-          #+#    #+#             */
/*   Updated: 2019/11/23 20:09:05 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void		spaces_minor(t_data *data, int max)
{
	ft_set_spaces(max - ft_strlen(data->min));
	ft_putstrs(data->min, " ", 0, 0);
}

void		spaces_major(t_data *data, int max)
{
	ft_set_spaces(max - ft_strlen(data->maj));
	ft_putstrs(data->maj, " ", 0, 0);
}

int			*get_lenghts(t_args *args, int opt)
{
	int		*max;

	max = (int *)malloc((sizeof(int)) * 4);
	max[0] = get_max_lent_nlink(args);
	max[1] = (opt & G) ? 0 : get_max_lent_usr(args);
	max[2] = get_max_lent_grp(args);
	max[3] = get_max_lent_size(args);
	return (max);
}

void		add_spaces(t_data *data, int *max, int opt)
{
	ft_putstrs(data->chmod, " ", " ", 0);
	spaces_nlink(data, max[0]);
	(opt & G) ? 0 : spaces_usr(data, max[1]);
	spaces_grp(data, max[2]);
	if (data->chmod[0] == 'c' || data->chmod[0] == 'b')
	{
		spaces_major(data, 3);
		spaces_minor(data, 3);
	}
	else
		spaces_size(data, max[3]);
	ft_print_details_param(data, opt);
}
