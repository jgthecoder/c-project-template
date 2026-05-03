#include <assert.h>

// STB SINGLE HEADER FILE APPROACH, coined by SEAN BARRETT

#ifndef LIB_H
#define LIB_H

// Place all API declarations below

typedef struct {
	float x;
	float y;
} vec2;

vec2 create_vec2(float x, float y);

#endif // LIB_H

#ifdef LIB_IMPLEMENTATION

// Place all API definitions/implementations below

vec2 create_vec2(float x, float y)
{
	vec2 v = { x, y };
	return v;
}


#endif // LIB_IMPLEMENTATION
