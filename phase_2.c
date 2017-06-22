static void read_six_numbers(const char *input, int *a)
{
	//					%rdi	     %rsi			%rdx    %rcx   %r8   %r9    (%rsp)  *(%rsp)
	int result = sscanf(input, "%d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]);
	if (result <= 5) {
		explode_bomb();	
	}
}

void phase_2(const char *input)
{
	int a[6];
	read_six_numbers(input, a);

	int *begin = &a[1];
	int *end = &a[6];

	for ( ; begin < end; ++begin) {
		int prev_value = begin[-1] * 2;
		if (prev_value != begin[0]) {
			explode_bomb();	
		}
	}
}

