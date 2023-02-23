/**
 * @file
 * @author Isaiah Lateer
 * 
 * Processes and outputs key presses to the console
 */

#include <string>

#include <windows.h>

/**
 * Translates characters based on which modifier keys have been pressed
 * 
 * Interprets which keys are pressed and then translates how that information
 * will be presented based on which modifier keys are being pressed or held.
 * 
 * @param primary contains the primary character (ex: a, 1, /, ;)
 * @param secondary contains the secondary character (ex: A, !, ?, :)
 * @param win is a flag for whether the Windows key is being pressed or not
 * @param shift is a flag for whether either shift key is being pressed or not
 * @param caps is a flag for whether caps lock is enabled or not (this value
 *        should be set to false for keys that are not effected by caps lock)
 * @param ctrl is a flag for whether either control key is being pressed or not
 * @param alt is a flag for whether the alt key is being pressed or not
 * @return string containing the message to be displayed
 */
std::string translate(_In_ char primary, _In_ char secondary, _In_ bool win,
	_In_ bool shift, _In_ bool caps, _In_ bool ctrl, _In_ bool alt) {
	std::string text;
	if (win || ctrl || alt) {
		caps = false;
		text.append("<");
	}

	if (win)
		text.append("WIN + ");
	if (ctrl)
		text.append("CTRL + ");
	if (alt)
		text.append("ALT + ");

	if (shift ^ caps)
		text += secondary;
	else
		text += primary;

	if (win || ctrl || alt)
		text.append(">");
	return text;
}

/**
 * Hook procedure
 * 
 * Processes and outputs key events to the console. Then passes the hook
 * information to the next hook procedure in the hook chain.
 * 
 * @param code is used to determine how to process the hook information
 * @param wParam contains information depending on the type hook
 * @param lParam contains information depending on the type hook
 * @return value returned by the next hook procedure in the chain
 */
