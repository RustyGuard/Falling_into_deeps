#include "gearpch.h"
#include "Input.h"

bool keys[GLFW_KEY_LAST];
std::unordered_map<std::string, int> registered;
void SetKey(const std::string& key, int k)
{
	registered[key] = k;
}

void Gear::InitKeys()
{
	/*SetKey("", GLFW_KEY_SPACE
	SetKey("", GLFW_KEY_APOSTROPHE
	SetKey("", GLFW_KEY_COMMA
	SetKey("", GLFW_KEY_MINUS
	SetKey("", GLFW_KEY_PERIOD
	SetKey("", GLFW_KEY_SLASH
	SetKey("", GLFW_KEY_0                  48
	SetKey("", GLFW_KEY_1                  49
	SetKey("", GLFW_KEY_2                  50
	SetKey("", GLFW_KEY_3                  51
	SetKey("", GLFW_KEY_4                  52
	SetKey("", GLFW_KEY_5                  53
	SetKey("", GLFW_KEY_6                  54
	SetKey("", GLFW_KEY_7                  55
	SetKey("", GLFW_KEY_8                  56
	SetKey("", GLFW_KEY_9                  57
	SetKey("", GLFW_KEY_SEMICOLON          59 
	SetKey("", GLFW_KEY_EQUAL              61*/  
	SetKey("a", GLFW_KEY_A);
	//SetKey("", GLFW_KEY_B                  66
	//SetKey("", GLFW_KEY_C                  67
	SetKey("d", GLFW_KEY_D);
	/*SetKey("", GLFW_KEY_E                  69
	SetKey("", GLFW_KEY_F                  70
	SetKey("", GLFW_KEY_G                  71
	SetKey("", GLFW_KEY_H                  72
	SetKey("", GLFW_KEY_I                  73
	SetKey("", GLFW_KEY_J                  74
	SetKey("", GLFW_KEY_K                  75
	SetKey("", GLFW_KEY_L                  76
	SetKey("", GLFW_KEY_M                  77
	SetKey("", GLFW_KEY_N                  78
	SetKey("", GLFW_KEY_O                  79
	SetKey("", GLFW_KEY_P                  80
	SetKey("", GLFW_KEY_Q                  81
	SetKey("", GLFW_KEY_R                  82*/
	SetKey("s", GLFW_KEY_S);
	/*SetKey("", GLFW_KEY_T                  84
	SetKey("", GLFW_KEY_U                  85
	SetKey("", GLFW_KEY_V                  86*/
	SetKey("w", GLFW_KEY_W);
	/*SetKey("", GLFW_KEY_X                  88
	SetKey("", GLFW_KEY_Y                  89
	SetKey("", GLFW_KEY_Z                  90
	SetKey("", GLFW_KEY_LEFT_BRACKET
	SetKey("", GLFW_KEY_BACKSLASH
	SetKey("", GLFW_KEY_RIGHT_BRACKET
	SetKey("", GLFW_KEY_GRAVE_ACCENT
	SetKey("", GLFW_KEY_WORLD_1
	SetKey("", GLFW_KEY_WORLD_2

	/* Function keys */
	/*SetKey("", GLFW_KEY_ESCAPE             256
	SetKey("", GLFW_KEY_ENTER              257
	SetKey("", GLFW_KEY_TAB                258
	SetKey("", GLFW_KEY_BACKSPACE          259
	SetKey("", GLFW_KEY_INSERT             260
	SetKey("", GLFW_KEY_DELETE             261
	SetKey("", GLFW_KEY_RIGHT              262
	SetKey("", GLFW_KEY_LEFT               263
	SetKey("", GLFW_KEY_DOWN               264
	SetKey("", GLFW_KEY_UP                 265
	SetKey("", GLFW_KEY_PAGE_UP            266
	SetKey("", GLFW_KEY_PAGE_DOWN          267
	SetKey("", GLFW_KEY_HOME               268
	SetKey("", GLFW_KEY_END                269
	SetKey("", GLFW_KEY_CAPS_LOCK          280
	SetKey("", GLFW_KEY_SCROLL_LOCK        281
	SetKey("", GLFW_KEY_NUM_LOCK           282
	SetKey("", GLFW_KEY_PRINT_SCREEN       283
	SetKey("", GLFW_KEY_PAUSE              284
	SetKey("", GLFW_KEY_F1                 290
	SetKey("", GLFW_KEY_F2                 291
	SetKey("", GLFW_KEY_F3                 292
	SetKey("", GLFW_KEY_F4                 293
	SetKey("", GLFW_KEY_F5                 294
	SetKey("", GLFW_KEY_F6                 295
	SetKey("", GLFW_KEY_F7                 296
	SetKey("", GLFW_KEY_F8                 297
	SetKey("", GLFW_KEY_F9                 298
	SetKey("", GLFW_KEY_F10                299
	SetKey("", GLFW_KEY_F11                300
	SetKey("", GLFW_KEY_F12                301
	SetKey("", GLFW_KEY_F13                302
	SetKey("", GLFW_KEY_F14                303
	SetKey("", GLFW_KEY_F15                304
	SetKey("", GLFW_KEY_F16                305
	SetKey("", GLFW_KEY_F17                306
	SetKey("", GLFW_KEY_F18                307
	SetKey("", GLFW_KEY_F19                308
	SetKey("", GLFW_KEY_F20                309
	SetKey("", GLFW_KEY_F21                310
	SetKey("", GLFW_KEY_F22                311
	SetKey("", GLFW_KEY_F23                312
	SetKey("", GLFW_KEY_F24                313
	SetKey("", GLFW_KEY_F25                314
	SetKey("", GLFW_KEY_KP_0               320
	SetKey("", GLFW_KEY_KP_1               321
	SetKey("", GLFW_KEY_KP_2               322
	SetKey("", GLFW_KEY_KP_3               323
	SetKey("", GLFW_KEY_KP_4               324
	SetKey("", GLFW_KEY_KP_5               325
	SetKey("", GLFW_KEY_KP_6               326
	SetKey("", GLFW_KEY_KP_7               327
	SetKey("", GLFW_KEY_KP_8               328
	SetKey("", GLFW_KEY_KP_9               329
	SetKey("", GLFW_KEY_KP_DECIMAL         330
	SetKey("", GLFW_KEY_KP_DIVIDE          331
	SetKey("", GLFW_KEY_KP_MULTIPLY        332
	SetKey("", GLFW_KEY_KP_SUBTRACT        333
	SetKey("", GLFW_KEY_KP_ADD             334
	SetKey("", GLFW_KEY_KP_ENTER           335
	SetKey("", GLFW_KEY_KP_EQUAL           336
	SetKey("", GLFW_KEY_LEFT_SHIFT         340
	SetKey("", GLFW_KEY_LEFT_CONTROL       341
	SetKey("", GLFW_KEY_LEFT_ALT           342
	SetKey("", GLFW_KEY_LEFT_SUPER         343
	SetKey("", GLFW_KEY_RIGHT_SHIFT        344
	SetKey("", GLFW_KEY_RIGHT_CONTROL      345
	SetKey("", GLFW_KEY_RIGHT_ALT          346
	SetKey("", GLFW_KEY_RIGHT_SUPER        347
	SetKey("", GLFW_KEY_MENU               348*/

}

void Gear::keyPressed(int key)
{
	keys[key] = true;
}

void Gear::keyReleased(int key)
{
	keys[key] = false;
}

bool Gear::isKeyPressed(int key)
{
	return keys[key];
}

bool Gear::isPressed(const std::string & key)
{
	return isKeyPressed(registered[key]);
}
