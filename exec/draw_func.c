/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:45:24 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/30 19:16:24 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

/*
simple function from 42 mlx, its way faster than the normal mlx put
because it doesnt communicate with the mlx API and it puts the colored pixel
directly in the buffer. it gets displayed in the window when we
call the mlx_put_image_to_window
*/

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
this function draws a square by iterating over
the TILE_SIZE square and putting a colored pixel
in each pixel of the square
*/
void	draw_square(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= TILE_SIZE)
	{
		while (j <= TILE_SIZE)
		{
			my_mlx_pixel_put(data, x + i, y + j, color);
			j++;
		}
		j = 0;
		i++;
	}
}

t_txt	*new_img(t_data *data, char *path)
{
	t_txt	*txt;

	txt = (t_txt *)malloc(sizeof(t_txt));
	if (!txt)
		print_error_and_exit("Allocation Failled\n");
	txt->img = mlx_xpm_file_to_image(data->mlx, path,
			&txt->width, &txt->height);
	if (!txt->img)
		print_error_and_exit("invalid img\n");
	txt->addr = mlx_get_data_addr(txt->img, &txt->bits_per_pixel,
			&txt->line_lenght, &txt->endian);
	if (!txt->addr)
		print_error_and_exit("invalid address path\n");
	return (txt);
}

int	bibo_mlx_pixel_put(t_data *data, int x, int y)
{
	char			*mlx_data_addr;

	mlx_data_addr = data->tmp->addr + y * data->tmp->line_lenght + x
		* (data->tmp->bits_per_pixel / 8);
	return (*(unsigned int *)mlx_data_addr);
}
