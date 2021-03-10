#include <string>
using namespace std;

//#DEFINE constants 
constexpr int cutNumber = 10;
constexpr int maxNumberSize = 8;


namespace ariel { 
	string snowman(int inputNum);
	bool validInput (int inputNum);

	//declaration to private function 
	bool validInput (int inputNum);
	string hat (int x);
	string nose_mouth (int x);
	string eye_R_or_L (int x);
	string leftArm (int x);
	string rightArm (int x);
	string torso (int x);
	string base (int x);
	/////////////////////////
};