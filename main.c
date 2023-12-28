/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:15:36 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/28 22:21:15 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_mlx(t_data *img)
{
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, MAP_WIDTH,
			MAP_HEIGHT, "Cub3D");
	img->img = mlx_new_image(img->mlx, MAP_WIDTH, MAP_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->no = new_img(img, img->parse->no);
	img->so = new_img(img, img->parse->so);
	img->ea = new_img(img, img->parse->ea);
	img->we = new_img(img, img->parse->we);
}

int	main(int argc, char *argv[])
{
	t_final	parse;
	t_data	img;

	if (validate_input_and_file(argc, argv))
		return (-1);
	img.parse = validate_file_content(argv[1]);
	init_mlx(&img);
	set_player(&img);
	render_game(&img);
	mlx_hook(img.mlx_win, 2, 1L << 0, press_down, &img);
	mlx_hook(img.mlx_win, 3, 1L << 1, press_up, &img);
	mlx_hook(img.mlx_win, 17, 0, press_down, &img);
	mlx_loop_hook(img.mlx, &key_hook1, &img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
}
