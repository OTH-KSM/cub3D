#include "cube3d.h"

// this function draws the walls in each pixel
void    draw_3d(t_data *data, float distance, int x)
{
    float wall_height;
    float rayDistance;
    float distanceProjectionPlane;
    distanceProjectionPlane = (MAP_HEIGHT / 2) / tan(FOV_ANGLE / 2);
    wall_height = (TILE_SIZE / distance) * distanceProjectionPlane;
    // printf("TESTICN   %f  %f  %d %f \n",x + wall_height, (MAP_WIDTH / 2) - (wall_height / 2), x, distance);
    if((wall_height / 2) <= (MAP_WIDTH / 2) || wall_height == 0)
    {
        //printf("teststsetsetassdfasfdsfasdfasdfasdfasdfasdfasd\n");
        // printf("here is the problem %f\n\n", wall_height);
        draw_rect(data, x, (MAP_WIDTH / 2) - (wall_height / 2), wall_height);
        return;
    }
    draw_rect(data, x, 0, 1078);
}

// obvious
void	render_background(t_data *data)
{
    int	i;
    int	j;

    if (data->mlx_win == NULL)
        return ;
    i = 0;
    while (i < MAP_WIDTH)
    {
        j = 0;
        while (j < MAP_HEIGHT)
            my_mlx_pixel_put(data, j++, i, 0xffffff);
        ++i;
    }
}

// obvious
void    render_game(t_data *data)
{
   render_background(data);
    // draw_map(data);
//    draw_circle(data, data->player_x, data->player_y);
    // check_interception(data, data->rotationAngle);
    cast_all_rays(data, data->player_x, data->player_y);
    // draw_3d(data, data->ray_distance, 1);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);

    // cast_rays(data, data->player_x, data->player_y);
    // draw_triangle(data, x, y);
}
