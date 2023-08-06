#include "HUDScreen.h"
#include "TextureManager.h"
#include "Game.h"
#include "UIButton.h"
#include "UIText.h"
#include "QuitScreen.h"
#include "GameObjectManager.h"
#include "Renderer.h"

HUDScreen::HUDScreen(string name) : AGameObject(name), ButtonListener()
{

}

HUDScreen::~HUDScreen()
{
	AGameObject::~AGameObject();
}

void HUDScreen::initialize()
{
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*TextureManager::getInstance()->getTexture("hud_bg"));
	sf::Vector2u textureSize = this->sprite->getTexture()->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
	this->setPosition(Game::WINDOW_WIDTH - 240, Game::WINDOW_HEIGHT - 50);

	Renderer* renderer = new Renderer("HUDScreen");
	renderer->assignDrawable(sprite);
	this->attachComponent(renderer);

	sf::Texture* btnNormal = TextureManager::getInstance()->getTexture("btn_normal");
	sf::Texture* btnPressed = TextureManager::getInstance()->getTexture("btn_pressed");
	UIButton* quitBtn = new UIButton("quitBtn", btnNormal, btnPressed);
	this->attachChild(quitBtn);
	quitBtn->setPosition(170, 0);
	quitBtn->getTransformable()->setScale(0.15f, 0.15f);
	quitBtn->setButtonListener(this);

	UIText* button_1Text = new UIText("text_1");
	//do not make as a button child. difficult to position
	quitBtn->attachChild(button_1Text);
	button_1Text->setPosition(0, -50);
	button_1Text->setSize(150);
	button_1Text->setText("QUIT");

	/*UIText* button_2Text = new UIText("text_2");
	//do not make as a button child. difficult to position
	button_2Text->setPosition(0, -0);
	button_2Text->setSize(150);
	button_2Text->setText("Score:");*/

}

void HUDScreen::onButtonClick(UIButton* button)
{
}

void HUDScreen::onButtonReleased(UIButton* button)
{
	if (button->getName() == "quitBtn") {
		QuitScreen* quitScreen = new QuitScreen("quitScreen");
		quitScreen->markGameQuit();
		GameObjectManager::getInstance()->addObject(quitScreen);
	}
}