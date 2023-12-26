#include "../header.h"

// this function draws the walls in each pixel
void    draw_3d(t_data *data, float distance, int x)
{
    float wall_height;
    float rayDistance;
    float distanceProjectionPlane;
    distanceProjectionPlane = (MAP_WIDTH / 2) / tan(FOV_ANGLE / 2);
    wall_height = (TILE_SIZE / distance) * distanceProjectionPlane;
    // printf("TESTICN   %f  %f  %d %f \n",x + wall_height, (MAP_data->parse.width / 2) - (wall_height / 2), x, distance);
    float start = (MAP_HEIGHT / 2) - (wall_height / 2);
    if (start < 0)
        start = 0;
    float end = (MAP_HEIGHT / 2) + (wall_height / 2);
	if (end > MAP_HEIGHT)
		end = MAP_HEIGHT;

    unsigned int color = 0;
    int i = 0;
    while (i < start)
        my_mlx_pixel_put(data, x, i++, 0x5247863);
    floatz		distance_center_wall;
    int X = (int)(data->hit_x * data->NO->width / TILE_SIZE) % data->NO->width;
    // int X = data->NO->height * fmod(data->hit_x + data->hit_y, TILE_SIZE) / TILE_SIZE;
    while (i < end) {
        
        // // int X = data->NO->height * fmod(data->hit_x + data->hit_y, 64) / 64; 
        distance_center_wall = i + (wall_height / 2) - (MAP_HEIGHT / 2);
		// correspanding_y_coordinate = (int)(distance_center_wall * (float)d->tex->height / draw->h_wall) % d->tex->height;   
        int Y = (int)(distance_center_wall * (float)data->NO->height / wall_height ) % data->NO->height;
        color = bibo_mlx_pixel_put(data, X, Y);
        my_mlx_pixel_put(data, x, i, color);
        i++;

    }
    // // }
    // i += wall_height;
    while (i < MAP_HEIGHT) 
        my_mlx_pixel_put(data, x, i++, 0x1234567);
}

// obvious
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
void    render_game(t_data *data)
{
   render_background(data);
//    draw_circle(data, data->player_x, data->player_y);
    // check_interception(data, data->rotationAngle);
    cast_all_rays(data, data->player_x, data->player_y);
    // draw_3d(data, data->ray_distance, 1);
    // draw_map(data);
    // cast_rays(data, data->player_x, data->player_y);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);

    // draw_triangle(data, x, y);
}
