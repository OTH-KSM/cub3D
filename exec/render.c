/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:48:36 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/30 20:57:52 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	select_texture(t_data *data, float angle)
{
	int	imgx;

	if (!data->check_test)
	{
		if (angle >= EA && angle < WE)
			data->tmp = data->ea;
		else
			data->tmp = data->we;
		imgx = (int)(data->hit_h_x * data->tmp->width / TILE_SIZE)
			% data->tmp->width;
	}
	else
	{
		if (angle > SO && angle <= NO)
			data->tmp = data->no;
		else
			data->tmp = data->so;
		imgx = (int)(data->hit_v_y * data->tmp->width / TILE_SIZE)
			% data->tmp->width;
	}
	return (imgx);
}

int	draw_walls(t_data *data, float wall_height, int i)
{
	float	distance_center_wall;
	int		imgy;

	distance_center_wall = i + (wall_height / 2) - (MAP_HEIGHT / 2);
	imgy = (int)(distance_center_wall * (float)data->tmp->height / wall_height)
		% data->tmp->height;
	return (imgy);
}

// this function draws the walls in each pixel
void	draw_3d(t_data *data, float distance, int x, int imgX)
{
	float	wall_height;
	float	distance_projection_plane;
	float	start;
	float	end;
	int		i;

	distance_projection_plane = (MAP_WIDTH / 2) / tan(FOV_ANGLE / 2);
	wall_height = (TILE_SIZE / distance) * distance_projection_plane;
	start = (MAP_HEIGHT / 2) - (wall_height / 2);
	end = (MAP_HEIGHT / 2) + (wall_height / 2);
	if (start < 0)
		start = 0;
	if (end > MAP_HEIGHT)
		end = MAP_HEIGHT;
	i = 0;
	while (i < start)
		my_mlx_pixel_put(data, x, i++, data->parse->c);
	while (i < end)
	{
		my_mlx_pixel_put(data, x, i, (unsigned int)bibo_mlx_pixel_put
			(data, imgX, draw_walls(data, wall_height, i)));
		i++;
	}
	while (i < MAP_HEIGHT)
		my_mlx_pixel_put(data, x, i++, data->parse->f);
}

void	render_background(t_data *data)
{
	int	i;
	int	j;

	if (data->mlx_win == NULL)
		return ;
	i = 0;
	while (i < MAP_HEIGHT)
	{
		j = 0;
		while (j < MAP_WIDTH)
			my_mlx_pixel_put(data, j++, i, 0xffffff);
		++i;
	}
}

// obvious
void	render_game(t_data *data)
{
	cast_all_rays(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}
