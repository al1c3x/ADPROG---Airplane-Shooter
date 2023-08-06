#include "TextRenderer.h"
#include "FontManager.h"


TextRenderer::TextRenderer(sf::Text* textDrawable, string fontName, sf::Color fillColor, sf::Color outlineColor, float outlineThickness, float size, string defaultText) : Renderer(name){
    sf::Font* font = FontManager::getInstance()->getFont(fontName);

    textDrawable->setFont(*font);
    textDrawable->setFillColor(fillColor);
    textDrawable->setOutlineColor(outlineColor);
    textDrawable->setOutlineThickness(outlineThickness);
    textDrawable->setCharacterSize(size);
    textDrawable->setString(defaultText);
    this->assignDrawable(textDrawable);
}

TextRenderer* TextRenderer::createText(sf::Text* textDrawable, string fontName, sf::Color fillColor, sf::Color outlineColor, float outlineThickness, float size, string defaultText)
{
    return new TextRenderer(textDrawable, fontName, fillColor, outlineColor, outlineThickness, size, defaultText);
}