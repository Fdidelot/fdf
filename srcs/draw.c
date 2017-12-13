/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 03:05:33 by fdidelot          #+#    #+#             */
/*   Updated: 2017/10/03 05:48:18 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_color(t_data *box, int x, int y)
{
	int	color;

	box->y1 = box->y - ft_atoi(box->map[y][x]) * box->zoom * box->z;
	box->yi = (box->x + box->y1) / 2;
	box->xi = (box->x - box->y) + 640;
	if (ft_atoi(box->map[y][x]) > 20)
		color = 255;
	else if (ft_atoi(box->map[y][x]) > 15)
		color = 230;
	else if (ft_atoi(box->map[y][x]) > 10)
		color = 200;
	else if (ft_atoi(box->map[y][x]) > 5)
		color = 150;
	else
		color = 100;
	box->col->red = color + box->col->modify;
	box->col->blue = color - box->col->modify;
	box->col->green = box->col->modify;
}

void	ass(t_data *box, int x, int y)
{
	X2 = box->xi;
	Y2 = box->yi;
	box->dx = abs(x - box->xi);
	box->sx = box->xi < x ? 1 : -1;
	box->dy = abs(y - box->yi);
	box->sy = box->yi < y ? 1 : -1;
}

void	draw_line(t_data *box, int x, int y)
{
	int err;
	int e2;

	ass(box, x, y);
	err = (box->dx > box->dy ? box->dx : -box->dy) / 2;
	while (x != X2 || Y2 != y)
	{
		if (X2 < 1280 && X2 > 0 && Y2 > 0 && Y2 < 1280)
		{
			box->s_img[(1280 * Y2 + X2) * 4] = (char)(box->col->blue);
			box->s_img[(1280 * Y2 + X2) * 4 + 1] = (char)(box->col->green);
			box->s_img[(1280 * Y2 + X2) * 4 + 2] = (char)(box->col->red);
		}
		e2 = err;
		if (e2 >= -box->dx)
		{
			err -= box->dy;
			X2 += box->sx;
		}
		if (e2 <= box->dy)
		{
			err += box->dx;
			Y2 += box->sy;
		}
	}
}

void	bresenham(t_data *box, int x, int y, int ok)
{
	int	xe;
	int ye;

	if (ok)
	{
		box->y1 = box->zoom + box->y - ft_atoi(box->map[y][x])
			* box->zoom * box->z;
		ye = (box->x + box->y1) / 2;
		xe = (box->x - (box->y + box->zoom)) + 640;
	}
	else
	{
		box->y1 = box->y - ft_atoi(box->map[y][x]) * box->zoom * box->z;
		ye = (box->zoom + box->x + box->y1) / 2;
		xe = ((box->x + box->zoom) - box->y) + 640;
	}
	draw_line(box, xe, ye);
}

void	draw(t_data *box)
{
	int	x;
	int	y;

	y = 0;
	box->x = box->xs;
	box->y = box->ys;
	while (y < box->y_max)
	{
		x = 0;
		box->x = box->xs;
		while (x < box->x_max)
		{
			get_color(box, x, y);
			if (x + 1 < box->x_max)
				bresenham(box, x + 1, y, 0);
			if (y + 1 < box->y_max)
				bresenham(box, x, y + 1, 1);
			box->x += box->zoom;
			x++;
		}
		box->y += box->zoom;
		y++;
	}
}
