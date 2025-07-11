/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_initialization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 06:14:52 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/11 06:14:52 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	init_themes(char *themes[4])
{
	themes[0] = "winter";
	themes[1] = "summer";
	themes[2] = "autumn";
	themes[3] = "spring";
}

void	init_background(int clr[8])
{
	clr[0] = 0x050510;  // Winter - Bleu nuit très profond
	clr[1] = 0x080815;  // Winter - Bleu nuit avec nuance
	clr[2] = 0x100805;  // Summer - Brun terre ultra sombre  
	clr[3] = 0x150503;  // Summer - Rouge terre profond
	clr[4] = 0x100705;  // Autumn - Brun automne profond
	clr[5] = 0x150a05;  // Autumn - Ocre ultra sombre
	clr[6] = 0x051005;  // Spring - Vert forêt profond
	clr[7] = 0x030a08;  // Spring - Vert émeraude ultra sombre
}

void init_color_palettes(int winter[3], int summer[3], int autumn[3], 
									int spring[3], int *init)
{
	winter[0] = 20;
	winter[1] = 20;
	winter[2] = 180;
	summer[0] = 200;
	summer[1] = 120;
	summer[2] = 40;
	autumn[0] = 30;
	autumn[1] = 150;
	autumn[2] = 255;
	spring[0] = 200;
	spring[1] = 50;
	spring[2] = 255;
	*init = 1;
}
