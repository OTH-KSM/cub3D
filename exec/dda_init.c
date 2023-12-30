/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:22:50 by omarchic          #+#    #+#             */
/*   Updated: 2023/12/30 18:16:37 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	set_variables(t_dda *t, t_data *data, double angle)
{
	t->ray_angle = set_angle(angle);
	t->is_up = 0;
	t->is_left = 0;
	t->found_horz_hit = 0;
	t->found_verti_hit = 0;
	data->check_test = 0;
	t->y_horiz_step = TILE_SIZE;
	t->x_horiz_step = t->y_horiz_step / tan(t->ray_angle);
	t->x_verti_step = TILE_SIZE;
	t->y_verti_step = t->x_verti_step * tan(t->ray_angle);
}

void	init_dda(t_dda *t, t_data *data, double angle)
{
	set_variables(t, data, angle);
	if (t->ray_angle > M_PI && t->ray_angle < 2 * M_PI)
	{
		t->is_up = 1;
		t->y_horiz_step *= -1;
		t->y_horiz_intercept = floor(data->player_y / TILE_SIZE) * TILE_SIZE;
	}
	else
		t->y_horiz_intercept = (floor(data->player_y / TILE_SIZE) * TILE_SIZE)
			+ TILE_SIZE;
	if ((t->ray_angle > (M_PI / 2) && t->ray_angle < (3 * M_PI / 2)))
	{
		if (t->x_horiz_step > 0)
			t->x_horiz_step *= -1;
	}
	else
	{
		if (t->x_horiz_step < 0)
			t->x_horiz_step *= -1;
	}
	t->x_horiz_intercept = data->player_x + ((t->y_horiz_intercept
				- data->player_y) / tan(t->ray_angle));
	t->x_horiz_touch = t->x_horiz_intercept;
	t->y_horiz_touch = t->y_horiz_intercept;
}
