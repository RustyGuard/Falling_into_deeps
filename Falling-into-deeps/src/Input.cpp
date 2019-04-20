#include "gearpch.h"
#include "Input.h"
#include "events/KeyEvent.h"
#include "events/MouseEvent.h"
#include "events/WindowEvent.h"

double x = 0.0, y = 0.0, wd_width = 0.0, wd_height = 0.0;
int keys[GLFW_KEY_LAST];
int buttons[GLFW_MOUSE_BUTTON_LAST];
std::unordered_map<std::string, int> registered;
void SetKey(const std::string& key, int k)
{
	registered[key] = k;
}

void Gear::InitKeys()
{
	SetKey("space", GLFW_KEY_SPACE);
	SetKey("apostrophe", GLFW_KEY_APOSTROPHE);
	SetKey("comma", GLFW_KEY_COMMA);
	SetKey("minus", GLFW_KEY_MINUS);
	SetKey("period", GLFW_KEY_PERIOD);
	SetKey("slash", GLFW_KEY_SLASH);
	SetKey("0", GLFW_KEY_0);
	SetKey("1", GLFW_KEY_1);
	SetKey("2", GLFW_KEY_2);
	SetKey("3", GLFW_KEY_3);
	SetKey("4", GLFW_KEY_4);
	SetKey("5", GLFW_KEY_5);
	SetKey("6", GLFW_KEY_6);
	SetKey("7", GLFW_KEY_7);
	SetKey("8", GLFW_KEY_8);
	SetKey("9", GLFW_KEY_9);
	SetKey("0", GLFW_KEY_SEMICOLON);
	SetKey("equal", GLFW_KEY_EQUAL);
	SetKey("a", GLFW_KEY_A);
	SetKey("b", GLFW_KEY_B);
	SetKey("c", GLFW_KEY_C);
	SetKey("d", GLFW_KEY_D);
	SetKey("e", GLFW_KEY_E);
	SetKey("f", GLFW_KEY_F);
	SetKey("g", GLFW_KEY_G);
	SetKey("h", GLFW_KEY_H);
	SetKey("i", GLFW_KEY_I);
	SetKey("j", GLFW_KEY_J);
	SetKey("k", GLFW_KEY_K);
	SetKey("l", GLFW_KEY_L);
	SetKey("m", GLFW_KEY_M);
	SetKey("n", GLFW_KEY_N);
	SetKey("o", GLFW_KEY_O);
	SetKey("p", GLFW_KEY_P);
	SetKey("q", GLFW_KEY_Q);
	SetKey("r", GLFW_KEY_R);
	SetKey("s", GLFW_KEY_S);
	SetKey("t", GLFW_KEY_T);
	SetKey("u", GLFW_KEY_U);
	SetKey("v", GLFW_KEY_V);
	SetKey("w", GLFW_KEY_W);
	SetKey("x", GLFW_KEY_X);
	SetKey("y", GLFW_KEY_Y);
	SetKey("z", GLFW_KEY_Z);
	SetKey("left_bracket", GLFW_KEY_LEFT_BRACKET);
	SetKey("backslash", GLFW_KEY_BACKSLASH);
	SetKey("rigth_bracket", GLFW_KEY_RIGHT_BRACKET);
	SetKey("grave_accent", GLFW_KEY_GRAVE_ACCENT);
	SetKey("world_1", GLFW_KEY_WORLD_1);
	SetKey("world_2", GLFW_KEY_WORLD_2);

	/* Function keys */
	SetKey("escape", GLFW_KEY_ESCAPE);
	SetKey("enter", GLFW_KEY_ENTER);
	SetKey("tab", GLFW_KEY_TAB);
	SetKey("backspace", GLFW_KEY_BACKSPACE);
	SetKey("insert", GLFW_KEY_INSERT);
	SetKey("delete", GLFW_KEY_DELETE);
	SetKey("right", GLFW_KEY_RIGHT);
	SetKey("left", GLFW_KEY_LEFT);
	SetKey("down", GLFW_KEY_DOWN);
	SetKey("up", GLFW_KEY_UP);
	SetKey("page_up", GLFW_KEY_PAGE_UP);
	SetKey("page_down", GLFW_KEY_PAGE_DOWN);
	SetKey("home", GLFW_KEY_HOME);
	SetKey("end", GLFW_KEY_END);
	SetKey("caps_lock", GLFW_KEY_CAPS_LOCK);
	SetKey("scroll_lock", GLFW_KEY_SCROLL_LOCK);
	SetKey("num_lock", GLFW_KEY_NUM_LOCK);
	SetKey("print_screen", GLFW_KEY_PRINT_SCREEN);
	SetKey("pause", GLFW_KEY_PAUSE);
	SetKey("f1", GLFW_KEY_F1);
	SetKey("f2", GLFW_KEY_F2);
	SetKey("f3", GLFW_KEY_F3);
	SetKey("f4", GLFW_KEY_F4);
	SetKey("f5", GLFW_KEY_F5);
	SetKey("f6", GLFW_KEY_F6);
	SetKey("f7", GLFW_KEY_F7);
	SetKey("f8", GLFW_KEY_F8);
	SetKey("f9", GLFW_KEY_F9);
	SetKey("f10", GLFW_KEY_F10);
	SetKey("f11", GLFW_KEY_F11);
	SetKey("f12", GLFW_KEY_F12);
	SetKey("f13", GLFW_KEY_F13);
	SetKey("f14", GLFW_KEY_F14);
	SetKey("f15", GLFW_KEY_F15);
	SetKey("f16", GLFW_KEY_F16);
	SetKey("f17", GLFW_KEY_F17);
	SetKey("f18", GLFW_KEY_F18);
	SetKey("f19", GLFW_KEY_F19);
	SetKey("f20", GLFW_KEY_F20);
	SetKey("f21", GLFW_KEY_F21);
	SetKey("f22", GLFW_KEY_F22);
	SetKey("f23", GLFW_KEY_F23);
	SetKey("f24", GLFW_KEY_F24);
	SetKey("f25", GLFW_KEY_F25);
	SetKey("kp0", GLFW_KEY_KP_0);
	SetKey("kp1", GLFW_KEY_KP_1);
	SetKey("kp2", GLFW_KEY_KP_2);
	SetKey("kp3", GLFW_KEY_KP_3);
	SetKey("kp4", GLFW_KEY_KP_4);
	SetKey("kp5", GLFW_KEY_KP_5);
	SetKey("kp6", GLFW_KEY_KP_6);
	SetKey("kp7", GLFW_KEY_KP_7);
	SetKey("kp8", GLFW_KEY_KP_8);
	SetKey("kp9", GLFW_KEY_KP_9);
	SetKey("kp_decimal", GLFW_KEY_KP_DECIMAL);
	SetKey("kp_divide", GLFW_KEY_KP_DIVIDE);
	SetKey("kp_multiply", GLFW_KEY_KP_MULTIPLY);
	SetKey("kp_substract", GLFW_KEY_KP_SUBTRACT);
	SetKey("kp_add", GLFW_KEY_KP_ADD);
	SetKey("kp_enter", GLFW_KEY_KP_ENTER);
	SetKey("kp_equal", GLFW_KEY_KP_EQUAL);
	SetKey("left_shift", GLFW_KEY_LEFT_SHIFT);
	SetKey("left_control", GLFW_KEY_LEFT_CONTROL);
	SetKey("left_alt", GLFW_KEY_LEFT_ALT);
	SetKey("left_super", GLFW_KEY_LEFT_SUPER);
	SetKey("right_shift", GLFW_KEY_RIGHT_SHIFT);
	SetKey("right_control", GLFW_KEY_RIGHT_CONTROL);
	SetKey("right_alt", GLFW_KEY_RIGHT_ALT);
	SetKey("right_super", GLFW_KEY_RIGHT_SUPER);
	SetKey("menu", GLFW_KEY_MENU);
}

