#include "../header.h"

// this function iterates over the map searching for the player
void    set_player(t_data *data)
{
    int i;
    int j;
    int step;

    i = 0;
    j = 0;
    step = TILE_SIZE / 2;
    while (i < ROWS)
    {
        while (j < COLUMNS)
        {
            if(map[i][j] == 'P')
            {
                data->player_x = (i * TILE_SIZE) + step + 5;// 5 is arbitrary
                data->player_y = (j * TILE_SIZE) + step + 5;
            }
            j++;
        }
        j = 0;
        i++;
    }
}

// this function assures that the angle we have is always between 0 and 2 pi
double     set_angle(double angle)
{
    angle = fmod(angle , (2 * M_PI));
    if(angle < 0)
        angle = (2 * M_PI) + angle;
    return(angle);
}