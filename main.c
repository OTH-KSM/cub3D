#include "header.h"

// exit (0);
    // data is the struct :
    /*
        typedef struct	s_FinalElem	{
        char	*no;
        char	*so;
        char	*we;
        char	*ea;
        int		F;
        int		C;
        int     height;
        int     width;
        char	**map;
        struct	s_FilanElem *next_elem;
    }	t_final;
    */
    // You have accsess to the map 
    // height and width are your infomation about the map that you wanted
    
int	main(int argc, char *argv[])
{
    t_final parse;
	t_data	img;
    if (validate_input_and_file(argc, argv))
        return (-1);
    img.parse = validate_file_content(argv[1]);

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, MAP_WIDTH, MAP_HEIGHT, "Hello world!");
	img.img = mlx_new_image(img.mlx, MAP_WIDTH, MAP_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    img.turn = 0;
    img.no = new_img(&img, img.parse->no);
    img.so = new_img(&img, img.parse->so);
    img.ea = new_img(&img, img.parse->ea);
    img.we = new_img(&img, img.parse->we);
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
