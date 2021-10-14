/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:08:12 by ayghazal          #+#    #+#             */
/*   Updated: 2021/10/14 15:03:54 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utill.h"

char	*ft_strchr(const char *s, int c)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)s;
	while (temp[i] != c)
	{
		if (temp[i] != '\0')
		{
			i++;
		}
		else
			return (NULL);
	}
	return (temp + i);
}
