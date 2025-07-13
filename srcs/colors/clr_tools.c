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
		return ((alpha << 24) | (150 << 16) | (3 << 8) | 255);
	}
	alpha -= 20;
	r = (iterations * 2);
	g = (iterations * 1);
	b = (iterations * 40);
	
	return ((alpha << 24) | (r << 16) | (g << 8) | b);
}
