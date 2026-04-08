#include <iostream>

bool Weight() {
	std::cout << "Do you prefer KG or LBS? (0 or 1)\n";
	bool pref_weight = 0;
	std::cin >> pref_weight;
	return pref_weight;
}
bool Height() {
	std::cout << "Do you prefer height in CM or FT? (0 or 1)\n";
	bool pref_height = 0;
	std::cin >> pref_height;
	return pref_height;
}
char Gender () {
	char Gender = 0;
	while (Gender != 'f' || Gender != 'm') {
		std::cout << "Are you a MALE or FEMALE? (m or f)\n";
		std::cin >> Gender;
		switch (Gender) {
			case 'm':
				std::cout << "You are a male.\n";
				return Gender;
			case 'f':
				std::cout << "You are a female.\n";
				return Gender;
			default:
				std::cout << "Not a valid option.";
		}
	}
	return 0;
}
int Age() {
	std::cout << "How old are you?: ";
	int age = 0;
	std::cin >> age;
	return age;
}
float BasalMetabolicRate(bool Weight,bool Height,char Gender,int Age) {  // Where all the calculations are made for BMR.
	std::cout << "==SETTINGS==\n	AGE: " << Age;
	if (Gender == 'm') {
		std::cout << "\n	GENDER: MALE ";
	}
	else {
		std::cout << "\n	GENDER: FEMALE ";
	}
	if (Height == 0) {
		std::cout << "	HEIGHT: CM\n";
	}
	else {	
		std::cout << "	HEIGHT: FT\n";
	}
	if (Weight == 0) {
		std::cout << "	WEIGHT: KG\n";
	}
	else {
		std::cout << "	WEIGHT: LBS\n";
	}
	float user_weight = 0;
	float user_height =0;
	const float kilo = 0.454;
	const float centi = 30.48;
	const float inchcm = 2.54;
	int daily_intake = 0;
	float daily_miles = 0;
	int user_foot =0;
	float user_finch =0;
	float bmr = 0;
	if (Height == 1) {
		std::cout << "Enter your foot height: "; std::cin >> user_foot;
		std::cout << "Enter your inch height: "; std::cin >> user_finch;
		user_height = (centi*user_foot) + (inchcm*user_finch);
	}
	else {
		std::cout << "Enter your height: "; std::cin >> user_height;
	}
	std::cout << "Enter your weight: "; std::cin >> user_weight;
	std::cout << "How many calories do you eat?: "; std::cin >> daily_intake;
	std::cout << "How many miles do you walk?: "; std::cin >> daily_miles;
	std::cout << "--Body Statistics--\n";		// The statistics are split from the rest after the calculations so the height and weight actually show the entered values, not the converted.
	std::cout << "	WEIGHT: " << user_weight << "\n	HEIGHT: " << user_height;
	if (Weight == 1) {
		user_weight = user_weight * kilo;
	}
	if (Gender = 'm') {
		bmr = (10 * user_weight) + (6.25 * user_height) - (5 * Age) + 5;
	}
	else {
		bmr = (10 * user_weight) + (6.25 * user_height) - (5 * Age) - 161;
	}
	float bmi = user_weight / ((user_height / 100)*(user_height / 100));
	std::cout << "\n	Body Mass Index (BMI): " << bmi << "\n";
	std::cout << "\n	Daily Passive Burn: " << bmr;
	std::cout << "\n	Passive Burn w/ Intake: " << bmr - daily_intake;
	std::cout << "\n	Active Burn: " << bmr + (0.75 * user_weight * daily_miles);
	std::cout << "\n	Active Burn w/ Intake: " << bmr + (0.75 * user_weight * daily_miles) - daily_intake;
	if (Weight == 0) {
		std::cout << "\n	Kilograms Lost Weekly: " << ((bmr*7)/7700);
	}
	else {
		std::cout << "\n	Pounds Lost Weekly: " << (((bmr + (daily_miles * 0.75 * user_weight) - daily_intake)*7)/3500);
	}
	return 0;
}
int main() {
	BasalMetabolicRate(Weight(),Height(),Gender(),Age());
	std::cout << "\n-\n-\n-\nProgram created by Dawi.\n-\n-\n-";
}
