#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

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

static size_t string_length(const char *s)
{
	if (s[0] == '\0') {
		return (0);	
	}

	const char *p = s + 1;
	ptrdiff_t len = p - s;

	while (*p++ != '\0') {
		len = p - s;	
	}

	return (size_t)len;
}

void phase_5(const char *input)
{
	static int array[] = { 'm', 'a', 'd', 'u', 'i', 'e', 'r', 's', 'n', 'f', 'o', 't', 'v', 'b', 'y', 'l'};
	char str[7];
	size_t len = string_length(input);
   	if (len != 6) {
  		explode_bomb();		 
   	}

	int i;
	for (i = 0; i < 6; ++i) {
		str[i] = array[input[i] & 0x0f];	
	}
	str[6] = '\0';

	int result = strings_not_equal(str, "flyers"); 
	if (result != 0) {
		explode_bomb();	
	}
}

int main(int argc, const char *argv[])
{
	phase_5("ONEFG");
	return 0;
}
