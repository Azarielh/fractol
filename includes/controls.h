/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze <jlacaze-@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:23:16 by jlacaze           #+#    #+#             */
/*   Updated: 2025/07/08 18:23:16 by jlacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H

# define CONTROLS_H

//__________________  KEYBOARD CODES  ________________
//_____Main keys
# define ESC			65307
# define ENTER			65293
# define SPACE			32

//____Arrows
# define UP_KEY			65362
# define DOWN_KEY		65364
# define LEFT_KEY		65361
# define RIGHT_KEY		65363

//__________________  MOUSE CODES  ________________
# define LEFT_CLICK		1
# define RIGHT_CLICK	2
# define MIDDLE_CLICK	3
# define SCROLL_UP		4
# define SCROLL_DOWN	5

//________________   Define Event Key   _________________
# define KeyPress		2
# define KeyRelase		3
# define ButtonPress	4
# define ButtonReleased	5
# define MotionNotify	6
# define DestroyNotify	17

#endif