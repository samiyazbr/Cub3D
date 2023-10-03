/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkunnam- <hkunnam-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:31:36 by hkunnam-          #+#    #+#             */
/*   Updated: 2023/01/10 21:31:36 by hkunnam-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	const char *p = s;
	unsigned char ch = c;
	while (*p != '\0') {
		if (*p == ch) {
			return ((char *)p);
		}
		p++;
	}
	if (ch == '\0') {
		return ((char *)p);
	}
	return (NULL);
}
// char	*ft_strchr(const char *s, int c)
// {
// 	if (!s)
// 		return (NULL);
// 	unsigned char	ch;

// 	ch = c;
// 	while (*s)
// 	{
// 		if (*s == ch)
// 		{
// 			return ((char *)s);
// 		}
// 		s++;
// 	}
// 	if (c == '\0')
// 		return ((char *)s);
// 	return (NULL);
// }

/* int main()
{
	char str[] = "www.google.com";
	printf("%s", ft_strchr(str, 'o'));
} */