#ifndef DF_DISPLAYMANAGER_H
#define DF_DISPLAYMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Vector.h"
#include "Manager.h"
#include "Color.h"

#define DM df::DisplayManager::getInstance()

namespace df {

	// string justifications
	enum Justification {
		LEFT_JUSTIFIED,
		CENTER_JUSTIFIED,
		RIGHT_JUSTIFIED,
	};

	// defaults for SFML window
	const int WINDOW_HORIZONTAL_PIXELS_DEFAULT = 1024;
	const int WINDOW_VERTICAL_PIXELS_DEFAULT = 768;
	const int WINDOW_HORIZONTAL_CHARS_DEFAULT = 80;
	const int WINDOW_VERTICAL_CHARS_DEFAULT = 24;
	const int WINDOW_STYLE_DEFAULT = sf::Style::Titlebar | sf::Style::Close;
	const sf::Color WINDOW_BACKGROUND_COLOR_DEFAULT = sf::Color::Black;
	const std::string WINDOW_TITLE_DEFAULT = "Dragonfly";
	const std::string FONT_FILE_DEFAULT = "df-font.ttf";
	const float FONT_SCALE_DEFAULT = 1.0;

	// compute character height based on window size and font
	float charHeight(void);

	// Compute character width, based on window size and font.
	float charWidth(void);

	// Convert ASCII spaces (x,y) to window pixels (x,y).
	Vector spacesToPixels(Vector spaces);

	// Convert window pixels (x,y) to ASCII spaces (x,y).
	Vector pixelsToSpaces(Vector pixels);

	class DisplayManager : public Manager {

	private:

		DisplayManager();

		DisplayManager(DisplayManager const &);

		void operator=(DisplayManager const &);

		sf::Font font;
		sf::RenderWindow *p_window;
		int window_horizontal_pixels;
		int window_vertical_pixels;
		int window_horizontal_chars;
		int window_vertical_chars;
		sf::Color window_background_color;

	public:

		static DisplayManager &getInstance();

		// return 0 if ok, else −1
		int startUp() override;

		// close graphics window
		void shutDown() override;

		// draw a character at window location (x,y) with color
		// return 0 if ok, else −1
		int drawCh(Vector world_pos, char ch, Color color) const;

		// return 0 if ok, else −1
		int drawCh(Vector world_pos, char ch, unsigned char r, unsigned char g, unsigned char b) const;

		// return 0 if ok, else −13
		int swapBuffers();

		sf::RenderWindow *getWindow() const;

		int getHorizontalPixels() const;

		int getVerticalPixels() const;

		int getHorizontal() const;

		int getVertical() const;

		// draw string at window location (x,y) with color
		// justified left, center or right
		// return 0 if ok, else -1
		int drawString(Vector world_pos, std::string str, Justification just, Color color) const;

		// return true if ok, else false
		bool setBackgroundColor(Color color);
	};
}

#endif //DF_DISPLAYMANAGER_H
