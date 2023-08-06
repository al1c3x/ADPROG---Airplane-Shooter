#pragma once
#include "Renderer.h"
class TextRenderer : public Renderer
{
public:
	TextRenderer(sf::Text* textDrawable, string fontName, sf::Color fillColor, sf::Color outlineColor, float outlineThickness, float size, string defaultText);
	static TextRenderer* createText(sf::Text* textDrawable, string fontName, sf::Color fillColor, sf::Color outlineColor, float outlineThickness, float size, string defaultText);
};

