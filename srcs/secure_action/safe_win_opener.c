/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_win_opener.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:19:37 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/08 17:19:37 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	*safe_win_opener(t_fractol *f, char *title)
{
	void	*win_ptr;

	win_ptr = mlx_new_window(f->mlx_ptr, f->width, f->height, title);
	if (win_ptr == 0)
		exit_n_free("Failed to open a new window", f, 2);
	return (win_ptr);
}
