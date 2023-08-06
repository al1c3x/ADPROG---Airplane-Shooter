#include <stddef.h>
#include <iostream>
#include "TextureManager.h"

TextureManager* TextureManager::sharedInstance = NULL;

TextureManager* TextureManager::getInstance() {
	//initialize only when we need it
	if (sharedInstance == NULL) {
		sharedInstance = new TextureManager();
	}
	return sharedInstance;
}

void TextureManager::loadAll() {

	loadTexture("desert_bg", "Desert.png");
	sf::Texture* bgTex;
	bgTex = getTexture("desert_bg");
	bgTex->setRepeated(true);

	loadTexture("eagle", "Eagle.png");
	loadTexture("raptor", "Raptor.png");
	loadTexture("ui_bg", "f.png");
	loadTexture("btn_normal", "b_4.png");
	loadTexture("btn_pressed", "b_5.png");
	loadTexture("hud_bg", "bar_1.png");
	loadTexture("avenger", "Avenger.png");
	loadTexture("title_bg", "Tbg.png");
	loadTexture("Projectile", "Bullet.png");
}

void TextureManager::loadTexture(std::string key, std::string path) {
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(path);
	textureMap[key] = texture;
}

sf::Texture* TextureManager::getTexture(std::string key) {
	if (textureMap[key] != NULL) {
		return textureMap[key];
	}
	else {
		std::cout << "No texture found for " << key;
		return NULL;
	}
}

void TextureManager::testFunction() {
	std::cout << "Hi, I'm single-ton ;D";
}