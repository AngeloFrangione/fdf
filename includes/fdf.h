#ifndef FDF_H
# define FDF_H
# define WIN_HEIGHT 900
# define WIN_WIDTH 1800
# define READ_BUFFER 4096
# define MAP_SIZE 6000000
# include "libft.h"
# include "mlx.h"

typedef struct	s_vector
{
	int16_t x;
	int16_t y;
	int16_t z;
}				t_vector;

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
	void		*mlx;
	void		*mlx_win;
	void		*mlx_image;
	int			bits_per_pixel;
	int			*pixelmap;
	int			size_line;
	int			endian;
	int16_t		*map;
	t_vector	*vectors;
	int			width;
	int			height;
}				t_gdata;

typedef void (*t_func)();

void			initiate_mlx(t_gdata *g);
void			free_mlx(t_gdata *g);
int				key_hook(int keycode, t_gdata *g);

void			read_map(t_gdata *g, char **av);
void			put_pixel(int x, int y, int z, int *image);
void			put_segment(t_segment *s, int *image, int z);
void			link_points(t_gdata *g);
void			projection(t_gdata *g);
void			parsing(t_gdata *g, unsigned char *file, int len);

#endif
