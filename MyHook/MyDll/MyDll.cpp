#include<Windows.h>
#include<iostream>
using namespace std;
HHOOK gHook = NULL;
LRESULT CALLBACK proc(int nCode, WPARAM wParam, LPARAM lParam) {

	if (nCode == HC_ACTION) {
		if(wParam==WM_KEYDOWN)
			if (((KBDLLHOOKSTRUCT *)lParam)->vkCode == 0x41)
			{
				return 1;
			}
		
		
	}
	return CallNextHookEx(gHook, nCode, wParam, lParam);
}
void setmyhook() {
	gHook = SetWindowsHookEx(WH_KEYBOARD_LL, proc, GetModuleHandle(0), 0);
}
void unsetmyhook() {
	UnhookWindowsHookEx(gHook);
}