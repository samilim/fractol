/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 04:45:39 by salimon           #+#    #+#             */
/*   Updated: 2022/02/09 02:35:28 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

/*
** LINUX
*/
# ifdef __linux__
#  define ESC_KEY 65307
#  define LEFT_CLICK 1
#  define RIGHT_CLICK 3

#  define SCROLLUP_KEY 4
#  define SCROLLDOWN_KEY 5

#  define UP_KEY 65362
#  define DOWN_KEY 65364
#  define LEFT_KEY 65361
#  define RIGHT_KEY 65363

#  define SPACE_KEY 32

# else
/*
** MAC ; check OS ?
*/
#  define ESC_KEY 53

#  define SCROLLUP_KEY 4
#  define SCROLLDOWN_KEY 5

#  define UP_KEY 126
#  define DOWN_KEY 125
#  define LEFT_KEY 123
#  define RIGHT_KEY 124
# endif
#endif