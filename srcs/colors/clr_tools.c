/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 06:17:07 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/11 06:17:07 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int get_color(int iterations, int max_iter)
{
	int r;
	int g;
	int b;
	static int	alpha;

	if (iterations == max_iter)
	{
		alpha = 255;
		return ((alpha << 24) | (80 << 16) | (140 << 8) | 125);
	}
	alpha -= 5;
	r = iterations * (iterations * 0.8);
	g = iterations * (iterations * 0.5);
	b = iterations;
	
	return ((alpha << 24) | (r << 16) | (g << 8) | b);
}
