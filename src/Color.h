#ifndef DF_COLOR_H
#define DF_COLOR_H

namespace df {

	enum Color {
		UNDEFINED_COLOR = -1,
		BLACK = 0,
		RED,
		GREEN,
		YELLOW,
		BLUE,
		MAGENTA,
		CYAN,
		WHITE,
		CUSTOM,
	};

	// if color not specified, use default
	const Color COLOR_DEFAULT = WHITE;
}

#endif //DF_COLOR_H
