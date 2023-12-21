#include "cube3d.h"

char map[ROWS][COLUMNS] = {
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    {'1', '0', '1', '0', '0', '0', '0', '0', '0', '1'},
    {'1', '0', '1', '0', '1', '0', '0', '0', '0', '1'},
    {'1', '0', '1', '1', '0', '0', '0', '0', '0', '1'},
    {'1', '0', '0', '0', '0', 'P', '0', '0', '0', '1'},
    {'1', '0', '0', '1', '0', '0', '0', '0', '0', '1'},
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
};

int	main(void)
{
	t_data	img;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, MAP_HEIGHT, MAP_WIDTH, "Hello world!");
	img.img = mlx_new_image(img.mlx, MAP_HEIGHT, MAP_WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    img.rotationAngle = M_PI;
    set_player(&img);
	render_game(&img);
    // mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
    //printf("%f\n", set_angle(180));
    mlx_hook(img.mlx_win, 2, 1L << 0, press_down, &img);
	mlx_hook(img.mlx_win, 3, 1L << 1, press_up, &img);
    mlx_hook(img.mlx_win, 17, 0, press_down, &img);
    mlx_loop_hook(img.mlx, &key_hook1, &img);
    // mlx_key_hook(img.mlx_win, key_hook, &img);
    mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
}