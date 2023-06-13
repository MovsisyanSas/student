#include <iostream>

class student {
	int age;
	int level; // 0-4
	int mathGrade; //all grades by 10 point system
	int englishGrade;
	int absentes;
	bool goodProgress;
	bool goodBehaviour;

	int check() {
		int points = 5;
		if (age <= 18)
		{
			std::cout << "You must be older than 18 y.o." << std::endl;
			return -1;
		}
		if (mathGrade < 4)
		{
			points--;
		}
		if (englishGrade < 4)
		{
			points--;
		}
		if (absentes > 120)
		{
			points--;
		}
		if (!goodProgress) {
			points--;
		}
		if (!goodBehaviour) {
			points--;
		}
		return points;
	}
	void opinion(int a) {
		if (a == -1)
		{
			abort;
		}
		else {
			if (3 < a <= 5)
			{
				std::cout << "You are good student" << std::endl;
			}
			else if (2 <= a <= 3) {
				std::cout << "You must study better" << std::endl;
			}
			else {
				std::cout << "You are a bad student" << std::endl;
			}
		}
	}

public:
	void display() {
		std::cout << "age: " << age << std::endl;
		std::cout << "level: " << level << std::endl;
		std::cout << "mathGrade: " << mathGrade << std::endl;
		std::cout << "englishGrade: " << englishGrade << std::endl;
		std::cout << "absentes: " << absentes << std::endl;
		std::cout << "goodProgress: " << goodProgress << std::endl;
		std::cout << "goodBehaviour: " << goodBehaviour << std::endl;
	}

	student() {
		std::cerr << "Error! Fill all stats" << std::endl;
	}
	student(int age, int level, int mathGrade, int englishGrade, int absentes, bool goodProgress, bool goodBehaviour) {
		if (age >= 0 && 0 <= level <= 4 && 0 <= mathGrade <= 10 && 0 <= englishGrade <= 10 && absentes >= 0)
		{
			this->age = age;
			this->level = level;
			this->mathGrade = mathGrade;
			this->englishGrade = englishGrade;
			this->absentes = absentes;
			this->goodProgress = goodProgress;
			this->goodBehaviour = goodBehaviour;
			opinion(check());
		}
	}
	student(const student& obj) {
		this->age = obj.age;
		this->level = obj.level;
		this->mathGrade = obj.mathGrade;
		this->englishGrade = obj.englishGrade;
		this->absentes = obj.absentes;
		this->goodProgress = obj.goodProgress;
		this->goodBehaviour = obj.goodBehaviour;
	}
	student& operator = (const student& obj) {
		if (this != &obj)
		{
			this->age = obj.age;
			this->level = obj.level;
			this->mathGrade = obj.mathGrade;
			this->englishGrade = obj.englishGrade;
			this->absentes = obj.absentes;
			this->goodProgress = obj.goodProgress;
			this->goodBehaviour = obj.goodBehaviour;
		}
		return *this;
	}
};

int main() {
	int age, level, mathGrade, englishGrade, absentes;
	bool goodProgress, goodBehaviour;
	std::cout << "Your age: ";
	std::cin >> age;
	std::cout << "Your level (0-4): ";
	std::cin >> level;
	std::cout << "Your grade of math (0-10): ";
	std::cin >> mathGrade;
	std::cout << "Your grade of english (0-10): ";
	std::cin >> englishGrade;
	std::cout << "Your absentes: ";
	std::cin >> absentes;
	std::cout << "Do you have good progress (enter 0 if 'No' and any other Number if 'Yes'): ";
	std::cin >> goodProgress;
	std::cout << "Do you have good behaviour (enter 0 if 'No' and any other Number if 'Yes'): ";
	std::cin >> goodBehaviour;

	student form(age, level, mathGrade, englishGrade, absentes, goodProgress, goodBehaviour);

	student form1(form);

	form1.display();
	student form2 = form;
	form2.display();
}