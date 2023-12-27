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
    while(i < data->parse.height)//
    {
        while(j < data->parse.width)//
        {
            if(data->parse.map[i][j] == '1')
                draw_square(data, (i * TILE_SIZE) + k, (j * TILE_SIZE), 0xf45d52);
            else
                draw_square(data, (i * TILE_SIZE) + k, (j * TILE_SIZE), 0xffffff);
            j++;
        }
        k++;
        j = 0;
        i++;
    }
    double x = data->player_x;
    double y = data->player_y;
    while (j < 100)
        {
                my_mlx_pixel_put(data, x, y, 0x000000);
                // mlx_pixel_put(data->mlx, data->mlx_win, x, y, 0x000000);
                x = x + cos(data->rotationAngle);
                y = y + sin(data->rotationAngle);
            j++;
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

t_txt	*new_img(t_data *data, char *path)
{
    static int i;
    t_txt	*txt;
	txt = (t_txt *) malloc(sizeof(t_txt));
    if (!txt)
        exit (0);
	txt->img = mlx_xpm_file_to_image(data->mlx, path,
			&txt->width, &txt->height);
	if (!txt->img)  {
		printf("invalid img\n");
        exit (0);
    }
	txt->addr = mlx_get_data_addr(txt->img, &txt->bits_per_pixel,
			&txt->line_lenght, &txt->endian);
	if (!txt->addr)  {
		printf("invalid address path\n");
        exit (0);
    }
    i++;
	return (txt);
}

unsigned int    bibo_mlx_pixel_put(t_data *data, int x, int y)
{
	char	*mlx_data_addr;
	unsigned int	pos;

	mlx_data_addr = data->tmp->addr + y * data->tmp->line_lenght + x * (data->tmp->bits_per_pixel / 8);
	return (*(unsigned int *)mlx_data_addr);
}

// --------------------------------------------------------------------------------------------------------------
// {
//     void	render_3d_map(t_data *d, t_draw *draw, int x)
// {
// 	int		i;
// 	int		distance_center_wall;
// 	int		correspanding_y_coordinate;
// 	char	*dst;

// 	i = 0;
// 	while (i < draw->t_wall)
// 		my_mlx_pixel_put(d->img, draw->x, i++, d->ceil);
// 	while (i < draw->b_wall)
// 	{
// 		distance_center_wall = i + (draw->h_wall / 2) - (HMAP / 2);
// 		correspanding_y_coordinate = (int)(distance_center_wall * (float)d->tex->height / draw->h_wall) % d->tex->height;
// 		dst = d->tex->addr + correspanding_y_coordinate * d->tex->size_line + x * (d->tex->bits_per_pixel / 8);
// 		my_mlx_pixel_put(d->img, draw->x, i, *(unsigned int *)dst);
// 		i++;
// 	}
// 	while (i < HMAP)
// 		my_mlx_pixel_put(d->img, draw->x, i++, d->floor);
// }

// }

// --------------------------------------------------------------------------------------------------------------

// obvious
// void    draw_rect(t_data *data, int x, int y, int height)
// {
//     int i;
//     int j;
//     unsigned int color;
//     int l;
//     int g;

//     i = 0;
//     j = 0;
//     int y1;
//     y1 = y;

//     // if(data->check_test == 0)
//     // {
//         // data->NO = new_img(data, data->parse.NO);
        
//         int X = data->NO->height * fmod(data->hit_x + data->hit_y, 64) / 64;    
//         while(j < height)
//         {
//             int Y = data->NO->width * ((y + j) - y1) / height;
//             color = bibo_mlx_pixel_put(data, X, Y);
//             my_mlx_pixel_put(data, x, y + j, color);
//             j++;
//         }
//     // }
//     // else
//     // {
//     //     while(j < height)
//     //     {
//     //          my_mlx_pixel_put(data, x + i, y + j, 0x808fd80);
//     //         j++;
//     //     }
//     // }

// }