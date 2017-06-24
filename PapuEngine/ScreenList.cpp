#include "ScreenList.h"
#include "IGameScreen.h"


ScreenList::ScreenList(Game* game):_game(game)
{
}

ScreenList::~ScreenList()
{
	destroy();
}

IGameScreen* ScreenList::getCurrent() {
	if (_currentIndex == -1) {
		return nullptr;
	}
	return _screens[_currentIndex];
}

IGameScreen* ScreenList::moveNext() {
	IGameScreen* currentScreen = getCurrent();
	if (currentScreen->getNextScreen() != -1) {
		_currentIndex = 
			currentScreen->getNextScreen();
	}
	return getCurrent();
}

IGameScreen* ScreenList::movePrevious() {
	IGameScreen* currentScreen = getCurrent();
	if (currentScreen->getPreviousScreen() != -1) {
		_currentIndex =
			currentScreen->getPreviousScreen();
	}
	return getCurrent();
}
