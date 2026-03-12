#include "skin.h"

skin::skin(string cName, string sName, int p) {
    characterName = cName;
    skinName = sName;
    price = p;
    isSold = false;
}

string skin::getCharacterName() { return characterName; }
string skin::getSkinName() { return skinName; }
int skin::getPrice() { return price; }
bool skin::getIsSold() { return isSold; }

void skin::setCharacterName(string cName) { characterName = cName; }
void skin::setSkinName(string sName) { skinName = sName; }
void skin::setPrice(int p) { price = p; }
void skin::setIsSold(bool sold) { isSold = sold; }
