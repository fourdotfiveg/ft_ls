/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briviere <briviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 12:38:52 by briviere          #+#    #+#             */
/*   Updated: 2017/11/21 17:28:00 by briviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// TODO: print in well formatted column
void	print_file(char *path, char *file, t_arg_opt *opt)
{
	struct stat		path_stat;
	struct passwd	*passwd;
	struct group	*group;

	stat(path, &path_stat);
	passwd = getpwuid(path_stat.st_uid);
	group = getgrgid(path_stat.st_gid);
	if (opt->long_format)
	{
		print_permissions(path_stat.st_mode);
		ft_putstr("  ");
		ft_putnbr(path_stat.st_nlink);
		ft_putchar(' ');
		ft_putstr(passwd->pw_name);
		ft_putchar(' ');
		ft_putstr(group->gr_name);
		ft_putchar(' ');
		ft_putnbr(path_stat.st_size);
		ft_putchar(' ');
	}
	ft_putstr(file);
}

int		ft_ls(char **av, t_arg_opt *opt)
{
	char			*dir_path;
	DIR				*dir;
	struct dirent	*ent;


	(void)opt;
	if (av[0] == 0)
		return (ft_puterr(0, "TODO: Read current directory"));
	dir = opendir(av[0]);
	if (av[0][ft_strlen(av[0]) - 1] != '/')
		dir_path = ft_strjoin(av[0], "/");
	else
		dir_path = av[0];
	if (dir == 0)
		return (ft_puterr(0, "TODO: ls file"));
	while ((ent = readdir(dir)) != 0)
	{
		if ((ent->d_name[0] == '.' && opt->hidden) ||
			(ent->d_name[0] != '.'))
		{
			print_file(ft_strjoin(dir_path, ent->d_name), ent->d_name, opt);
			ft_putchar('\n');
		}
	}
	closedir(dir);
	return (1);
}
