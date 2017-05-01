#ifndef __MENUBUTTON__
#define __MENUBUTTON__

#include <SDLGameObject.hpp>


class MenuButton : public SDLGameObject{
	public:
		MenuButton();
		virtual void draw();
		virtual void update();
		virtual void clean();
		virtual void load(const LoaderParams* pParams);
		void setCallback(void(*callback)()) { m_callback = callback;}
		int getCallbackID() { return m_callbackID; }

	private:
		enum button_state{
			MOUSE_OUT = 0,
			MOUSE_OVER = 1,
			CLICKED = 2
		};
		int m_callbackID;
		void (*m_callback)();
		bool m_bReleased;

};

#endif