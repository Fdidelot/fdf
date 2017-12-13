/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 03:29:55 by fdidelot          #+#    #+#             */
/*   Updated: 2017/10/03 06:29:57 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		get_zoom(t_data *box)
{
	if (box->x_max > 499 || box->y_max > 499)
		return (2);
	if (box->x_max > 299 || box->y_max > 299)
		return (3);
	if (box->x_max > 199 || box->y_max > 199)
		return (4);
	if (box->x_max > 99 || box->y_max > 99)
		return (5);
	if (box->x_max > 29 || box->y_max > 29)
		return (15);
	return (20);
}

void	get_title(t_data *box, char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (str[i] && str[i] != '/')
		i--;
	box->title = ft_strdup(str + i + 1);
}

int		nb_occ(char *str)
{
	int	nb;

	nb = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str && *str != ' ')
		{
			nb++;
			while (*str && *str != ' ')
				str++;
		}
	}
	return (nb);
}

void	get_xy(t_data *box, char *str)
{
	int		fd;
	char	*tmp;

	fd = 0;
	if (!(fd = open(str, O_RDONLY)))
	{
		write(2, "open() failed.\n", 15);
		exit(0);
	}
	while (get_next_line(fd, &tmp) > 0)
	{
		if (box->x_max == 0)
			box->x_max = nb_occ(tmp);
		if (box->x_max != nb_occ(tmp))
			error_map();
		box->y_max++;
	}
	free(tmp);
	close(fd);
}

void	get_map(t_data *box, char *str)
{
	int		fd;
	int		i;

	i = 0;
	fd = 0;
	get_xy(box, str);
	box->map = (char ***)malloc(sizeof(char **)
								* box->y_max + 1);
	if (!(fd = open(str, O_RDONLY)))
	{
		write(2, "open() failed.\n", 15);
		exit(0);
	}
	while (get_next_line(fd, &str) > 0)
		box->map[i++] = ft_strsplit(str, ' ');
	free(str);
	close(fd);
	box->map[i] = 0;
	box->zoom = get_zoom(box);
	box->xs = 640 - box->zoom * box->x_max / 2;
	box->ys = 640 - box->zoom * box->y_max / 2;
}