void Gear::OnEvent(Event & event)
{
	switch (event.GetEventType())
	{
	case EventType::Key:
		keys[((KeyEvent&)event).GetKeyCode()] = ((KeyEvent&)event).GetAction();
		break;
	case EventType::MouseMoved:
		x = ((MouseMovedEvent&)event).GetX();
		y = ((MouseMovedEvent&)event).GetY();
		break;
	case EventType::MouseButton:
		buttons[((MouseButtonEvent&)event).GetMouseButton()] = ((MouseButtonEvent&)event).GetAction();
		break;
	case EventType::AppUpdate:
		for (int i = 0; i <= GLFW_MOUSE_BUTTON_LAST; i++)
		{
			if (buttons[i] == GLFW_PRESS) {
				buttons[i] = GLFW_REPEAT;
			}
		}
		break;
	case EventType::WindowResize:
		wd_width = ((WindowResizeEvent&)event).GetWidth();
		wd_height = ((WindowResizeEvent&)event).GetHeight();
		break;
	}
}

int Gear::isKeyPressed(int key)
{
	return keys[key];
}

int Gear::GetKey(const std::string & key)
{
	return isKeyPressed(registered[key]);
}

int Gear::GetMouseButton(int button)
{
	return buttons[button];
}

double Gear::getMouseX()
{
	return x - wd_width / 2;
}

double Gear::getMouseY()
{
	return y - wd_height / 2;
}
