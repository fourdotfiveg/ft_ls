/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 04:17:40 by briviere          #+#    #+#             */
/*   Updated: 2017/11/30 04:22:40 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_error(int err, char *path)
{
	ft_putstr_fd("ls: ", 2);
	if (path)
	{
		ft_putstr_fd(path);
		ft_putchar_fd(':');
	}
	ft_putendl_fd(strerror(err), 2);
}
