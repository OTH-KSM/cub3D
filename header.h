/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:01:34 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/21 18:53:31 by okassimi         ###   ########.fr       */
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

/*Validation*/
int			_ValidateInputAndFile(int argc, char *argv[]);
t_final		_ValidateFileContent(char *argv);
int*		_ReturnStatistics(char *argv);
t_elist*	_InializeLinkedList();
/*Phase01*/
t_elist		*_CheckEelements(int fd, int last);
bool		_ItMatchDir(t_elist *elem, char *sample, char **solutions, int token);
bool		_ItMatchCol(t_elist *elem, char *sample, char **solutions, int token);
int			_CheckDirValues(t_elist *elem);
int			_isDigit(char *str);
int			_CheckColValues(t_elist *elem);
/*Phase02*/
char		**_CheckMap(int fd, int maxlen, int lines, int last);
char		*_Fill(char *str, int maxlen);
/*Phase03*/
void		_ItterateTheMap(char **map, int mapL);
int			_ParsFirstLine(char **map, int mapL);
int			_ParsLastLine(char **map,int mapL);
int			_ParsMiddle(char **map, int mapL);
/*Pass Data*/
t_final		_PassingTheData(t_elist *met, char **map, int lines);
int			_RGBtoInt(int R, int G, int B);


void	free_2D_array(char **array);
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
    int move;
    int turn;
	t_final parse;
}				t_data;

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
void	draw_3d(t_data *data, float distance, int x);
void	render_background(t_data *data);
void	render_game(t_data *data);
int		key_hook1(t_data *data);
int		press_up(int keycode, t_data *data);
int		press_down(int keycode, t_data *data);

#endif