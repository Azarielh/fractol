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

#include "../../includes/fractol.h"

int get_color(int iterations, int max_iter)
{
	int rgb;
	int r;
	int g;
	int b;

	if (iterations == max_iter)
		return (0x000000);  // Noir simple pour le fond
	
	// Palette fixe simple et efficace
	r = (iterations * 9) % 256;
	g = (iterations * 15) % 256;
	b = (iterations * 25) % 256;

	rgb = (r << 16) | (g << 8) | b;
	return (rgb);
}
