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

int keys_handler(int key, void *param)
{
	t_fractol *f = (t_fractol *)param;
	
	if (key == ESC)
		close_window(param);
	else if (key == SPACE)
		cycle_background_color(f);
	// if(key == SPACE)
	// 	switch_theme();
	return (0);
}