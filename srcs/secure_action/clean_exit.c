/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 00:21:56 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/12 00:21:56 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	clean_exit(t_fractol *f)
{
	if (f->img_ptr)
		mlx_destroy_image(f->mlx_ptr, f->img_ptr);
	if (f->win_ptr)
		mlx_destroy_window(f->mlx_ptr, f->win_ptr);
	if (f->mlx_ptr)
	{
		mlx_destroy_display(f->mlx_ptr);
		free(f->theme);
		free(f->mlx_ptr);
	}
	exit(0);
}