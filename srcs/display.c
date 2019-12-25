/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 02:56:32 by belhatho          #+#    #+#             */
/*   Updated: 2019/11/20 17:58:35 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	ft_putstrs(char *s1, char *s2, char *s3, char *s4)
{
	ft_putstr(s1);
	ft_putstr(s2);
	ft_putstr(s3);
	ft_putstr(s4);
}

void	ft_option_f(t_data *data)
{
	if (data->chmod[0] == 'd')
		ft_putstr("/");
	else if (data->chmod[0] == 'p')
		ft_putstr("|");
	else if (data->chmod[0] == 'l')
		ft_putstr("@");
	else if (data->chmod[0] == '-' && (data->chmod[3] == 'x' ||
				data->chmod[6] == 'x' || data->chmod[9] == 'x'))
		ft_putstr("*");
}

void	ft_print_details_param(t_data *data, int opt)
{
	ft_putstrs(data->time_month, data->time_rest, " ", data->str);
	if (opt & FF)
		ft_option_f(data);
	if (data->chmod[0] == 'l')
		ft_putstrs("", " -> ", data->linkto, "");
	if (data)
		ft_putstr("\n");
}

void	get_total_nblocks(t_args *args)
{
	long	n;

	n = 0;
	while (args)
	{
		lstat(args->data->path, &st);
		n = n + st.st_blocks;
		args = args->next;
	}
	ft_putstr("total ");
	ft_putnbr(n);
	ft_putchar('\n');
}
