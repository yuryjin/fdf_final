/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 11:54:19 by zlucan            #+#    #+#             */
/*   Updated: 2020/08/15 15:32:00 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#define MAX(a, b) (a > b ? a : b)
#define MOD(a) (a < 0 ? -a : a)

void	super3d(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	brezenham2(t_pf_br_vars *br_vars, t_pf_fdf *data)
{
	br_vars->x += data->shift_x;
	br_vars->y += data->shift_y;
	br_vars->x1 += data->shift_x;
	br_vars->y1 += data->shift_y;
	br_vars->x_step = br_vars->x1 - br_vars->x;
	br_vars->y_step = br_vars->y1 - br_vars->y;
	br_vars->max = MAX(MOD(br_vars->x_step), MOD(br_vars->y_step));
	br_vars->x_step /= br_vars->max;
	br_vars->y_step /= br_vars->max;
	while ((int)(br_vars->x - br_vars->x1) || (int)(br_vars->y - br_vars->y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
		br_vars->x, br_vars->y, data->color);
		br_vars->x += br_vars->x_step;
		br_vars->y += br_vars->y_step;
	}
}

void	bresenham1(float arr[5], t_pf_fdf *data)
{
	t_pf_br_vars *br_vars;

	br_vars = (t_pf_br_vars*)malloc(sizeof(t_pf_br_vars));
	br_vars->x = arr[0];
	br_vars->y = arr[1];
	br_vars->x1 = arr[2];
	br_vars->y1 = arr[3];
	br_vars->z = data->z_matrix[(int)br_vars->y][(int)br_vars->x];
	br_vars->z1 = data->z_matrix[(int)br_vars->y1][(int)br_vars->x1];
	br_vars->x *= data->zoom;
	br_vars->x1 *= data->zoom;
	br_vars->y *= data->zoom;
	br_vars->y1 *= data->zoom;
	data->color = (br_vars->z || br_vars->z1) ? 0xe80c0c : 0xffffff;
	super3d(&br_vars->x, &br_vars->y, br_vars->z);
	super3d(&br_vars->x1, &br_vars->y1, br_vars->z1);
	brezenham2(br_vars, data);
	free(br_vars);
}

void	looping_matrix(int x, int y, float arr[5], t_pf_fdf *data)
{
	if (x < data->width - 1)
	{
		arr[2] = arr[0] + 1;
		bresenham1(arr, data);
	}
	if (y < data->height - 1)
	{
		arr[3] = arr[1] + 1;
		bresenham1(arr, data);
	}
}

void	draw(t_pf_fdf *data)
{
	float	arr[5];
	int		x;
	int		y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			arr[0] = x;
			arr[1] = y;
			arr[2] = x;
			arr[3] = y;
			looping_matrix(x, y, arr, data);
			x++;
		}
		y++;
	}
}
