#include"Animal.h"
#include "Parrot.h"
#include "Dog.h"
#include "Cat.h"
#include "Pinguin.h"
#include "Dolphin.h"


using namespace std;

int main()
{
	//Animal* ptr = new Parrot("Ara",2,"Africa");
	//ptr->Eat();
	//ptr->Move();
	//ptr->Print();
	//delete ptr;

	IAnimal* ptr = nullptr;

	ptr = new Parrot("Ara", 1, "Africa");
	// ptr - интерфейсная ссылка
	ptr->Eat();
	ptr->Move();
	Parrot* parrot = static_cast<Parrot*>(ptr);
	parrot->Print();
	parrot->Fly();
	delete ptr;
	cout << endl;

	ptr = new Cat("Vasya", 5, "Europe");
	// ptr - интерфейсная ссылка
	ptr->Eat();
	ptr->Move();
	Cat* cat = static_cast<Cat*>(ptr);
	cat->Print();
	delete ptr;
	cout << endl;


	ptr = new Dog("Bob", 2, "Asia");
	// ptr - интерфейсная ссылка
	ptr->Eat();
	ptr->Move();
	Dog* dog = static_cast<Dog*>(ptr);
	dog->Print();
	delete ptr;
	cout << endl;


	ptr = new Pinguin("Gaba", 2, "Antarctica");
	// ptr - интерфейсная ссылка
	ptr->Eat();
	ptr->Move();
	Pinguin* pinguin = static_cast<Pinguin*>(ptr);
	pinguin->Print();
	pinguin->Swim();
	cout << endl;


	ptr = new Dolphin("Ara", 2, "Africa");
	// ptr - интерфейсная ссылка
	ptr->Eat();
	ptr->Move();
	Dolphin* dolphin = static_cast<Dolphin*>(ptr);
	dolphin->Print();
	dolphin->Swim();
	cout << endl;

	//delete ptr;
		
}

/*
Parrot Eat
Parrot Move
Name: Ara
KG: 1
Continent: Africa
Parrot Fly

Cat Eat
Cat Move
Name: Vasya
KG: 5
Continent: Europe

Dog Eat
Dog Move
Name: Bob
KG: 2
Continent: Asia

Pinguin Eat
Pinguin Move
Name: Gaba
KG: 2
Continent: Antarctica
Pinguin Swim

Dolphin Eat
Dolphin Move
Name: Ara
KG: 2
Continent: Africa
Dolphin Swim
*/