/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeghiaz <syeghiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:10:18 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 08:08:27 by syeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_color(t_string color, int fd)
{
	write(fd, color, ft_strlen(color));
}

void	set_error_color(void)
{
	set_color(RED_TERM, 2);
}

void	print_error(int error_code)
{
	t_string	error;

	if (error_code == WRONG_NUM_ARGS)
		error = "Wrong Number of Arguments";
	else if (error_code == COULD_NOT_INIT)
		error = "Could not init Data";
	else if (error_code == BAD_INPUT_FILE)
		error = "Bad Input File!!!";
	else if (error_code == BAD_ARGUMENT)
		error = "Bad Argument!!!";
	else if (error_code == BAD_MAP)
		error = "Bad Input Map!!!";
	else if (error_code == TEXTURE_MISSING)
		error = "Could Not Validate a Texture";
	else if (error_code == WRONG_FILE_EXT)
		error = "An Argument Has Wrong File Extention";
	else if (error_code == BAD_ARG_FILE)
		error = "Could Not Open an Argument File";
	else
		error = "Unrecognized Line in The Input";
	set_error_color();
	write(2, "\nERROR! ", 8);
	write(2, error, ft_strlen(error));
	write(2, "\n\n", 2);
	set_color(WHITE_TERM, 2);
}

void	print_error_and_exit(int error_code)
{
	print_error(error_code);
	exit(error_code);
}

void	print_error_free_and_exit(t_data *data, int error_code)
{
	free_parsing_data(data);
	print_error_and_exit(error_code);
}
