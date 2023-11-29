/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okassimi <okassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:01:11 by okassimi          #+#    #+#             */
/*   Updated: 2023/11/29 11:04:40 by okassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int argc, char *argv[])  {
    if (_ValidateInputAndFile(argc, argv))
        return (-1);
    if (_ValidateFileContent(argv[1]))
        return (-1);
}