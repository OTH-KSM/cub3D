#ifndef CUBE3D_H
#define CUBE3D_H

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAP_HEIGHT 1920
#define MAP_WIDTH 1080
#define TILE_SIZE 64
#define ROWS 7
#define COLUMNS 10
#define FOV_ANGLE (60 * (M_PI / 180))
#define NUM_RAYS 1920
#define WALL_WIDTH 100

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
}				t_data;

int     is_wall(long x_touch, long y_touch);
int    check_ray(t_data *data, double x, double y);
void    cast_all_rays(t_data *data, double x, double y);
int    check_boundary(t_data *data, double add);
double count_distance(t_data *data, long x2, long y2);
float     check_interception(t_data *data, double angle);
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    draw_square(t_data *data, int x, int y, int color);
void    draw_map(t_data *data);
void draw_circle(t_data *data, int x, int y);
void    draw_rect(t_data *data, int x, int y, int height);
void    set_player(t_data *data);
double     set_angle(double angle);
int close_window(t_data *data);
int	key_hook(int keycode, t_data *data);
void    draw_3d(t_data *data, float distance, int x);
void	render_background(t_data *data);
void    render_game(t_data *data);
int	key_hook1(t_data *data);
int	press_up(int keycode, t_data *data);
int	press_down(int keycode, t_data *data);
#endif