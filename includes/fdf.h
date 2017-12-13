/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 20:26:32 by fdidelot          #+#    #+#             */
/*   Updated: 2017/10/03 05:11:16 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../ressources/mlx/mlx.h"

# define X2 box->x2
# define Y2 box->y2

typedef struct	s_color
{
	int		red;
	int		green;
	int		blue;
	int		modify;
}				t_color;

typedef struct	s_data
{
	void	*win;
	void	*mlx;
	void	*img;
	char	*s_img;
	char	***map;
	char	*title;
	int		bpp;
	int		size_l;
	int		end;
	int		y_max;
	int		x_max;
	int		x;
	int		y;
	int		y1;
	int		z;
	int		zoom;
	int		xi;
	int		yi;
	int		xs;
	int		ys;
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		x2;
	int		y2;
	t_color	*col;
}				t_data;

void			error_map(void);
void			draw(t_data *box);
void			get_map(t_data *box, char *str);
void			get_title(t_data *box, char *str);
void			get_xy(t_data *box, char *str);
int				key(int keycode, t_data *box);

#endif
