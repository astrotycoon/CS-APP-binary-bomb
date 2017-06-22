#include <stdio.h>
#include <stdlib.h>

static void read_six_numbers(const char *input, int *a)
{
	//					%rdi	     %rsi			%rdx    %rcx   %r8   %r9    (%rsp)  *(%rsp)
	int result = sscanf(input, "%d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]);
	if (result <= 5) {
		explode_bomb();	
	}
}

struct node {
	int value;
	int seq;
	struct node *next;	
};

struct node node6 = {
	0x000001bb, 6, NULL 
};

struct node node5 = {
	0x000001dd, 5, &node6
};

struct node node4 = {
	0x000002b3, 4, &node5
};

struct node node3 = {
	0x0000039c, 3, &node4
};

struct node node2 = {
	0x000000a8, 2, &node3
};

struct node node1 = {
	0x0000014c, 1, &node2
};

void phase_6(const char *input)
{
	int a[6]; 
	struct node *nodes[6];

	read_six_numbers(input, a);

	// %r13
	int *pa = a;
	// %r12d
	int i = 0;

	for ( ;; ) {
		if (*pa > 6) {
			explode_bomb();
		}
		++i;

		if (i == 6) break;

		int j = i;
		do {
			if (*pa == a[j]) {
				explode_bomb();
			}
			j++;
		} while (j <= 5);

		++pa;
	}

	int *begin = &a[0];
	int *end = &a[6];
	do {
		*begin = 7 - *begin;
		++begin;	
	} while (begin != end);

	i = 0;
	do {
		if (a[i] <= 1) {
			nodes[i] = &node1;
		} else {
			int j = 1;
			struct node *pnode = &node1; 
			do {
				pnode = pnode->next;	
				++j;	
			} while (j != a[i]);
			nodes[i] = pnode;
		}
		++i;
	} while (i != 6);

	struct node *head = nodes[0];		// %rbx
	struct node **begin_node = &nodes[1];	// %rax
	struct node **end_node = &nodes[6];		// %rsi
	struct node *tmp;				// %rdx

	for ( ;; ) {
		// %rdx
		tmp = *begin_node;
		head->next = tmp;
		++begin_node;
		if (begin_node == end_node) break;
		head = tmp;	
	}
	tmp->next = NULL;
		
	i = 5;
	head = nodes[0];
	do {
		tmp = head->next;
		if (head->value < tmp->value) {
			explode_bomb();	
		}
		head = tmp;
		--i;	
	} while (i != 0);

	printf("sucess\n");
}

#if 0
int main(int argc, const char *argv[])
{
	phase_6(argv[1]);		
	return 0;
}
#endif
