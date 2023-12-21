#include "cube3d.h"

// obvious
int close_window(t_data *data)
{

    (void)data;
    exit(0);
}

// this function handles the key presses the 5 is added for more speed
// feel free to play with it if you want to increment or decrement the player's speed
// tho you gotta change it in the check_boundary function too

// D === 2
// A === 0
// right = 124
// left  = 123

int	press_down(int keycode, t_data *data)
{
	if (keycode == 53)
		close_window(data);
	if (keycode == 13)
		data->move = 1;
	if (keycode == 1)
		data->move= -1;
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
		data->move= 0;
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
    // exit(0);
    if  (data->move == 1)
    {
        if(check_boundary(data, 0) == 0)
        {
            data->player_x += cos(data->rotationAngle) * 5;
            data->player_y += sin(data->rotationAngle) * 5;
        }
    }
    else if  (data->turn == 1)
        data->rotationAngle+=0.05;
    else if  (data->move == -1)
    {
        if(check_boundary(data, M_PI) == 0)
            {
                data->player_x += cos(data->rotationAngle + M_PI) * 5;
                data->player_y += sin(data->rotationAngle + M_PI) * 5;
            }
    }
    else if  (data->turn == -1)
        data->rotationAngle-=0.05;
    else if (data->move == 2)
    {
        if(check_boundary(data, M_PI / 2) == 0)
            {
                data->player_x += cos(data->rotationAngle + M_PI / 2) * 5;
                data->player_y += sin(data->rotationAngle + M_PI / 2) * 5;
            }
    }
    else if (data->move == 3)
    {
        if(check_boundary(data, -M_PI /2) == 0)
        {
            data->player_x += cos(data->rotationAngle - M_PI / 2) * 5;
            data->player_y += sin(data->rotationAngle - M_PI / 2) * 5;
        }
    }
    render_game(data);
    return (0);
}
// int	key_hook(int keycode, t_data *data)
// {
//     printf("%d\n", keycode);
//     // exit(0);
//     if  (keycode == 53)
//         close_window(keycode, data);
//     if  (keycode == 13)
//     {
//         if(check_boundary(data, 0) == 0)
//         {
//             data->player_x += cos(data->rotationAngle) * 5;
//             data->player_y += sin(data->rotationAngle) * 5;
//         }
//     }
//     else if  (keycode == 124)
//         data->rotationAngle+=0.05;
//     else if  (keycode == 1)
//     {
//         if(check_boundary(data, M_PI) == 0)
//             {
//                 data->player_x += cos(data->rotationAngle + M_PI) * 5;
//                 data->player_y += sin(data->rotationAngle + M_PI) * 5;
//             }
//     }
//     else if  (keycode == 123)
//         data->rotationAngle-=0.05;
//     else if (keycode == 2)
//     {
//         if(check_boundary(data, M_PI / 2) == 0)
//             {
//                 data->player_x += cos(data->rotationAngle + M_PI / 2) * 5;
//                 data->player_y += sin(data->rotationAngle + M_PI / 2) * 5;
//             }
//     }
//     else if (keycode == 0)
//     {
//         if(check_boundary(data, -M_PI /2) == 0)
//         {
//             data->player_x += cos(data->rotationAngle - M_PI / 2) * 5;
//             data->player_y += sin(data->rotationAngle - M_PI / 2) * 5;
//         }
//     }
//     render_game(data);
//     return (0);
// }