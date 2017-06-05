#ifndef FRACTOL_H
# define FRACTOL_H

# define WINX	2000
# define WINY	1000

# define ITER	50

typedef struct		s_fract
{
	char		type;
	void		*mlx;
	void		*win;

	int		iter;
	float		zoom;
	long double	x;
	long double	y;
	long double	zr;
	long double	zi;

	int		lock;
	int		bpp;
	int		ls;
	int		end;
}			t_fract;

t_fract			*setup(char fract);
void			run(t_fract *fract);
void			draw(t_fract *fract);

void			mandelbrot(t_fract *fract);
void			julia(t_fract *fract);
void			ship(t_fract *fract);
void			bird(t_fract *fract);

int			mouse(int button, int x, int y, void *param);
int			key(int key, void *param);
int			expose(void *param);
int			move(int x, int y, void *param);

char			*ito(long double nb);

#endif
