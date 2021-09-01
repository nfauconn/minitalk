/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:09:26 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/01 18:16:40 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*void	send_signal(char **argv)
{
	int	sig_num;
	int	str;

	sig_num = ft_atoi(argv[1]);
	str = ft_atoi_base(argv[2]);
}*/

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("wrong number of arguments\nformat : ./client <PID> <string_to_display>\n");
		exit(EXIT_FAILURE);
	}
	else
		printf("ok\n");
//		send_signal(argv);
	return (0);
}
