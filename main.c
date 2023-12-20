/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:01:11 by okassimi          #+#    #+#             */
/*   Updated: 2023/12/20 16:39:07 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int argc, char *argv[])  {
    t_final data;
    if (_ValidateInputAndFile(argc, argv))
        return (-1);
    data = _ValidateFileContent(argv[1]);
    printf("%s\n", data.NO);
	printf("%s\n", data.SO);
	printf("%s\n", data.WE);
	printf("%s\n", data.EA);
	printf("%d\n", data.F);
	printf("%d\n", data.C);
	// printf("%s\n", data.map[0]);
    int i = 0;
    while (data.map[i])  {
        printf("%s\n", data.map[i]);
        i++;
    }
    return (0);
}
