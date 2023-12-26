#include "../header.h"

// here is the main function of the project it returns the distance between the player and the wall
// using DDA
float     check_interception(t_data *data, double angle)
{
    double ray_angle = set_angle(angle);
    
    float distance;
    int is_up;
    int is_left;
    float wall_hit_x_horiz;
    float wall_hit_y_horiz;
    float wall_hit_x_verti;
    float wall_hit_y_verti;
    float x_horiz_intercept;
    float y_horiz_intercept;
    float x_verti_intercept;
    float y_verti_intercept;
    float x_horiz_step;
    float y_horiz_step;
    float x_verti_step;
    float y_verti_step;
    float x_horiz_touch;
    float y_horiz_touch;
    float x_verti_touch;
    float y_verti_touch;
    double horz_hit_distance;
    double verti_hit_distance;
    float wall_hit_x;
    float wall_hit_y;
    int found_horz_hit;
    int found_verti_hit;
    // problem is coming from x_step being negative from(0 ; pi/2) == (3pi/2 ; pi /2)
    is_up = 0;
    is_left = 0;
    found_horz_hit = 0;
    found_verti_hit = 0;
    data->check_test = 0;

    y_horiz_step = TILE_SIZE;
    x_horiz_step = y_horiz_step / tan(ray_angle);
    x_verti_step = TILE_SIZE;
    y_verti_step = x_verti_step * tan(ray_angle);
    if (ray_angle > M_PI && ray_angle < 2 * M_PI)//;
    {
        is_up = 1;
        y_horiz_step *= -1;
        y_horiz_intercept = floor(data->player_y / TILE_SIZE) * TILE_SIZE;
    }
    else// is_down = 1;
        y_horiz_intercept = (floor(data->player_y / TILE_SIZE) * TILE_SIZE) + TILE_SIZE;
    if((ray_angle > (M_PI / 2) && ray_angle < (3 * M_PI / 2)))
    {//is_left = 1;
        if(x_horiz_step > 0)
            x_horiz_step *= -1;
    }
    else//is_left = 1;
    {
        if(x_horiz_step < 0)
            x_horiz_step *= -1;
    }
    //else kayb9a dakchi normal      
    x_horiz_intercept = data->player_x + ((y_horiz_intercept - data->player_y) / tan(ray_angle));
    x_horiz_touch = x_horiz_intercept;
    y_horiz_touch = y_horiz_intercept;
    if(is_up == 1)
        y_horiz_touch--;
    // printf("ray_angle %f x_step %f y_step %f x_horiz %f y_horiz %f\n", ray_angle, x_horiz_step, y_horiz_step, x_horiz_touch, y_horiz_touch);    
    while(x_horiz_touch >= 0 && x_horiz_touch <= MAP_WIDTH && y_horiz_touch >= 0 && y_horiz_touch <= MAP_HEIGHT)
    {
        float x_to_check = x_horiz_touch;
        float y_to_check = y_horiz_touch;
        if(is_up == 1)
            y_to_check--;
        if(is_wall(data, x_to_check, y_to_check) == 1)
        {
            // printf("%ld   %ld\n", x_horiz_touch, y_horiz_touch);
    
            found_horz_hit = 1;
            wall_hit_x_horiz = x_horiz_touch;
            wall_hit_y_horiz = y_horiz_touch;
            break;
        }
        else
        {
            x_horiz_touch += x_horiz_step;
            y_horiz_touch += y_horiz_step;
        }
    }
    // cast_rays(data, data->player_x, data->player_y, x_horiz_touch, y_horiz_touch);
    ////////////????///////////                   ////////////////////////////////// //////////////////////// ///////////////////// //////
    if (ray_angle > M_PI_2 && ray_angle < 3 * M_PI_2)//;
    { 
        is_left = 1;
        x_verti_step *= -1;
        x_verti_intercept = floor(data->player_x / TILE_SIZE) * TILE_SIZE;
    }
    else// is_down = 1;
        x_verti_intercept = (floor(data->player_x / TILE_SIZE) * TILE_SIZE) + TILE_SIZE;
    if((ray_angle > M_PI && ray_angle < (2 * M_PI)))
    {//is_left = 1;
        if(y_verti_step > 0)
            y_verti_step *= -1;
    }
    else//is_left = 1;
    {
        if(y_verti_step < 0)
            y_verti_step *= -1;
    }
    //else kayb9a dakchi normal      
    y_verti_intercept = data->player_y + ((x_verti_intercept - data->player_x) * tan(ray_angle));
    x_verti_touch = x_verti_intercept;
    y_verti_touch = y_verti_intercept;
    if(is_left == 1)
        x_verti_touch--;
    // printf("ray_angle %f x_step %ld y_step %ld x_verti %ld y_verti_touch %ld\n", ray_angle, x_verti_step, y_verti_step, x_verti_touch, y_verti_touch);    
    while(x_verti_touch >= 0 && x_verti_touch <= MAP_WIDTH && y_verti_touch >= 0 && y_verti_touch <= MAP_HEIGHT)
    {
        float x_to_check = x_verti_touch;
        float y_to_check = y_verti_touch;
        if(is_left == 1)
            x_to_check--;
        if(is_wall(data, x_to_check, y_to_check))
        {
            // printf("%ld   %ld\n", x_verti_touch, y_verti_touch);
            found_verti_hit = 1;
            wall_hit_x_verti = x_verti_touch;
            wall_hit_y_verti = y_verti_touch;
            break;
        }
        else
        {
            x_verti_touch += x_verti_step;
            y_verti_touch += y_verti_step;
        }
    }
    // cast_rays(data, data->player_x, data->player_y, x_horiz_touch, y_horiz_touch);

    // maybe i should check if there is a wall hit ;
    if(found_horz_hit == 1)
        horz_hit_distance = count_distance(data, wall_hit_x_horiz, wall_hit_y_horiz);
    else
        horz_hit_distance = MAXFLOAT;
    if(found_verti_hit == 1)
        verti_hit_distance = count_distance(data, wall_hit_x_verti, wall_hit_y_verti);
    else
        verti_hit_distance = MAXFLOAT;
    if(verti_hit_distance < horz_hit_distance)
    {
        data->ray_distance = verti_hit_distance;

        // dont delete this you will need it for textures

        // data->hit_v_x = wall_hit_x_verti;
        // data->hit_v_y = wall_hit_y_verti;
        //was hit vertical;
        //wallhit  content
    }
    else
    {
        data->ray_distance = horz_hit_distance;
        // this too
        
        data->hit_x = wall_hit_x_horiz;
        data->hit_y = wall_hit_y_horiz;
        data->check_test = 1;
    }
    // if(horz_hit_distance < verti_hit_distance)
    //     wall_hit_x = wall_hit_x_horiz;
    // else
    //     wall_hit_x = wall_hit_x_verti;
    // if(horz_hit_distance < verti_hit_distance)
    //     wall_hit_y = wall_hit_y_horiz;
    // else
    //     wall_hit_y = wall_hit_y_verti;
    // if(horz_hit_distance < verti_hit_distance)
    // {
    //     data->check_test = 1;
    //     data->ray_distance = horz_hit_distance;
    // }
    // else
    //     data->ray_distance = verti_hit_distance;
    // printf("this is the distance %f //////   %f  %ld\n", verti_hit_distance, horz_hit_distance, LONG_MAX);
    return(data->ray_distance);
}