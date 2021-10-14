/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 22:51:50 by ayghazal          #+#    #+#             */
/*   Updated: 2021/10/14 15:03:54 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utill.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (char *)malloc(count * size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_bzero(ptr, size * count);
	return (ptr);
}
