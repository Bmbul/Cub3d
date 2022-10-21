/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stadevos <stadevos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 00:09:56 by stadevos          #+#    #+#             */
/*   Updated: 2022/10/21 00:09:57 by stadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, t_string *argv)
{
	t_data	*data;

	if (argc != 2)
		print_error_and_exit("Wrong number of arguments!!");
	if (!validate_input_file(argv[1]))
		print_error_and_exit("Bad input! Give valid file name");
	data = data_init();
	if (!parse(argv[1], data))
	{
		free_data(data);
		print_error_and_exit("BAD map! Try better one!!!");
	}
	start_game(data);
}
