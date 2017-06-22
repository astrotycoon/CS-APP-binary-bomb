// 返回0 -- input == dst; 返回1 input != dst
int strings_not_equal(const char *input, const char *dst)
{
	int result;
	size_t len1 = strlen(input);
	size_t len2 = strlen(dst);

	if (len1 != len2) {
		result = 1;
	} else if (input[0] == '\0') {
		result = 0;
	} else { 
		result = 1;
		while (*input++ == *dst++) {
			if (*input == '\0') { 
				result = 0;
				break;	
			}
		}
	}

	return (result);	
}

int phase_1(const char *input)
{
	const char *dst = "Border relations with Canada have never been better.";
	int result = strings_not_equal(input, dst);
	if (result != 0) {
		explode_bomb();	
	}

	return (result);
}

