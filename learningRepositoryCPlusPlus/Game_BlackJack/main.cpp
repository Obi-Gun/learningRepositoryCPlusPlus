#include "Menu.h"
#include "Deck.h"

Menu* Menu::_ptr = new Menu;
Deck* Deck::_ptr = new Deck;
Diller* Diller::_ptr = new Diller;

int main()
{
    Menu* menu = Menu::getReferance();
    Deck* deck = Deck::getReferance();
    Diller* diller = Diller::getReferance();
    menu->start();
    menu->~Menu();
}

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
