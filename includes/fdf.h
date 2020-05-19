#ifndef FDF_H
# define FDF_H
# define WIN_HEIGHT 1000
# define WIN_WIDTH 1900
# define READ_BUFFER 4096
# define MAP_SIZE 6000000
# define NB_PROJECTIONS 4
# include "libft.h"
# include "mlx.h"

# ifdef __APPLE__
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_MINUS 0
# define KEY_PLUS 0
# define KEY_SPACE 0
# define KEY_CAPS 0
# define KEY_Z 13
# define KEY_Q 0
# define KEY_S 1
# define KEY_D 2
# define KEY_A 12
# define KEY_E 14
# define KEY_W 0
# define KEY_X 7
# define KEY_C 8
# define KEY_ENTER 0
# define KEY_LENTER 0
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 3
# define MOUSE_FRONT 5
# define MOUSE_BACK 4
# elif __unix
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_MINUS 65453
# define KEY_PLUS 65451
# define KEY_SPACE 32
# define KEY_CAPS 65505
# define KEY_Z 122
# define KEY_Q 113
# define KEY_S 115
# define KEY_D 100
# define KEY_A 97
# define KEY_E 101
# define KEY_W 119
# define KEY_X 120
# define KEY_C 99
# define KEY_ENTER 65293
# define KEY_LENTER 65421
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 3
# define MOUSE_FRONT 5
# define MOUSE_BACK 4
# endif

typedef struct	s_vector
{
	int16_t x;
	int16_t y;
	int16_t z;
}				t_vector;

typedef struct s_fvector
{
	float x;
	float y;
	float z;
}				t_fvector;

typedef struct	s_point
{
	int16_t x;
	int16_t y;
}				t_point;

typedef struct	s_segment
{
	t_point a;
	t_point b;
}				t_segment;

typedef struct	s_gdata
{
	char		*buf;
	int			map_state;
	void		*mlx;
	void		*mlx_win;
	void		*mlx_image;
	int32_t		bits_per_pixel;
	int32_t		*pixelmap;
	int32_t		size_line;
	int32_t		endian;
	int16_t		*map;
	t_vector	*vectors;
	int32_t		width;
	int32_t		height;
	int32_t		delta;
	int32_t		up_down;		
	int32_t		left_right;
	float		zoom;
	uint8_t		projection;
	int32_t	 	camera;
	float		angle_x;
	float		angle_y;
	float		angle_z;
	float		depth;
	int16_t		color;
	int			len;

}				t_gdata;

void			initiate_mlx(t_gdata *g);
int				free_mlx(t_gdata *g);
int				key_hook(int keycode, t_gdata *g);
int				mouse_hook(int keycode, int x, int y, t_gdata *g);

void			create_image_mlx(t_gdata *g);
void			reload_image(t_gdata *g);

void			rotation_x(t_gdata *g, int *i);
void			rotation_y(t_gdata *g, int *i);
void			rotation_z(t_gdata *g, int *i);

void			read_map(t_gdata *g, char **av);
void			put_pixel(int x, int y, int z, t_gdata *g);
void			put_segment(t_segment *s, t_gdata *g, int z);
void			link_points(t_gdata *g);
void			projection(t_gdata *g);
void			parsing(t_gdata *g, unsigned char *file, int len);
void			update_caption(t_gdata *g);

void			k_move_x(t_gdata *g, int keycode);
void			k_move_y(t_gdata *g, int keycode);
void			k_zoom(t_gdata *g, int keycode);
void			k_change_projection(t_gdata *g, int keycode);
void			k_change_delta(t_gdata *g, int keycode);
void			k_reset_values(t_gdata *g, int keycode);
void			k_change_depth(t_gdata *g, int keycode);
void			k_change_color_mode(t_gdata *g, int keycode);
void			k_rotate_x(t_gdata *g, int keycode);
void			k_rotate_y(t_gdata *g, int keycode);
void			k_rotate_z(t_gdata *g, int keycode);


#endif
