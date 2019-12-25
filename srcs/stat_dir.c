/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 01:46:42 by belhatho          #+#    #+#             */
/*   Updated: 2019/11/24 02:40:35 by aait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

DIR		*ft_opendir(char *dur)
{
	DIR				*directory;

	if (!(directory = opendir(dur)))
	{
		ft_putstrs("ft_ls: ", ft_strrchr(dur, '/'), ": ", 0);
		perror("");
	}
	return (directory);
}

t_args	*get_dir_content(char *dur, int opt)
{
	t_args			*head;
	t_args			*tt;
	t_args			*curr;
	DIR				*directory;

	head = NULL;
	tt = NULL;
	if (!(directory = ft_opendir(dur)))
		return (NULL);
	curr = create_args();
	while ((file = readdir(directory)))
	{
		if ((opt & A) || (opt & F) || file->d_name[0] != '.')
		{
			get_all_data(curr, dur, file->d_name, opt);
			ft_alloc(&head, &curr, &tt);
		}
	}
	closedir(directory);
	free(curr);
	head = tt;
	return (head);
}

void	read_dir(char *dur, int opt)
{
	t_args			*head;
	t_args			*tt;

	tt = get_dir_content(dur, opt);
	if (!(opt & F) && tt)
	{
		sort_list(tt, opt);
		tt = (opt & R) ? ft_reverse_lst(tt) : tt;
	}
	head = tt;
	if (!(opt & D) && ((opt & L) || (opt & G)) && head)
		get_total_nblocks(head);
	print_all(head, opt);
	while (head && (opt & RR))
	{
		if (head->data->chmod[0] == 'd' && ft_strcmp(head->data->str, ".")
						&& ft_strcmp(head->data->str, ".."))
		{
			ft_putstrs("\n", head->data->path, " : ", "\n");
			read_dir(head->data->path, opt);
		}
		head = head->next;
	}
	head = tt;
	ft_clean_lst(&head, opt);
}
