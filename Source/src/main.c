/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeghiaz <syeghiaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:09:56 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 08:06:06 by syeghiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, t_string *argv)
{
	t_data	*data;

	if (argc != 2)
		print_error_and_exit(WRONG_NUM_ARGS);
	if (!validate_input_file(argv[1]))
		print_error_and_exit(BAD_INPUT_FILE);
	data = data_init();
	parse(argv[1], data);
	if (data->error_code)
		print_error_free_and_exit(data, data->error_code);
	start_game(data);
}
