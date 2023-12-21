#include "../header.h"

void    set_p_view(t_data *data, char direction)
{
    if (direction == 'N')
        data->rotationAngle = 3 * M_PI / 2;
    else if (direction == 'S')
        data->rotationAngle = M_PI / 2;
    else if (direction == 'E')
        data->rotationAngle = 0;
    else if (direction == 'W')
        data->rotationAngle = M_PI;
}
// this function iterates over the map searching for the player
void    set_player(t_data *data)
{
    int i;
    int j;
    int step;

    i = 0;
    j = 0;
    step = TILE_SIZE / 2;
    while (i < data->parse.height)
    {
        while (j < data->parse.width)
        {
            if(data->parse.map[i][j] == 'N' || data->parse.map[i][j] == 'W' || data->parse.map[i][j] == 'E' || data->parse.map[i][j] == 'S')
            {
                data->player_x = (i * TILE_SIZE) + step + 5;// 5 is arbitrary
                data->player_y = (j * TILE_SIZE) + step + 5;
                set_p_view(data, data->parse.map[i][j]);
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