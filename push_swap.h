/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: klasak <klasak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/10 15:31:23 by klasak        #+#    #+#                 */
/*   Updated: 2022/04/26 15:23:14 by klasak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

int		parts(char const *s, char c);
char	**ft_split(char const *s, char c);
int		ft_check_only_sign(int argc, char *argv[]);
int		ft_check_dig_or_sign(int argc, char *argv[]);
int		ft_min_max(int argc, char *argv[]);
int		ft_atoi(const char *str);
int		ft_sorted_check(int argc, int *stack);
int		ft_duplicates(int argc, int *stack);
int		*ft_mapping(int argc, int *stack_a);
int		*ft_sort_3(int argc, int *stack_a);
int		*ft_sort_5(int argc, int *stack_a);
int		*ft_radix(int argc, int *stack_a);
int		*ft_case_1(int *stack_a);
int		*ft_case_2(int argc, int *stack_a);
int		*ft_case_3(int argc, int *stack_a);
int		*ft_case_4(int argc, int *stack_a);
int		*ft_case_5(int argc, int *stack_a);
int		*ft_create_empty_stack(int argc);
int		*ft_sb(int *stack);
int		*ft_rb(int argc, int *stack);
int		*ft_rrb(int argc, int *stack);
int		*ft_pb(int argc, int *stack_a, int *stack_b);
int		ft_real_size(int argc, int *stack);
int		*ft_move_by_1(int argc, int *stack);
int		find_smallest(int argc, int *stack);
int		*ft_digits(int argc, int *stack);
int		ft_find_max(int argc, int *stack);
int		ft_power(int digit);
int		*ft_rap(int argc, int *stack);
int		*ft_pbp(int argc, int *stack_a, int *stack_b);
int		ft_isdigit_or_sign(int c);
int		ft_isdigit(int c);
void	*free_each(char **array);

#endif