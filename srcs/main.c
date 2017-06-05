#include "libft.h"
#include "fractol.h"

#include <unistd.h>

static int	getfractal(char *str)
{
	if (!ft_strcmp(str, "julia"))
		return ('j');
	if (!ft_strcmp(str, "mandelbrot"))
		return ('m');
	if (!ft_strcmp(str, "ship"))
		return ('s');
	if (!ft_strcmp(str, "bird"))
		return ('b');
	return (0);
}

int		main(int argc, char **argv)
{
	t_fract		*fract;
	int		type;

	if (argc != 2 || !(type = getfractal(argv[1])))
		write(1, "usage : fractol [julia/mandelbrot/bird/ship]\n", 45);
	else if ((fract = setup(type)))
		run(fract);
	return (0);
}
