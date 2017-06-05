/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 16:15:37 by dpaunovi          #+#    #+#             */
/*   Updated: 2017/06/05 16:15:46 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

int		mouse(int button, int x, int y, void *param)
{
	t_fract		*fract;

	fract = param;
	if (button == 1)
	{
		fract->x += fract->x + 2 * (x - WINX / 2);
		fract->y += fract->y + 2 * (y - WINY / 2);
		fract->zoom *= 2;
	}
	else if (button == 2 && fract->zoom > 0.5)
	{
		fract->zoom /= 2;
		fract->x /= 2;
		fract->y /= 2;
	}
	draw(fract);
	return (1);
}

int		key(int keycode, void *param)
{
	t_fract		*fract;

	fract = param;
	if (keycode == 37)
		fract->lock = fract->lock ? 0 : 1;
	else if (keycode == 51)
	{
		fract->iter = ITER;
		fract->zoom = 1;
		fract->x = 0;
		fract->y = 0;
	}
	else if (keycode == 13 || keycode == 1)
		fract->y += (keycode == 1 ? 1 : -1) * (WINY / 50);
	else if (keycode == 0 || keycode == 2)
		fract->x += (keycode == 2 ? 1 : -1) * (WINX / 50);
	else if (keycode == 24 || (keycode == 27 && fract->iter > 10))
		fract->iter += keycode == 24 ? 10 : -10;
	else if (keycode == 53)
		exit(0);
	else
		return (1);
	draw(fract);
	return (1);
}

int		expose(void *param)
{
	draw(param);
	return (1);
}

int		move(int x, int y, void *param)
{
	t_fract		*fract;

	fract = param;
	if (fract->lock == 0 && (fract->type == 'j' || fract->type == 'x'))
	{
		fract->zr = 2 * ((long double)x - WINX / 2) / WINX;
		fract->zi = 2 * ((long double)y - WINY / 2) / WINY;
		draw(fract);
	}
	return (1);
}
