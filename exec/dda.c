/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:27:53 by omarchic          #+#    #+#             */
/*   Updated: 2023/12/30 19:02:41 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

/*
here is the main function of the project it returns
the distance between the player and the wall
using DDA
*/

void	horiz_touch(t_dda *t, t_data *data)
{
	if (t->is_up == 1)
		t->y_horiz_touch--;
	while (t->x_horiz_touch >= 0 && t->x_horiz_touch
		<= data->parse->height * TILE_SIZE
		&& t->y_horiz_touch >= 0 && t->y_horiz_touch
		<= data->parse->width * TILE_SIZE)
	{
		t->x_to_check = t->x_horiz_touch;
		t->y_to_check = t->y_horiz_touch;
		if (t->is_up == 1)
			t->y_to_check--;
		if (is_wall(data, t->x_to_check, t->y_to_check) == 1)
		{
			t->found_horz_hit = 1;
			t->wall_hit_x_horiz = t->x_horiz_touch;
			t->wall_hit_y_horiz = t->y_horiz_touch;
			break ;
		}
		else
		{
			t->x_horiz_touch += t->x_horiz_step;
			t->y_horiz_touch += t->y_horiz_step;
		}
	}
}

void	init_dda2(t_dda *t, t_data *data)
{
	if (t->ray_angle > M_PI_2 && t->ray_angle < 3 * M_PI_2)
	{
		t->is_left = 1;
		t->x_verti_step *= -1;
		t->x_verti_intercept = floor(data->player_x / TILE_SIZE) * TILE_SIZE;
	}
	else
		t->x_verti_intercept = (floor(data->player_x / TILE_SIZE)
				* TILE_SIZE) + TILE_SIZE;
	if ((t->ray_angle > M_PI && t->ray_angle < (2 * M_PI)))
	{
		if (t->y_verti_step > 0)
			t->y_verti_step *= -1;
	}
	else
	{
		if (t->y_verti_step < 0)
			t->y_verti_step *= -1;
	}
	t->y_verti_intercept = data->player_y + ((t->x_verti_intercept
				- data->player_x) * tan(t->ray_angle));
	t->x_verti_touch = t->x_verti_intercept;
	t->y_verti_touch = t->y_verti_intercept;
	if (t->is_left == 1)
		t->x_verti_touch--;
}

void	vertical_touch(t_dda *t, t_data *data)
{
	while (t->x_verti_touch >= 0 && t->x_verti_touch
		<= data->parse->height * TILE_SIZE
		&& t->y_verti_touch >= 0 && t->y_verti_touch
		<= data->parse->width * TILE_SIZE)
	{
		t->x_to_check = t->x_verti_touch;
		t->y_to_check = t->y_verti_touch;
		if (t->is_left == 1)
			t->x_to_check--;
		if (is_wall(data, t->x_to_check, t->y_to_check))
		{
			t->found_verti_hit = 1;
			t->wall_hit_x_verti = t->x_verti_touch;
			t->wall_hit_y_verti = t->y_verti_touch;
			break ;
		}
		else
		{
			t->x_verti_touch += t->x_verti_step;
			t->y_verti_touch += t->y_verti_step;
		}
	}
}

void	fill_data(t_dda *t, t_data *data)
{
	if (t->found_horz_hit == 1)
		t->horz_hit_distance = count_distance(data, t->wall_hit_x_horiz,
				t->wall_hit_y_horiz);
	else
		t->horz_hit_distance = MAXFLOAT;
	if (t->found_verti_hit == 1)
		t->verti_hit_distance = count_distance(data, t->wall_hit_x_verti,
				t->wall_hit_y_verti);
	else
		t->verti_hit_distance = MAXFLOAT;
	if (t->verti_hit_distance < t->horz_hit_distance)
	{
		data->ray_distance = t->verti_hit_distance;
		data->hit_v_x = t->wall_hit_x_verti;
		data->hit_v_y = t->wall_hit_y_verti;
		data->check_test = 1;
	}
	else
	{
		data->ray_distance = t->horz_hit_distance;
		data->hit_h_x = t->wall_hit_x_horiz;
		data->hit_h_y = t->wall_hit_y_horiz;
		data->check_test = 0;
	}
}

float	check_interception(t_data *data, double angle)
{
	t_dda	t;

	init_dda(&t, data, angle);
	horiz_touch(&t, data);
	init_dda2(&t, data);
	vertical_touch(&t, data);
	fill_data(&t, data);
	return (data->ray_distance);
}
