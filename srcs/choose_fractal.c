/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:55:14 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/09 20:55:14 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * get the 'set' parametter from s_fractol struct found int the header.
 * 
 * if set == M or m
 *			→ call render_mandelbrot
 *
 * if set == J or j
 *			→ call render_julia
 * else
 *			→ call help function
 */
void	choose_fractal(t_fractol *f)
{
	if (ft_strcmp_2(f->set, "mandelbrot", "m") == 0)
		render_mandelbrot(f);
	if (ft_strcmp_2(f->set, "julia", "j") == 0)
		render_julia(f);
}
