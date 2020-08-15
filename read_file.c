/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 11:48:54 by zlucan            #+#    #+#             */
/*   Updated: 2020/08/15 15:31:53 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	free(line);
	close(fd);
	return (height);
}

int		get_width(char *file_name)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = ft_wdcounter(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	file_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

void	read_file(char *file_name, t_pf_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int **)malloc(sizeof(int*) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line) && i < data->height)
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	free(line);
	free(data->z_matrix[i]);
	close(fd);
	data->z_matrix[i] = NULL;
}
