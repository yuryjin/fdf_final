/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 11:48:37 by zlucan            #+#    #+#             */
/*   Updated: 2020/08/15 15:53:43 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_pf_fdf *data)
{
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == '5')
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data);
		exit(0);
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

void	ft_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

void	manage_errors(int argc, char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("%s\n", "usage: file must be passed as an argument");
		exit(-1);
	}
	if (argc != 2)
		ft_error("usage: ./fdf map.fdf and it should be file");
}

int		main(int argc, char **argv)
{
	t_pf_fdf	*data;
	int			i;

	manage_errors(argc, argv);
	data = (t_pf_fdf*)malloc(sizeof(t_pf_fdf));
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 20;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	i = 0;
	while (i <= data->height)
	{
		free(data->z_matrix[i]);
		i++;
	}
	free(data->z_matrix);
	free(data);
}
