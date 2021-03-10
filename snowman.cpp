/*
* AUTHORS: <Tzion Beniaminov>
* This code is about drawing a Snowman fon input 8 digits nmber
* in range of 11111111 to 44444444 
*
* STILL NOT FINSHED THE IMPLEMENTION 
*/

#include <iostream>
#include <string>
#include "snowman.hpp"


namespace ariel {
	string snowman(int inputNum) {
	
	int copy_inputNum = inputNum;//create a copy of the input to change the value of it
	if(!validInput(copy_inputNum)){
		throw out_of_range{"invalid input"};
	}
		/*
		string ans = "";
		
		string B = base(inputNum%10);
		inputNum/=10;
		string T = torso(inputNum%10);
		inputNum/=10;

		int r_Arm = inputNum%10;
		string Y = rightArm(inputNum%10);
		inputNum/=10;

		int l_Arm = inputNum%10;
		string X = leftArm(inputNum%10);
		inputNum/=10;

		string R = eye_R_or_L(inputNum%10);
		inputNum/=10;
		string L = eye_R_or_L(inputNum%10);
		inputNum/=10;
		string N = nose_mouth(inputNum%10);
		inputNum/=10;
		string H = hat(inputNum%10);

		if((l_Arm == 1 && r_Arm == 1)||(l_Arm== 1 && r_Arm==3)||(l_Arm== 1 && r_Arm==3)||(l_Arm == 1 && r_Arm == 4)
			||(l_Arm== 3 && r_Arm==1)||(l_Arm== 3 && r_Arm==3)||(l_Arm== 3 && r_Arm==4)||(l_Arm== 4 && r_Arm==1)
			||(l_Arm== 4 && r_Arm==3)||(l_Arm== 4 && r_Arm==4))
				ans = H+"("+L+N+R+")"+"\n"+X+"( "+T+" )"+Y+"\n"+" ( "+B+" )";
				
			if((l_Arm== 1 && r_Arm==2)||(l_Arm== 3 && r_Arm==2)||(l_Arm== 4 && r_Arm==2))
			ans = H+"("+L+N+R+")"+Y+"\n"+X+"( "+T+" )"+"\n"+" ( "+B+" )";
			
			if((l_Arm== 2 && r_Arm==1)||(l_Arm== 2 && r_Arm==2)||(l_Arm== 2 && r_Arm==3)||(l_Arm== 2 && r_Arm==4))
			ans = H+X+"("+L+N+R+")"+"\n"+"( "+T+" )"+Y+"\n"+" ( "+B+" )";
			
			if(l_Arm==3 && r_Arm==2)
			else
			ans = H+X+"("+L+N+R+")"+Y+"\n"+X+"( "+T+" )"+Y+"\n"+" ( "+B+" )";
			*/
		
		return "";
	}
	/**
	*gets the input number for the snowman and checks if
	*it's in the rigth range
	*/
	bool validInput (int inputNum){
		int copy_inputNum = inputNum;
		int lastDigit = 0;
    	int numSize = 0;

		while(copy_inputNum>0){
			numSize++;
			lastDigit = copy_inputNum%cutNumber;
			if(lastDigit>4 || lastDigit<1){return false;}
			copy_inputNum/=cutNumber;	
		}

		return !(numSize < maxNumberSize || inputNum < 0);
	}

	/**
	* returns the hat -H : in case 1: Straw Hat : _===_
 	*                     in case 2: Mexican Hat:   ___
    *                                              ..... 
 	* 				      in case 3: Fez:  _  
 	*						              /_\ 
 	*                     in case 4: Russian Hat:  ___ 
	*				   						      (_*_)
 	*/
	string hat (int x){
		switch(x){
			case 1 : return "_===_\n";
			case 2 : return "___\n.....\n";
			case 3 : return " _ \n/_\\\n";
			case 4 : return "___\n(_*_)\n";
			default : return "";
		}
	}

	/**
	* returns the nose/mouth -N : in case 1: Normal : ,
 	*                             in case 2: Dot : .
 	* 				              in case 3: Line : _
 	*                             in case 4: None : 
	*/
	string nose_mouth (int x){
		switch(x){
			case 1 : return ",";
			case 2 : return ".";
			case 3 : return "_";
			//case 4
			default : return "";
		}
	}

	/**
	* returns the eye R and L : in case 1: Dot : .
 	*                           in case 2: Bigger Dot : o
 	* 				            in case 3: Biggest Dot : O
 	*                           in case 4: Closed : -
	*/
	string eye_R_or_L (int x){
		switch(x){
			case 1 : return ".";
			case 2 : return "o";
			case 3 : return "O";
			case 4 : return "-";
			default : return "";
		}
	}

	/**
	* returns the leftArm -X in case 1: Normal Arm : <
 	*                        in case 2: Upwards Arm : \
 	* 				         in case 3: Downwards Arm : /
 	*                        in case 4: None : 
	*/
	string leftArm (int x){
		switch(x){
			case 1 : return "<";
			case 2 : return "\\";
			case 3 : return "/";
			//case 4
			default : return "";
		}
	}

	/**
	* returns the rightArm -Y in case 1: Normal Arm : >
 	*                         in case 2: Upwards Arm : /
 	* 				          in case 3: Downwards Arm : \
 	*                         in case 4: None : 
	*/
	string rightArm (int x){
		switch(x){
			case 1 : return ">";
			case 2 : return "/";
			case 3 : return "\\";
			//case 4
			default : return "";
		}
	}

	/**
	* returns the torso -T   in case 1: Buttons : :
 	*                        in case 2: Vest : ] [
 	* 				         in case 3: Inward Arms : > <
 	*                        in case 4: None : 
	*/
	string torso (int x){
		switch(x){
			case 1 : return ":";
			case 2 : return "] [";
			case 3 : return "> <";
			//case 4
			default : return "";
		}
	}

	/**
	* returns the base -B   in case 1: Buttons : :
 	*                       in case 2: Upwards Arm : " "
 	* 				        in case 3: Downwards Arm : ___
 	*                       in case 4: None : 
	*/
	string base (int x){
		switch(x){
			case 1 : return ":";
			case 2 : return """";
			case 3 : return "___";
			//case 4
			default : return "";
		}
	}
}