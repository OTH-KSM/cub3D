/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omarchic <omarchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:39:36 by omarchic          #+#    #+#             */
/*   Updated: 2023/12/27 18:43:32 by omarchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// this function check if the pixel passed in the arguments is a wall
// by dividing by the tile_size
int	is_wall(t_data *data, long x_touch, long y_touch)
{
	int	x;
	int	y;

	x = x_touch / TILE_SIZE;
	y = y_touch / TILE_SIZE;
	if (x < data->parse.height && y < data->parse.width
		&& data->parse.map[x][y] == '1')
		return (1);
	return (0);
}

// this function is for testing purposes it check if 
//the ray casted reached a wall
// same as the function above ghir nssit kant deja 3ndi
int	check_ray(t_data *data, double x, double y)
{
	int		new_x;
	int		new_y;
	double	angle;

	new_x = x / TILE_SIZE;
	new_y = y / TILE_SIZE;
	angle = cos(data->rotationAngle - (FOV_ANGLE / 2));
	if (data->parse.map[new_x][new_y] == '1')
		return (1);
	return (0);
}

// this function casts a MAP_data->parse.width of rays and draws the walls

void	cast_all_rays(t_data *data, double x, double y) // not tested
{
	int		j;
	int		i;
	float	angle;
	float	real_distance;

	i = 0;
	j = 0;
	angle = data->rotationAngle - (FOV_ANGLE / 2);
	while (i < MAP_WIDTH)
	{
		real_distance = check_interception(data, angle) * cos(angle
				- data->rotationAngle);
		angle += FOV_ANGLE / MAP_WIDTH;
		angle = set_angle(angle);
		draw_3d(data, real_distance, i, angle);
		i++;
	}
}

// check if the player can move or if he is limited by a wall
// it handles moving between the walls by setting a rectangle
// that have the player position and his new position as main points
// and then checks the other vertices to avoid runnig through walls
int	check_boundary(t_data *data, double add)
{
	int	x;
	int	y;
	int	x1;
	int	y1;

	x1 = (data->player_x + cos(data->rotationAngle + add) * 5) / TILE_SIZE;
	y1 = (data->player_y + sin(data->rotationAngle + add) * 5) / TILE_SIZE;
	x = data->player_x / TILE_SIZE;
	y = data->player_y / TILE_SIZE;
	if (data->parse.map[x1][y1] == '1' || (data->parse.map[x][y1] == '1'
						&& data->parse.map[x1][y] == '1'))
		return (1);
	return (0);
}

// this function implement basic math to count the distance between two points
double	count_distance(t_data *data, long x2, long y2)
{
	double	ret;

	ret = sqrt((((x2 - data->player_x) * (x2 - data->player_x))) + (((y2
						- data->player_y) * (y2 - data->player_y))));
	return (ret);
}
