/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:38:13 by tvader            #+#    #+#             */
/*   Updated: 2021/04/25 17:27:33 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wcount(char const *str, char sep)
{
	size_t	cnt;
	size_t	wc;

	cnt = 0;
	wc = 0;
	while (*(str + cnt))
	{
		while (*(str + cnt) == sep && *(str + cnt))
			cnt++;
		if (*(str + cnt) != sep && *(str + cnt))
			wc += 1;
		while (*(str + cnt) != sep && *(str + cnt))
			cnt++;
	}
	return (wc);
}

static int	ft_nxtwlen(char const *str, char sep)
{
	int	nwlen;
	int	cnt;

	cnt = 0;
	nwlen = 0;
	while (*(str + cnt) == sep && *(str + cnt))
		cnt++;
	while (*(str + cnt) != sep && *(str + cnt))
	{
		cnt++;
		nwlen++;
	}
	return (nwlen);
}

static char	*ft_nxtw(char const *str, char sep, size_t len)
{
	char	*word;
	size_t	i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (*str == sep)
		str++;
	while (*str != sep && *str)
	{
		word[i] = *str;
		str++;
		i++;
	}
	word[i] = 0;
	return (word);
}

static char	**ft_brkfree(char **arr, int n)
{
	int	cnt;

	cnt = 0;
	while (cnt < n)
	{
		free(arr[cnt]);
		arr[cnt++] = NULL;
	}
	if (arr)
		free(arr);
	arr = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char		**res;
	size_t		wc;
	size_t		wcnt;

	if (!s)
		return (NULL);
	wcnt = 0;
	wc = ft_wcount(s, c);
	res = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!res)
		return (NULL);
	while (wcnt < wc)
	{
		while (*s == c)
			s++;
		res[wcnt] = ft_nxtw(s, c, ft_nxtwlen(s, c));
		if (!res[wcnt])
			return (ft_brkfree(res, wcnt));
		s += ft_nxtwlen(s, c);
		wcnt++;
	}
	res[wcnt] = NULL;
	return (res);
}
