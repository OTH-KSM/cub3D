/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PassData.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omarchic <omarchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:24:25 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/21 16:54:44 by omarchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int     _RGBtoInt(int R, int G, int B)  {
    return ((R << 16) | (G << 8) | B);
}

void    _FreeMap(char **str)    {
    int i = 0;
    while (str[i])  {
        free(str[i]);
        i++;
    }
    free(str);
}

void    _FreeElem(t_elist *head)    {
    t_elist *tmp;
    while (head)    {
        if (head->Key)
            free(head->Key);
        if (head->Value1)
            free(head->Value1);
        if (head->Value2)
            free(head->Value2);
        if (head->Value3)
            free(head->Value3);
        tmp = head;
        head = head->next_elem;
        free(tmp);
    }
}

t_final _PassingTheData(t_elist *met, char **map, int lines)  {
    t_final data;
    t_elist *head;
    char    *tmp;
    head = met;
    int     i = 0;
    while (met) {
		// printf("%s\n%s\n%s\n%s\n", met->Key, met->Value1, met->Value2, met->Value3);
        if (!ft_strncmp(met->Key, "NO", 2))
            data.NO = ft_strdup(met->Value1);
        else if (!ft_strncmp(met->Key,"SO", 2))
            data.SO = ft_strdup(met->Value1);
        else if (!ft_strncmp(met->Key,"EA", 2))
            data.EA = ft_strdup(met->Value1);
        else if (!ft_strncmp(met->Key,"WE", 2))
            data.WE = ft_strdup(met->Value1);
        else if (!ft_strncmp(met->Key,"F", 1))
            data.F = _RGBtoInt(ft_atoi(met->Value1), ft_atoi(met->Value2), ft_atoi(met->Value3));
        else if (!ft_strncmp(met->Key,"C", 1))
            data.C = _RGBtoInt(ft_atoi(met->Value1), ft_atoi(met->Value2), ft_atoi(met->Value3));
        met = met->next_elem;
    }
    data.height = lines;
    /*pass the map*/
    data.map = ft_calloc(lines + 1, sizeof(char *));
    while (map[i])  {
        tmp = ft_strtrim(map[i], "*");
        if (i == 0)
            data.width = ft_strlen(tmp);
        data.map[i] = ft_strdup(tmp);
        free(tmp);
        i++;
    }
    _FreeElem(head);
    _FreeMap(map);
    return (data);
}