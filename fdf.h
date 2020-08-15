/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 11:48:29 by zlucan            #+#    #+#             */
/*   Updated: 2020/08/14 18:08:12 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdint.h>
# include <stddef.h>

typedef struct
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;
	float	x;
	float	y;
	float	x1;
	float	y1;
}			t_pf_br_vars;

typedef struct
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;

	void	*mlx_ptr;
	void	*win_ptr;
	float	x;
	float	y;
	float	x1;
	float	y1;
}			t_pf_fdf;

void		read_file(char *file_name, t_pf_fdf *data);
void		bresenham(float x, float y, float x1, float y1, t_pf_fdf *data);
void		draw(t_pf_fdf *data);

#endif
