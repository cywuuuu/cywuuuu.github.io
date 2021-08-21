#include <stdio.h>
#include <string.h>

int main() {
	char str[105];
	int cnt = 0;
	gets(str);
	for (int i = 0; i < (int)(strlen(str)) - 3; i++) {
		if (str[i] == 'F' &&
			str[i + 1] == 'A' &&
			str[i + 2] == 'L' &&
			str[i + 3] == 'L') {
			cnt++;
		}
	}
	if (strlen(str) >= 4 &&
		str[strlen(str) - 4] == 'R' &&
		str[strlen(str) - 3] == 'I' &&
		str[strlen(str) - 2] == 'S' &&
		str[strlen(str) - 1] == 'E') {
		printf("RISE %d", cnt);
	} else {
		printf("FALL %d", cnt);
	}

	return 0;
}
