#include <wchar.h>
int main(int argc, char** argv) {

	const wchar_t*p = L"Kraków";
	size_t i ,j;
	

	for (j = 0; j < wcslen(p); j++) {
		unsigned char*a = (unsigned char*)(p + j);

		for (i = 0; i < sizeof(wchar_t); i++) {
			printf("%02x", (a + i));
		}
		printf("|");
	}
	return 0;
}