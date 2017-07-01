#pragma once

#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/OpenGL/GL3Renderer.h>
#include <glm/glm.hpp>
#include <SDL/SDL_events.h>

class GUI
{
private:
	static CEGUI::OpenGL3Renderer* _renderer;
	CEGUI::GUIContext* _context = nullptr;
	CEGUI::Window* _root = nullptr;
	CEGUI::Key::Scan GUI::SDLKeyToCEGUIKey(SDL_Keycode key);
	CEGUI::MouseButton SDLButtonToCEGUIButton(Uint8 sdlButton);
	unsigned int _lasTime = 0;
public:
	void init(const std::string& resourceDirectory);
	void destroy();
	void draw();
	void onSDLEvent(SDL_Event& evnt);
	void update();
	void showMouseCursor();
	void hideMouseCursor();
	void setMouseCursor(const std::string& imageFile);
	void loadScheme(const std::string& schemeFile);
	void setFont(const std::string& fontFile);
	CEGUI::Window* createWidget(const std::string& scheme, const glm::vec4& desctRect, const glm::vec4& desctPix, const std::string& name = "");
	static void setWidgetDestrect(CEGUI::Window* newWindow, const glm::vec4& desctRect, const glm::vec4& desctPix);
	static CEGUI::OpenGL3Renderer* getRenderer() { return _renderer; };
	CEGUI::GUIContext* getContenxt() { return _context; };
};

