/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 04:45:39 by salimon           #+#    #+#             */
/*   Updated: 2021/11/12 06:29:45 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

/*
** LINUX
*/
# ifdef __linux__
#  define ESC_KEY 27

#  define SCROLLUP_KEY 
#  define SCROLLDOWN_KEY

#  define UP_KEY 38
#  define DOWN_KEY 40
#  define LEFT_KEY 37
#  define RIGHT_KEY 39

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