LRESULT CALLBACK procedure(_In_ int code, _In_ WPARAM wParam,
	_In_ LPARAM lParam) {
	static HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	static bool win = false;
	static bool shift = false;
	static bool caps = false;
	static bool ctrl = false;
	static bool alt = false;

	std::string log;

	if (code == HC_ACTION) {
		PKBDLLHOOKSTRUCT key = reinterpret_cast<PKBDLLHOOKSTRUCT>(lParam);

		switch (wParam) {
			case WM_KEYDOWN:
			case WM_SYSKEYDOWN:
				switch (key->vkCode) {
					case VK_BACK:
						log.append("<BACKSPACE>");
						break;
					case VK_TAB:
						log.append("<TAB>");
						break;
					case VK_RETURN:
						log.append("<RETURN>\r\n");
						break;
					case VK_CAPITAL:
						caps = !caps;
						break;
					case VK_ESCAPE:
						log.append("<ESC>");
						break;
					case VK_SPACE:
						log.append(" ");
						break;
					case VK_PRIOR:
						log.append("<PGDN>");
						break;
					case VK_NEXT:
						log.append("<PGUP>");
						break;
					case VK_END:
						log.append("<END>");
						break;
					case VK_HOME:
						log.append("<HOME>");
						break;
					case VK_LEFT:
						log.append("<LEFT>");
						break;
					case VK_UP:
						log.append("<UP>");
						break;
					case VK_RIGHT:
						log.append("<RIGHT>");
						break;
					case VK_DOWN:
						log.append("<DOWN>");
						break;
					case VK_SNAPSHOT:
						log.append("<PRTSC>");
						break;
					case VK_INSERT:
						log.append("<INS>");
						break;
					case VK_DELETE:
						log.append("<DEL>");
						break;
					case 48:
						log.append(translate('0', ')', win, shift, false,
							ctrl, alt));
						break;
					case 49:
						log.append(translate('1', '!', win, shift, false,
							ctrl, alt));
						break;
					case 50:
						log.append(translate('2', '@', win, shift, false,
							ctrl, alt));
						break;
					case 51:
						log.append(translate('3', '#', win, shift, false,
							ctrl, alt));
						break;
					case 52:
						log.append(translate('4', '$', win, shift, false,
							ctrl, alt));
						break;
					case 53:
						log.append(translate('5', '%', win, shift, false,
							ctrl, alt));
						break;
					case 54:
						log.append(translate('6', '^', win, shift, false,
							ctrl, alt));
						break;
					case 55:
						log.append(translate('7', '&', win, shift, false,
							ctrl, alt));
						break;
					case 56:
						log.append(translate('8', '*', win, shift, false,
							ctrl, alt));
						break;
					case 57:
						log.append(translate('9', '(', win, shift, false,
							ctrl, alt));
						break;
					case 65:
						log.append(translate('a', 'A', win, shift, caps,
							ctrl, alt));
						break;
					case 66:
						log.append(translate('b', 'B', win, shift, caps,
							ctrl, alt));
						break;
					case 67:
						log.append(translate('c', 'C', win, shift, caps,
							ctrl, alt));
						break;
					case 68:
						log.append(translate('d', 'D', win, shift, caps,
							ctrl, alt));
						break;
					case 69:
						log.append(translate('e', 'E', win, shift, caps,
							ctrl, alt));
						break;
					case 70:
						log.append(translate('f', 'F', win, shift, caps,
							ctrl, alt));
						break;
					case 71:
						log.append(translate('g', 'G', win, shift, caps,
							ctrl, alt));
						break;
					case 72:
						log.append(translate('h', 'H', win, shift, caps,
							ctrl, alt));
						break;
					case 73:
						log.append(translate('i', 'I', win, shift, caps,
							ctrl, alt));
						break;
					case 74:
						log.append(translate('j', 'J', win, shift, caps,
							ctrl, alt));
						break;
					case 75:
						log.append(translate('k', 'K', win, shift, caps,
							ctrl, alt));
						break;
					case 76:
						log.append(translate('l', 'L', win, shift, caps,
							ctrl, alt));
						break;
					case 77:
						log.append(translate('m', 'M', win, shift, caps,
							ctrl, alt));
						break;
					case 78:
						log.append(translate('n', 'N', win, shift, caps,
							ctrl, alt));
						break;
					case 79:
						log.append(translate('o', 'O', win, shift, caps,
							ctrl, alt));
						break;
					case 80:
						log.append(translate('p', 'P', win, shift, caps,
							ctrl, alt));
						break;
					case 81:
						log.append(translate('q', 'Q', win, shift, caps,
							ctrl, alt));
						break;
					case 82:
						log.append(translate('r', 'R', win, shift, caps,
							ctrl, alt));
						break;
					case 83:
						log.append(translate('s', 'S', win, shift, caps,
							ctrl, alt));
						break;
					case 84:
						log.append(translate('t', 'T', win, shift, caps,
							ctrl, alt));
						break;
					case 85:
						log.append(translate('u', 'U', win, shift, caps,
							ctrl, alt));
						break;
					case 86:
						log.append(translate('v', 'V', win, shift, caps,
							ctrl, alt));
						break;
					case 87:
						log.append(translate('w', 'W', win, shift, caps,
							ctrl, alt));
						break;
					case 88:
						log.append(translate('x', 'X', win, shift, caps,
							ctrl, alt));
						break;
					case 89:
						log.append(translate('y', 'Y', win, shift, caps,
							ctrl, alt));
						break;
					case 90:
						log.append(translate('z', 'Z', win, shift, caps,
							ctrl, alt));
						break;
					case VK_LWIN:
					case VK_RWIN:
						win = true;
						break;
					case VK_LSHIFT:
					case VK_RSHIFT:
						shift = true;
						break;
					case VK_LCONTROL:
					case VK_RCONTROL:
						ctrl = true;
						break;
					case VK_LMENU:
					case VK_RMENU:
						alt = true;
						break;
					case VK_OEM_1:
						log.append(translate(';', ':', win, shift, caps,
							ctrl, alt));
						break;
					case VK_OEM_PLUS:
						log.append(translate('=', '+', win, shift, caps,
							ctrl, alt));
						break;
					case VK_OEM_COMMA:
						log.append(translate(',', '<', win, shift, caps,
							ctrl, alt));
						break;
					case VK_OEM_MINUS:
						log.append(translate('-', '_', win, shift, caps,
							ctrl, alt));
						break;
					case VK_OEM_PERIOD:
						log.append(translate('.', '>', win, shift, caps,
							ctrl, alt));
						break;
					case VK_OEM_2:
						log.append(translate('/', '?', win, shift, caps,
							ctrl, alt));
						break;
					case VK_OEM_3:
						log.append(translate('`', '~', win, shift, caps,
							ctrl, alt));
						break;
					case VK_OEM_4:
						log.append(translate('[', '{', win, shift, caps,
							ctrl, alt));
						break;
					case VK_OEM_5:
						log.append(translate('\\', '|', win, shift, caps,
							ctrl, alt));
						break;
					case VK_OEM_6:
						log.append(translate(']', '}', win, shift, caps,
							ctrl, alt));
						break;
					case VK_OEM_7:
						log.append(translate('\'', '\"', win, shift, caps,
							ctrl, alt));
						break;
				}

				break;
			case WM_KEYUP:
			case WM_SYSKEYUP:
				switch (key->vkCode) {
					case VK_LWIN:
					case VK_RWIN:
						win = false;
						break;
					case VK_LSHIFT:
					case VK_RSHIFT:
						shift = false;
						break;
					case VK_LCONTROL:
					case VK_RCONTROL:
						ctrl = false;
						break;
					case VK_LMENU:
					case VK_RMENU:
						alt = false;
						break;
				}

				break;
		}
	}

	WriteConsoleA(out, log.c_str(), log.length(), NULL, NULL);
	return CallNextHookEx(NULL, code, wParam, lParam);
}

/**
 * Program entry-point
 * 
 * Standard Windows entry-point for C and C++ programs. Allocates a console
 * and then establishes a keyboard hook. Loops over messages, translating and
 * dispatching them. Once terminated, the hook is released and the console is
 * freed.
 * 
 * @param instance is the handle to the program when loaded in memory
 * @param prevInstance is used for backwards compatability with 16-bit Windows
 * @param cmdLine contains command-line arguments as a Unicode string
 * @param cmdShow is a flag used for how the application window is displayed
 * @return exit status
 */
int WINAPI wWinMain(_In_ HINSTANCE instance, _In_opt_ HINSTANCE prevInstance,
	_In_ PWSTR cmdLine, _In_ int cmdShow) {
	AllocConsole();
	HHOOK hook = SetWindowsHookExW(WH_KEYBOARD_LL, procedure, nullptr, NULL);

	MSG msg;
	while (!GetMessageW(&msg, nullptr, WM_KEYDOWN, WM_SYSKEYUP)) {
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	UnhookWindowsHookEx(hook);
	FreeConsole();
	return EXIT_SUCCESS;
}
