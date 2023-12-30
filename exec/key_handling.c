/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:29:35 by omarchic          #+#    #+#             */
/*   Updated: 2023/12/28 22:26:20 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// obvious
int	close_window(t_data *data)
{
	(void)data;
	exit(0);
}

/*
this function handles the key presses the 5 is added
for more speed feel free to play with it if you want to
increment or decrement the player's speed
tho you gotta change it in the check_boundary function too
D === 2
A === 0
right = 124
left  = 123
*/

int	press_down(int keycode, t_data *data)
{
	if (keycode == 53)
		close_window(data);
	if (keycode == 13)
		data->move = 1;
	if (keycode == 1)
		data->move = -1;
	if (keycode == 2)
		data->move = 2;
	if (keycode == 0)
		data->move = 3;
	if (keycode == 124)
		data->turn = 1;
	if (keycode == 123)
		data->turn = -1;
	return (0);
}

int	press_up(int keycode, t_data *data)
{
	if (keycode == 13)
		data->move = 0;
	if (keycode == 1)
		data->move = 0;
	if (keycode == 2)
		data->move = 0;
	if (keycode == 0)
		data->move = 0;
	if (keycode == 124)
		data->turn = 0;
	if (keycode == 123)
		data->turn = 0;
	return (0);
}

int	key_hook1(t_data *data)
{
	double	rotate;

	rotate = 1;
	if (data->move == 1 && check_boundary(data, 0) == 0)
		rotate = 0;
	else if (data->turn == 1)
		data->rotation_angle += 0.05;
	else if (data->move == -1 && check_boundary(data, M_PI) == 0)
		rotate = M_PI;
	else if (data->turn == -1)
		data->rotation_angle -= 0.05;
	else if (data->move == 2 && check_boundary(data, M_PI / 2) == 0)
		rotate = M_PI / 2;
	else if (data->move == 3 && check_boundary(data, -M_PI / 2) == 0)
		rotate = -M_PI / 2;
	if (rotate != 1)
	{
		data->player_x += cos(data->rotation_angle + rotate) * 10;
		data->player_y += sin(data->rotation_angle + rotate) * 10;
	}
	render_game(data);
	return (0);
}
