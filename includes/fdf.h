#ifndef FDF_H
# define FDF_H
# define WIN_HEIGHT 800
# define WIN_WIDTH 800
# define GRID_SPACEMENT 25
# define CORNER_SPACEMENT 150
# define READ_BUFFER 5000000
# include "libft.h"
# include "mlx.h"

typedef struct	s_vector
{
	uint16_t x;
	uint16_t y;
	uint16_t z;
}				t_vector;

typedef struct	s_point
{
	uint16_t x;
	uint16_t y;
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
	int			size_line;
	int			endian;
	uint16_t	*pixelmap;
	/*uint16_t	map[READ_BUFFER];*/
	t_vector	vectors[11*19];
	int			width;
	int			height;
}				t_gdata;

void			initiate_mlx(t_gdata *g);
void			free_mlx(t_gdata *g);
int				key_hook(int keycode, t_gdata *g);

void			parsing(t_gdata *g, char **av);
void			put_pixel(int x, int y, int *image);
void			put_pixel_c(int x, int y, int z, int *image);
void			put_segment(t_segment *s, int *image);
void			link_points(t_gdata *g);
void			projection(t_gdata *g);

#endif
