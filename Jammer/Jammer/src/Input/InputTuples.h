
#pragma once
#include <stdint.h>

namespace jam {
	typedef uint32_t MouseKey;
	typedef uint32_t KeyCode;
	namespace MouseKeys {
		constexpr jam::MouseKey MOUSE_BUTTON_1 = 0;
		constexpr jam::MouseKey MOUSE_BUTTON_2 = 1;
		constexpr jam::MouseKey MOUSE_BUTTON_3 = 2;
		constexpr jam::MouseKey MOUSE_BUTTON_4 = 3;
		constexpr jam::MouseKey MOUSE_BUTTON_5 = 4;
		constexpr jam::MouseKey MOUSE_BUTTON_6 = 5;
		constexpr jam::MouseKey MOUSE_BUTTON_7 = 6;
		constexpr jam::MouseKey MOUSE_BUTTON_8 = 7;
		constexpr jam::MouseKey MOUSE_BUTTON_LEFT = MOUSE_BUTTON_1;
		constexpr jam::MouseKey MOUSE_BUTTON_RIGHT = MOUSE_BUTTON_2;
		constexpr jam::MouseKey MOUSE_BUTTON_MIDDLE = MOUSE_BUTTON_3;

	}

	namespace KeyCodes {
		constexpr jam::KeyCode KEY_SPACE = 32;
		constexpr jam::KeyCode KEY_APOSTROPHE = 39;  /* ' */
		constexpr jam::KeyCode KEY_COMMA = 44;  /* , */
		constexpr jam::KeyCode KEY_MINUS = 45;  /* - */
		constexpr jam::KeyCode KEY_PERIOD = 46;  /* . */
		constexpr jam::KeyCode KEY_SLASH = 47;  /* / */
		constexpr jam::KeyCode KEY_0 = 48;
		constexpr jam::KeyCode KEY_1 = 49;
		constexpr jam::KeyCode KEY_2 = 50;
		constexpr jam::KeyCode KEY_3 = 51;
		constexpr jam::KeyCode KEY_4 = 52;
		constexpr jam::KeyCode KEY_5 = 53;
		constexpr jam::KeyCode KEY_6 = 54;
		constexpr jam::KeyCode KEY_7 = 55;
		constexpr jam::KeyCode KEY_8 = 56;
		constexpr jam::KeyCode KEY_9 = 57;
		constexpr jam::KeyCode KEY_SEMICOLON = 59;  /* ; */
		constexpr jam::KeyCode KEY_EQUAL = 61;  /* = */
		constexpr jam::KeyCode KEY_A = 65;
		constexpr jam::KeyCode KEY_B = 66;
		constexpr jam::KeyCode KEY_C = 67;
		constexpr jam::KeyCode KEY_D = 68;
		constexpr jam::KeyCode KEY_E = 69;
		constexpr jam::KeyCode KEY_F = 70;
		constexpr jam::KeyCode KEY_G = 71;
		constexpr jam::KeyCode KEY_H = 72;
		constexpr jam::KeyCode KEY_I = 73;
		constexpr jam::KeyCode KEY_J = 74;
		constexpr jam::KeyCode KEY_K = 75;
		constexpr jam::KeyCode KEY_L = 76;
		constexpr jam::KeyCode KEY_M = 77;
		constexpr jam::KeyCode KEY_N = 78;
		constexpr jam::KeyCode KEY_O = 79;
		constexpr jam::KeyCode KEY_P = 80;
		constexpr jam::KeyCode KEY_Q = 81;
		constexpr jam::KeyCode KEY_R = 82;
		constexpr jam::KeyCode KEY_S = 83;
		constexpr jam::KeyCode KEY_T = 84;
		constexpr jam::KeyCode KEY_U = 85;
		constexpr jam::KeyCode KEY_V = 86;
		constexpr jam::KeyCode KEY_W = 87;
		constexpr jam::KeyCode KEY_X = 88;
		constexpr jam::KeyCode KEY_Y = 89;
		constexpr jam::KeyCode KEY_Z = 90;
		constexpr jam::KeyCode KEY_LEFT_BRACKET = 91;  /* [ */
		constexpr jam::KeyCode KEY_BACKSLASH = 92;  /* \ */
		constexpr jam::KeyCode KEY_RIGHT_BRACKET = 93;  /* ] */
		constexpr jam::KeyCode KEY_GRAVE_ACCENT = 96;  /* ` */
		constexpr jam::KeyCode KEY_WORLD_1 = 161; /* non-US #1 */
		constexpr jam::KeyCode KEY_WORLD_2 = 162; /* non-US #2 */
		constexpr jam::KeyCode KEY_ESCAPE = 256;
		constexpr jam::KeyCode KEY_ENTER = 257;
		constexpr jam::KeyCode KEY_TAB = 258;
		constexpr jam::KeyCode KEY_BACKSPACE = 259;
		constexpr jam::KeyCode KEY_INSERT = 260;
		constexpr jam::KeyCode KEY_DELETE = 261;
		constexpr jam::KeyCode KEY_RIGHT = 262;
		constexpr jam::KeyCode KEY_LEFT = 263;
		constexpr jam::KeyCode KEY_DOWN = 264;
		constexpr jam::KeyCode KEY_UP = 265;
		constexpr jam::KeyCode KEY_PAGE_UP = 266;
		constexpr jam::KeyCode KEY_PAGE_DOWN = 267;
		constexpr jam::KeyCode KEY_HOME = 268;
		constexpr jam::KeyCode KEY_END = 269;
		constexpr jam::KeyCode KEY_CAPS_LOCK = 280;
		constexpr jam::KeyCode KEY_SCROLL_LOCK = 281;
		constexpr jam::KeyCode KEY_NUM_LOCK = 282;
		constexpr jam::KeyCode KEY_PRINT_SCREEN = 283;
		constexpr jam::KeyCode KEY_PAUSE = 284;
		constexpr jam::KeyCode KEY_F1 = 290;
		constexpr jam::KeyCode KEY_F2 = 291;
		constexpr jam::KeyCode KEY_F3 = 292;
		constexpr jam::KeyCode KEY_F4 = 293;
		constexpr jam::KeyCode KEY_F5 = 294;
		constexpr jam::KeyCode KEY_F6 = 295;
		constexpr jam::KeyCode KEY_F7 = 296;
		constexpr jam::KeyCode KEY_F8 = 297;
		constexpr jam::KeyCode KEY_F9 = 298;
		constexpr jam::KeyCode KEY_F10 = 299;
		constexpr jam::KeyCode KEY_F11 = 300;
		constexpr jam::KeyCode KEY_F12 = 301;
		constexpr jam::KeyCode KEY_F13 = 302;
		constexpr jam::KeyCode KEY_F14 = 303;
		constexpr jam::KeyCode KEY_F15 = 304;
		constexpr jam::KeyCode KEY_F16 = 305;
		constexpr jam::KeyCode KEY_F17 = 306;
		constexpr jam::KeyCode KEY_F18 = 307;
		constexpr jam::KeyCode KEY_F19 = 308;
		constexpr jam::KeyCode KEY_F20 = 309;
		constexpr jam::KeyCode KEY_F21 = 310;
		constexpr jam::KeyCode KEY_F22 = 311;
		constexpr jam::KeyCode KEY_F23 = 312;
		constexpr jam::KeyCode KEY_F24 = 313;
		constexpr jam::KeyCode KEY_F25 = 314;
		constexpr jam::KeyCode KEY_KP_0 = 320;
		constexpr jam::KeyCode KEY_KP_1 = 321;
		constexpr jam::KeyCode KEY_KP_2 = 322;
		constexpr jam::KeyCode KEY_KP_3 = 323;
		constexpr jam::KeyCode KEY_KP_4 = 324;
		constexpr jam::KeyCode KEY_KP_5 = 325;
		constexpr jam::KeyCode KEY_KP_6 = 326;
		constexpr jam::KeyCode KEY_KP_7 = 327;
		constexpr jam::KeyCode KEY_KP_8 = 328;
		constexpr jam::KeyCode KEY_KP_9 = 329;
		constexpr jam::KeyCode KEY_KP_DECIMAL = 330;
		constexpr jam::KeyCode KEY_KP_DIVIDE = 331;
		constexpr jam::KeyCode KEY_KP_MULTIPLY = 332;
		constexpr jam::KeyCode KEY_KP_SUBTRACT = 333;
		constexpr jam::KeyCode KEY_KP_ADD = 334;
		constexpr jam::KeyCode KEY_KP_ENTER = 335;
		constexpr jam::KeyCode KEY_KP_EQUAL = 336;
		constexpr jam::KeyCode KEY_LEFT_SHIFT = 340;
		constexpr jam::KeyCode KEY_LEFT_CONTROL = 341;
		constexpr jam::KeyCode KEY_LEFT_ALT = 342;
		constexpr jam::KeyCode KEY_LEFT_SUPER = 343;
		constexpr jam::KeyCode KEY_RIGHT_SHIFT = 344;
		constexpr jam::KeyCode KEY_RIGHT_CONTROL = 345;
		constexpr jam::KeyCode KEY_RIGHT_ALT = 346;
		constexpr jam::KeyCode KEY_RIGHT_SUPER = 347;
		constexpr jam::KeyCode KEY_MENU = 348;
	}
}
