#include "DisplayManager.h"
#include "LogManager.h"
#include "utility.h"

df::DisplayManager::DisplayManager() {
	p_window = nullptr;
	window_horizontal_pixels = WINDOW_HORIZONTAL_PIXELS_DEFAULT;
	window_vertical_pixels = WINDOW_VERTICAL_PIXELS_DEFAULT;
	window_horizontal_chars = WINDOW_HORIZONTAL_CHARS_DEFAULT;
	window_vertical_chars = WINDOW_VERTICAL_CHARS_DEFAULT;
	window_background_color = WINDOW_BACKGROUND_COLOR_DEFAULT;
	setType("DisplayManager");
}

df::DisplayManager &df::DisplayManager::getInstance() {
	static DisplayManager instance;
	return instance;
}

int df::DisplayManager::startUp() {
	if (p_window != nullptr)
		return Manager::startUp();

	// create SFML window
	p_window = new sf::RenderWindow(sf::VideoMode(window_horizontal_pixels, window_vertical_pixels),
	                                WINDOW_TITLE_DEFAULT, WINDOW_STYLE_DEFAULT);

	// hide mouse cursor by default
	p_window->setMouseCursorVisible(false);

	// Vsync on by default
	p_window->setVerticalSyncEnabled(true);

	// load font
	if (!font.loadFromFile(FONT_FILE_DEFAULT)) {
		LM.writeLog(5, "DisplayManager::startUp(): Error loading font file '%s'", FONT_FILE_DEFAULT.c_str());
		return -1;
	}

	LM.writeLog(1, "DisplayManager::startUp(): DisplayManager started successfully");
	return Manager::startUp();
}

void df::DisplayManager::shutDown() {
	p_window->close();
	delete p_window;
	Manager::shutDown();
}

int df::DisplayManager::drawCh(df::Vector world_pos, char ch, Color color) const {
	if (p_window == nullptr)
		return -1;

	// convert world position to pixel position
	Vector pixel_pos = spacesToPixels(worldToView(world_pos));

	// draw rectangle at pixel_pos with color
	static sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(charWidth(), charHeight()));
	rectangle.setFillColor(WINDOW_BACKGROUND_COLOR_DEFAULT);
	rectangle.setPosition(pixel_pos.getX() - charWidth() / 10, pixel_pos.getY() + charHeight() / 5);
	p_window->draw(rectangle);

	static sf::Text text("", font);
	text.setString(ch);
	text.setStyle(sf::Text::Bold);

	switch (color) {
		case BLACK:
			text.setFillColor(sf::Color::Black);
			break;
		case RED:
			text.setFillColor(sf::Color::Red);
			break;
		case GREEN:
			text.setFillColor(sf::Color::Green);
			break;
		case YELLOW:
			text.setFillColor(sf::Color::Yellow);
			break;
		case BLUE:
			text.setFillColor(sf::Color::Blue);
			break;
		case MAGENTA:
			text.setFillColor(sf::Color::Magenta);
			break;
		case CYAN:
			text.setFillColor(sf::Color::Cyan);
			break;
		case WHITE:
		default:
			text.setFillColor(sf::Color::White);
			break;
	}

	if (charWidth() < charHeight())
		text.setCharacterSize(charHeight() * FONT_SCALE_DEFAULT);
	else
		text.setCharacterSize(charWidth() * FONT_SCALE_DEFAULT);

	text.setPosition(pixel_pos.getX(), pixel_pos.getY());

	p_window->draw(text);
	return 0;
}

int df::DisplayManager::drawCh(df::Vector world_pos, char ch, unsigned char r, unsigned char g, unsigned char b) const {
	if (p_window == nullptr)
		return -1;

	// convert world position to pixel position
	Vector pixel_pos = spacesToPixels(worldToView(world_pos));

	// draw rectangle at pixel_pos with color
	static sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(charWidth(), charHeight()));
	rectangle.setFillColor(WINDOW_BACKGROUND_COLOR_DEFAULT);
	rectangle.setPosition(pixel_pos.getX() - charWidth() / 10, pixel_pos.getY() + charHeight() / 5);
	p_window->draw(rectangle);

	static sf::Text text("", font);
	text.setString(ch);
	text.setStyle(sf::Text::Bold);

	text.setFillColor(sf::Color(r, g, b));

	if (charWidth() < charHeight())
		text.setCharacterSize(charHeight() * FONT_SCALE_DEFAULT);
	else
		text.setCharacterSize(charWidth() * FONT_SCALE_DEFAULT);

	text.setPosition(pixel_pos.getX(), pixel_pos.getY());

	p_window->draw(text);
	return 0;
}

int df::DisplayManager::swapBuffers() {
	if (p_window == nullptr)
		return -1;

	p_window->display();
	p_window->clear(window_background_color);

	return 0;
}

sf::RenderWindow *df::DisplayManager::getWindow() const {
	return p_window;
}

int df::DisplayManager::getHorizontalPixels() const {
	return window_horizontal_pixels;
}

int df::DisplayManager::getVerticalPixels() const {
	return window_vertical_pixels;
}

int df::DisplayManager::getHorizontal() const {
	return window_horizontal_chars;
}

int df::DisplayManager::getVertical() const {
	return window_vertical_chars;
}

int
df::DisplayManager::drawString(df::Vector world_pos, std::string str, df::Justification just, df::Color color) const {
	Vector startingPos = world_pos;

	switch (just) {
		case df::LEFT_JUSTIFIED:
			break;
		case df::CENTER_JUSTIFIED:
			startingPos.setX(world_pos.getX() - str.size() / 2);
			break;
		case df::RIGHT_JUSTIFIED:
			startingPos.setX(world_pos.getX() - str.size());
			break;
		default:
			LM.writeLog(5, "DisplayManager::drawString(): Invalid justification");
			return -1;
	}

	for (unsigned int i = 0; i < str.size(); i++)
		drawCh(Vector(startingPos.getX() + i, startingPos.getY()), str[i], color);

	return 0;
}

bool df::DisplayManager::setBackgroundColor(Color color) {
	switch (color) {
		case BLACK:
			window_background_color = sf::Color::Black;
			break;
		case RED:
			window_background_color = sf::Color::Red;
			break;
		case GREEN:
			window_background_color = sf::Color::Green;
			break;
		case YELLOW:
			window_background_color = sf::Color::Yellow;
			break;
		case BLUE:
			window_background_color = sf::Color::Blue;
			break;
		case MAGENTA:
			window_background_color = sf::Color::Magenta;
			break;
		case CYAN:
			window_background_color = sf::Color::Cyan;
			break;
		case WHITE:
			window_background_color = sf::Color::White;
			break;
		default:
			LM.writeLog(4, "DisplayManager::setBackgroundColor(): Invalid color");
			return false;
	}

	return true;
}

float df::charHeight() {
	return DM.getVerticalPixels() / DM.getVertical();
}

float df::charWidth() {
	return DM.getHorizontalPixels() / DM.getHorizontal();
}

df::Vector df::spacesToPixels(Vector spaces) {
	return {spaces.getX() * charWidth(), spaces.getY() * charHeight()};
}

df::Vector df::pixelsToSpaces(Vector pixels) {
	return {pixels.getX() / charWidth(), pixels.getY() / charHeight()};
}
