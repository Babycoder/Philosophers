/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayghazal <ayghazal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 00:20:23 by ayghazal          #+#    #+#             */
/*   Updated: 2021/10/14 15:08:45 by ayghazal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utill.h"

char	*ft_strdup(const char *s1)
{
	char		*ptr;
	int			len;

	len = ft_strlen(s1);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, len);
	ptr[len] = '\0';
	return (ptr);
}
