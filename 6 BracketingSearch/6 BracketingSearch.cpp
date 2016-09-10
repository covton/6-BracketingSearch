// 6 BracketingSearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string> // so we can use strings
#include <algorithm> // so we can use max()

int main()
{
   
	std::string iChoice;
	// either guess the computer's number, or computer guesses yours
	do {
		std::cout << "Would you like me to guess your number (input 1), or you to guess my number (input 2)?\n";
		std::getline(std::cin,iChoice);
			if (iChoice == "1" || iChoice == "2") {
				break;
		}
			std::cout << "Please enter 1 or 2.\n";
	} while (iChoice != "1" || iChoice != "2");

	if (iChoice == "2") {
		int iRand;
		iRand = rand() % 100 + 1;

		std::cout << "I've thought of a number between 1 and 100. Guess what it could be.\n";
		int iGuess;
		do {
			std::cin >> iGuess;

			if (iGuess == iRand) {
				std::cout << "Congratulations! You are right, I was thinking of " << iGuess << ".\n";
				break;
			}
			else if (iGuess < iRand) {

				std::cout << "That's too low. Try again. \n";
			}
			else {
				std::cout << "That's too high. Try again. \n";
			}

		} while (iGuess != iRand);
	}

	if (iChoice == "1"){

		std::cout << "Think of a number between 1 and 100...\n";
		int iCompGuess = rand() % 100 + 1;
		int iHighCompGuess = std::max(iCompGuess, 101); //record the computer's highest guess
		int iLowCompGuess = std::min(iCompGuess, 0);//record the computer's lowest guess
		int iCompTries = 1; //record how many times the computer has tried

		std::string strUserFeedback;

		do {
			// computer chooses a random number to guess at the start

			std::cout << "Is your number " << iCompGuess << ", or is your number higher or lower?\n";

			//loop until the user picks yes, higher or lower
			do {
				std::getline(std::cin, strUserFeedback);
				if (strUserFeedback != "Yes" && strUserFeedback != "Lower" && strUserFeedback != "Higher") {
					std::cout << "Please enter 'Yes', 'Higher' or 'Lower'\n";
				}
			} while (strUserFeedback != "Yes" && strUserFeedback != "Lower" && strUserFeedback != "Higher");

			if (strUserFeedback != "Yes") {

				if (strUserFeedback=="Lower" && iCompGuess <= iLowCompGuess + 1) {
					std::cout << "That can't be right. You've already told me that it's higher than " << iLowCompGuess << ".\n";
				}
				else if (strUserFeedback=="Higher" && iCompGuess >= iHighCompGuess - 1) {
					std::cout << "That can't be right. You've already told me that it's lower than " << iHighCompGuess << ".\n";
				}
				else if (strUserFeedback == "Higher") {
					iCompTries++; //add one to number of tries
					iLowCompGuess = iCompGuess; //set new lowest guess
					iCompGuess = (iLowCompGuess + iHighCompGuess) / 2; //guess the number halfway between
				}
				else if (strUserFeedback=="Lower") {
					iCompTries++;
					iHighCompGuess = iCompGuess;
					iCompGuess = (iLowCompGuess + iHighCompGuess) / 2;
				}
			}

			if (strUserFeedback == "Yes") {
				if (iCompTries == 1) { //get the correct grammar
					std::cout << "Wow! That only took me 1 try!\n";
				}
				else {
					std::cout << "Wow! That only took me " << iCompTries << " tries!\n";
				}
			}

		} while (strUserFeedback!="Yes");

	}


	system("PAUSE");
	return 0;
}

