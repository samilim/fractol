/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 04:45:39 by salimon           #+#    #+#             */
/*   Updated: 2021/11/08 09:00:28 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

/*
** LINUX
*/
# ifdef __linux__
#  define ESC_KEY 27

#  define ZOOMIN_KEY 
#  define ZOOMOUT_KEY

#  define UP_KEY 
#  define DOWN_KEY 
#  define LEFT_KEY 
#  define RIGHT_KEY

# else
/*
** MAC ; check OS ?
*/
#  define ESC_KEY 53

#  define ZOOMIN_KEY 
#  define ZOOMOUT_KEY

#  define UP_KEY 126
#  define DOWN_KEY 125
#  define LEFT_KEY 123
#  define RIGHT_KEY 124
# endif
#endif