/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:01:34 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/28 13:19:25 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "fcntl.h"
# include "stdbool.h"
# include <mlx.h>
# include <math.h>
# include <limits.h>

#define MAP_WIDTH 1920
#define MAP_HEIGHT 1080
#define TILE_SIZE 64
#define ROWS 7
#define COLUMNS 10
#define FOV_ANGLE (60 * (M_PI / 180))
#define NUM_RAYS 1920
#define WALL_WIDTH 100
#define _NO 4.72
#define _EA 0
#define _SO 1.57
#define _WE 3.14

/****************************************************************************************************/
typedef struct	s_elemlist	{
	char	*Key;
	char	*Value1;
	char	*Value2;
	char	*Value3;
	int		found;
	int		Genre;	// 0 = Dir || 1 = Col
	struct	s_elemlist *next_elem;
}	t_elist;

typedef struct	s_FinalElem	{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		F;
	int		C;
	int		width;
	int		height;
	char	**map;
	struct	s_FilanElem *next_elem;
}	t_final;

typedef struct s_txt {
	void 	*img;
	char	 *addr;
	int		bits_per_pixel;
	int 	line_lenght;
	int 	endian;
	int  	width;
	int 	height;
}				t_txt;

/*Validation*/
int			_ValidateInputAndFile(int argc, char *argv[]);
t_final		*_ValidateFileContent(char *argv);
int*		_ReturnStatistics(char *argv);
t_elist*	_InializeLinkedList();
/*Phase01*/
t_elist	*check_elements(int fd, int last);
char	*removespaces(char *str);
void	verify_filling(t_elist *elem);
void	fill_col(t_elist *elem, char *line);
void	fill_dir(t_elist *elem, char *line);
bool	it_match_dir(t_elist *elem, char *sample, char **solutions, int token);
bool	it_match_col(t_elist *elem, char *sample, char **solutions, int token);
int	check_dir_values(t_elist *elem);
int	is_digit(char *str);
int	check_col_values(t_elist *elem);
/*Phase02*/
char	**check_map(int fd, int maxlen, int lines, int last);
char	*fill(char *str, int maxlen);
/*Phase03*/
void		_ItterateTheMap(char **map, int mapL);
int			_ParsFirstLine(char **map, int mapL);
int			_ParsLastLine(char **map,int mapL);
int			_ParsMiddle(char **map, int mapL);
/*Pass Data*/
t_final		*passing_the_data(t_elist *met, char **map, int lines);
void		pass_elem(t_elist *met, t_final *data);
void		pass_map(char **map, t_final *data, int lines);
int			rgb_to_int(int R, int G, int B);

int		print_error_and_return(char *str);
void	print_error_and_exit(char *str);
void	free_elem(t_elist *head);
void	free_2d_array(char **array);
/****************************************************************************************************/

extern char map[ROWS][COLUMNS];

typedef struct	s_data {
    void    *mlx;
    void    *mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    float   player_x;
    float   player_y;
    float   p_width;
    float   p_height;
    int     turnDirection; // -1 for left, +1 for right
    int     walkDirection; //-1 for back, +1 for front
    float   rotationAngle;
    float   walkSpeed;
    float   turnSpeed;
    float    ray_distance;
    int check_test;
	float  hit_h_x;
	float hit_h_y;
	float hit_v_x;
	float hit_v_y;
    int move;
    int turn;
	t_txt	*NO;
	t_txt	*SO;
	t_txt	*EA;
	t_txt	*WE;
	t_txt	*tmp;
	t_final *parse;
}				t_data;

typedef struct s_dda{
	double ray_angle;
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
	float x_to_check;
	float y_to_check;
    float wall_hit_x;
    float wall_hit_y;
    int found_horz_hit;
    int found_verti_hit;
}					t_dda;


unsigned int    bibo_mlx_pixel_put(t_data *data, int x, int y);
t_txt	*new_img(t_data *data, char *path);


int		is_wall(t_data *data, long x_touch, long y_touch);
int		check_ray(t_data *data, double x, double y);
void	cast_all_rays(t_data *data, double x, double y);
int		check_boundary(t_data *data, double add);
double	count_distance(t_data *data, long x2, long y2);
float	check_interception(t_data *data, double angle);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    draw_square(t_data *data, int x, int y, int color);
void    draw_map(t_data *data);
void	draw_circle(t_data *data, int x, int y);
void	draw_rect(t_data *data, int x, int y, int height);
void	set_player(t_data *data);
double	set_angle(double angle);
int		close_window(t_data *data);
int		key_hook(int keycode, t_data *data);
void	draw_3d(t_data *data, float distance, int x, float angle);
void	render_background(t_data *data);
void	render_game(t_data *data);
int		key_hook1(t_data *data);
int		press_up(int keycode, t_data *data);
int		press_down(int keycode, t_data *data);
void    init_dda(t_dda *t, t_data *data, double angle);
#endif