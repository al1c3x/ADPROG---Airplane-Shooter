#pragma once
#include "AGameObject.h"
#include "UIButtonInputController.h"

class HUDScreen : public AGameObject, public ButtonListener
{
public:
	HUDScreen(string name);
	~HUDScreen();

	void initialize();
	void onButtonClick(UIButton* button);
	void onButtonReleased(UIButton* button);
private:
	sf::Sprite* sprite;
};

