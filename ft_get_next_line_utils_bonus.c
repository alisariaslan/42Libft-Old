/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:13:33 by mkucukku          #+#    #+#             */
/*   Updated: 2022/12/02 15:14:32 by msariasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_line(char *str)
{
	int		i;
	char	*custom_str;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	custom_str = malloc(sizeof(char) * i + 1);
	if (!custom_str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		custom_str[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		custom_str[i] = str[i];
		i++;
	}
	custom_str[i] = '\0';
	return (custom_str);
}

char	*ft_new_str(char *str)
{
	int		i;
	int		j;
	char	*custom_str;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	custom_str = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!custom_str)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		custom_str[j++] = str[i++];
	custom_str[j] = '\0';
	free (str);
	return (custom_str);
}
