/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 16:17:25 by dpaunovi          #+#    #+#             */
/*   Updated: 2017/06/05 16:17:27 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

#include <mlx.h>

void		draw(t_fract *fract)
{
	char	*tmp;

	mlx_clear_window(fract->mlx, fract->win);
	(fract->type == 'm') ? mandelbrot(fract) : 0;
	(fract->type == 'j') ? julia(fract) : 0;
	(fract->type == 's') ? ship(fract) : 0;
	(fract->type == 'b') ? bird(fract) : 0;
	mlx_string_put(fract->mlx, fract->win, 0, 0, 0x00ff00, "ZOOM");
	mlx_string_put(fract->mlx, fract->win, 50, 0, 0xffffff,
	(tmp = ito(fract->zoom)));
	mlx_string_put(fract->mlx, fract->win, 0, 20, 0x00ff00, "ITER");
	mlx_string_put(fract->mlx, fract->win, 50, 20, 0xffffff,
	(tmp = ito(fract->iter)));
	free(tmp);
	if (fract->type == 'j')
	{
		mlx_string_put(fract->mlx, fract->win, 0, 40, 0x00ff00, "LOCK");
		mlx_string_put(fract->mlx, fract->win, 50, 40, 0xffffff,
		fract->lock ? "1" : "0");
	}
}

void		run(t_fract *fract)
{
	void	*mlx;
	void	*win;

	if (!(mlx = mlx_init()) ||
	!(win = mlx_new_window(mlx, WINX, WINY, "y u readin dis")))
		return ((void)ft_errret("fractol", "an error has occured", 0));
	fract->mlx = mlx;
	fract->win = win;
	draw(fract);
	mlx_hook(fract->win, 6, (1L << 6), move, fract);
	mlx_key_hook(fract->win, key, fract);
	mlx_mouse_hook(fract->win, mouse, fract);
	mlx_expose_hook(fract->win, expose, fract);
	mlx_loop(mlx);
}
