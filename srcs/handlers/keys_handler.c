/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:23:27 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/08 19:23:27 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	switch_model(t_fractol *f)
{
	static char	*sets[5];
	static int	init;
	static int	index;

	if (!init)
	{
		sets[0] = "butterfly";
		sets[1] = "vortex";
		sets[2] = "lightning";
		sets[3] = "dragon de douady";
		sets[4] = "mandelbrot";
		init = 1;
	}
	if (index > 4)
		index = 0;
	f->set = sets[index++];
	choose_fractal(f);
}

int keys_handler(int key, void *param)
{	
	if (key == ESC)
		close_window(param);
	if (key == SPACE)
		switch_model(param);
	return (0);
}
