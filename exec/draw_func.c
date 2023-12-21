#include "../header.h"


// simple function from 42 mlx, its way faster than the normal mlx put
// because it doesnt communicate with the mlx API and it puts the colored pixel
// directly in the buffer. it gets displayed in the window when we call the mlx_put_image_to_window

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

// this function draws a square by iterating over the TILE_SIZE square and putting a colored pixel
// in each pixel of the square
void    draw_square(t_data *data, int x, int y, int color)
{ 
    int i;
    int j;

    i = 0;
    j = 0;
    while(i <= TILE_SIZE)
    {
        while(j <= TILE_SIZE)
        {
            // mlx_pixel_put(data->mlx, data->mlx_win, x + i, y + j, color);
            my_mlx_pixel_put(data, x + i, y + j, color);
            j++;
        }
        j = 0;
        i++;
    }
}

// obvious
void    draw_map(t_data *data)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    while(i <= ROWS)//
    {
        while(j <= COLUMNS)//
        {
            if(map[i][j] == '1')
                draw_square(data, (i * TILE_SIZE) + k, (j * TILE_SIZE), 0xf45d52);
            else
                draw_square(data, (i * TILE_SIZE) + k, (j * TILE_SIZE), 0xffffff);
            j++;
        }
        k++;
        j = 0;
        i++;
    }
}

// using the implementation of the pythagore theorem we know that
// (x - x(center)) * (x - x(center)) + (y - y(center)) * (y - y(center)) <= rayon^2
// if a point satisfies this condition then it is included in our circle of (x(center), y(center)) coordinates
// and rayon

void draw_circle(t_data *data, int x, int y)
{
    int i;
    int j;

    i = x - 10;
    while (i <= x + 10)
    {
        j = y - 10;
        while (j <= y + 10)
        {
            if ((i - x) * (i - x) + (j - y) * (j - y) <= 10 * 10)
            {
                my_mlx_pixel_put(data, i, j, 0x000000);
                // mlx_pixel_put(data->mlx, data->mlx_win, i, j, 0x000000);
            }
            j++;
        }
        i++;
    }
}

// obvious
void    draw_rect(t_data *data, int x, int y, int height)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if(data->check_test == 0)
    {
        while(j < height)
        {
             my_mlx_pixel_put(data, x + i, y + j, 0x808080);
            j++;
        }
    }
    else
    {
        while(j < height)
        {
             my_mlx_pixel_put(data, x + i, y + j, 0x808fd80);
            j++;
        }
    }

}