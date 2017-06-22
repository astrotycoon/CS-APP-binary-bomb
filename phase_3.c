

void phase_3(const char *input)
{
	//  0x8(%rsp)  0xc(%rsp)
	int num1, num2;
	//     %rdi     %rsi   %rdx   %rcx 
	int result = sscnaf(input, "%d %d", &num1, &num2);
	if (result <= 1) {
		explode_bomb();	
	}

	switch (num1) {
		case 0:	// 0 207
			if (num2 != 0xcf) {
				explode_bomb();
			}
			break;
		case 1:	// 1 311
			if (num2 != 0x137) {
				explode_bomb();
			}
			break;
		case 2:	// 2 707
			if (num2 != 0x2c3) {
				explode_bomb();	
			}
			break;
		case 3:	// 3 256
			if (num2 != 0x100) {
				explode_bomb();	
			}
			break;
		case 4:	// 4 389
			if (num2 != 0x185) {
				explode_bomb();
			}
			break;
		case 5:	// 5 206
			if (num2 != 0xce) {
				explode_bomb();	
			}
			break;
		case 6:	// 6 682
			if (num2 != 0x2aa) {
				explode_bomb();	
			}
			break;
		case 7:	// 7 327
			if (num2 != 0x147) {
				explode_bomb();	
			}
			break;
		default:
			explode_bomb();
			break;
	}
}
