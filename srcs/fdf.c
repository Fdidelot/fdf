/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 01:01:41 by fdidelot          #+#    #+#             */
/*   Updated: 2017/10/03 06:36:09 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init(t_data *new)
{
	new->win = NULL;
	new->mlx = NULL;
	new->map = NULL;
	new->img = NULL;
	new->s_img = NULL;
	new->y_max = 0;
	new->x_max = 0;
	new->bpp = 0;
	new->title = NULL;
	new->size_l = 0;
	new->end = 0;
	new->y = 0;
	new->x = 0;
	new->z = 1;
	new->y1 = 0;
	new->ys = 0;
	new->xs = 0;
	new->col = (t_color *)malloc(sizeof(t_color));
	new->col->modify = 0;
}

t_data	*create_box(void)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	init(new);
	return (new);
}

int		main(int ac, char **av)
{
	t_data	*box;

	if (ac != 2)
	{
		write(2, "Usage : ./fdf <filename>\n", 25);
		return (0);
	}
	box = create_box();
	get_title(box, av[1]);
	get_map(box, av[1]);
	box->mlx = mlx_init();
	box->win = mlx_new_window(box->mlx, 1280, 1280, box->title);
	box->img = mlx_new_image(box->mlx, 1280, 1280);
	box->s_img = mlx_get_data_addr(box->img, &(box->bpp),
								&(box->size_l), &(box->end));
	draw(box);
	mlx_put_image_to_window(box->mlx, box->win, box->img, 0, 0);
	mlx_destroy_image(box->mlx, box->img);
	mlx_do_sync(box->mlx);
	mlx_key_hook(box->win, &key, box);
	mlx_loop(box->mlx);
	return (0);
}
