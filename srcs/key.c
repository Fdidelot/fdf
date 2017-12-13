/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 21:33:28 by fdidelot          #+#    #+#             */
/*   Updated: 2017/10/03 08:50:36 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	error_map(void)
{
	write(2, "Invalid map\n", 12);
	exit(0);
}

void	mod_img(t_data *box)
{
	box->img = mlx_new_image(box->mlx, 1280, 1280);
	box->s_img = mlx_get_data_addr(box->img,
							&(box->bpp), &(box->size_l), &(box->end));
	draw(box);
	mlx_put_image_to_window(box->mlx, box->win, box->img, 0, 0);
	mlx_destroy_image(box->mlx, box->img);
}

void	key3(int keycode, t_data *box)
{
	if (keycode == 33)
	{
		box->col->modify += 10;
		mod_img(box);
	}
	if (keycode == 30)
	{
		box->col->modify -= 10;
		mod_img(box);
	}
}

void	key2(int keycode, t_data *box)
{
	if (keycode == 121)
	{
		box->z -= 1;
		mod_img(box);
	}
	if (keycode == 116)
	{
		box->z += 1;
		mod_img(box);
	}
	if (keycode == 69)
	{
		box->zoom += 1;
		mod_img(box);
	}
	if (keycode == 78)
	{
		if (box->zoom > 2)
			box->zoom -= 1;
		mod_img(box);
	}
	key3(keycode, box);
}

int		key(int keycode, t_data *box)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 124)
	{
		box->xs += 10;
		mod_img(box);
	}
	if (keycode == 123)
	{
		box->xs -= 10;
		mod_img(box);
	}
	if (keycode == 125)
	{
		box->ys += 10;
		mod_img(box);
	}
	if (keycode == 126)
	{
		box->ys -= 10;
		mod_img(box);
	}
	key2(keycode, box);
	return (box->xi);
}
