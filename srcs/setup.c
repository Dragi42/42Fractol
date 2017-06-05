/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 16:17:33 by dpaunovi          #+#    #+#             */
/*   Updated: 2017/06/05 16:17:39 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdlib.h>

t_fract		*setup(char type)
{
	t_fract	*fract;

	if (!(fract = malloc(sizeof(t_fract))))
		return (0);
	fract->type = type;
	fract->zoom = 1;
	fract->x = 0;
	fract->y = 0;
	fract->zr = 0;
	fract->zi = 0;
	fract->iter = ITER;
	fract->bpp = 32;
	fract->ls = WINX * 4;
	fract->end = 0;
	fract->lock = 0;
	return (fract);
}
