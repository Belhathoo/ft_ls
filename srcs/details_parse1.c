/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   details_parse1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 04:13:29 by belhatho          #+#    #+#             */
/*   Updated: 2019/11/18 04:13:44 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

char	*get_nlink(struct stat st)
{
	int		link;
	char	*nlink;

	link = st.st_nlink;
	nlink = ft_itoa(link);
	return (nlink);
}

char	*get_uid(struct stat st)
{
	uid = getpwuid(st.st_uid);
	return (uid->pw_name);
}

char	*get_gid(struct stat st)
{
	gid = getgrgid(st.st_gid);
	return (gid->gr_name);
}

char	*get_size(struct stat st)
{
	int		size;
	char	*t_size;

	size = st.st_size;
	t_size = ft_itoa(size);
	return (t_size);
}
