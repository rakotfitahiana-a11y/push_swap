/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henirako <henirako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 11:12:46 by henirako          #+#    #+#             */
/*   Updated: 2026/03/27 11:05:28 by henirako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_bench
{
	double	init_disorder;
	int		active;
	int		total_ops;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_bench;

void	apply_sort(t_stack **a, t_stack **b, char *mode, t_bench *bench);

void	print_benchmark(char *mode, t_bench *bench);

double	compute_disorder(t_stack *stack_a);

t_stack	*lst_new(int value);
void	add_back(t_stack **stack, t_stack *new_node);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	free_stack(t_stack **stack);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);

void	print_error(void);
int		is_number(char *str);
int		has_duplicate(t_stack *stack, int value);
int		ft_atoi(char *str, t_stack *stack);

char	**ft_split(char const *s, char c);

int		get_max_pos(t_stack *stack);
int		get_min_pos(t_stack *stack);

int		get_stack_size(t_stack *stack);

void	index_stack(t_stack *stack);

int		init_context(int argc, char **argv, t_bench *bench, char **mode);

void	parse_input(int argc, char **argv, t_stack **a, int *i);

void	sa(t_stack **stack_a, t_bench *bench);
void	sb(t_stack **stack_b, t_bench *bench);
void	ss(t_stack **stack_a, t_stack **stack_b, t_bench *bench);

void	pa(t_stack **stack_b, t_stack **stack_a, t_bench *bench);
void	pb(t_stack **stack_a, t_stack **stack_b, t_bench *bench);

void	ra(t_stack **stack_a, t_bench *bench);
void	rb(t_stack **stack_b, t_bench *bench);
void	rr(t_stack **stack_a, t_stack **stack_b, t_bench *bench);

void	rra(t_stack **stack_a, t_bench *bench);
void	rrb(t_stack **stack_b, t_bench *bench);
void	rrr(t_stack **stack_a, t_stack **stack_b, t_bench *bench);

void	sort_3(t_stack **a, t_bench *bench);
void	sort_4(t_stack **a, t_stack **b, t_bench *bench);
void	sort_5(t_stack **a, t_stack **b, t_bench *bench);

void	sort_simple(t_stack **a, t_stack **b, int size, t_bench *bench);
void	sort_medium(t_stack **a, t_stack **b, int size, t_bench *bench);
void	sort_complex(t_stack **a, t_stack **b, int size, t_bench *bench);
void	sort_adaptive(t_stack **a, t_stack **b, int size, t_bench *bench);

#endif