/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 03:44:23 by salimon           #+#    #+#             */
/*   Updated: 2022/02/09 04:14:37 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isfloat(char *str)
{
    int period;

    period = 0;
    if (*str == '.')
        return (0);
    while (*str)
    {
        if (*str == '.')
            period++;
	    else if (*str < '0' || *str > '9')
		    return (0);
        if (period > 1)
            return (0);
        str++;
    }
    return (1);
}