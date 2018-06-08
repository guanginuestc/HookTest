#include<Windows.h>

int main() {
	typedef void(*s)();
	HMODULE hl = LoadLibraryA("MyDll.dll");
	s setmyhook = (s)GetProcAddress(hl, "setmyhook");
	s unsetmyhook = (s)GetProcAddress(hl, "unsetmyhook");
	setmyhook();
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	unsetmyhook();
}