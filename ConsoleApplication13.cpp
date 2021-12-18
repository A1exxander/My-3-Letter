
#include <iostream>
#include <vector>
#include <fstream>

bool testUsername(const std::string& name) { // This would call the Ubisoft and see if the username is avaibile, if so, itll add it to the vectorlist, you would then iterate thru the vectorlist and create accounts for each name
	return true;
}

void outputNamesToFile(const std::vector<std::string>& usernames) {

	std::ofstream myFile;
	myFile.open("output.txt");

	if (myFile) {
		myFile << "Availible usernames ---\n";
		for (auto i{ 0 }; i < usernames.size(); ++i) {
			myFile << usernames[i] << " ";
		}
		std::cout << "\nSuccessfully printed all 3-letters to file!\n";
		myFile.close();
	}
	else {
		std::cout << "\nFailed to print names to file!";
	}

}

int main(){

	std::string name{ "aaa" }; // username starts at aaa, first combination

	std::vector<std::string> usernames; // list of possible usernames that are availible will be stored here

	while (name!= "zzz") // while the last character in the string is less than z, you want to search for all possible combinations
	{
		bool usernameTest = false; // used to test if username will be valid

		for (auto i{ 97 }; i <= 122; i++) {
			name.at(0) = i; // first character will be set to A and incremented after all possibilities for third character are tested, so AAA, AAB, AAC, ... AAZ, THEN itll increment the second character ABA, ABB, ABC. etc until its ZZZ
			for (auto j{ 97 }; j <= 122; j++) {
				name.at(1) = j;
				for (auto k{ 97 }; k <= 122; k++) {
					name.at(2) = k;	
					usernameTest = testUsername(name);
					if (usernameTest = true) {
						usernames.insert(usernames.end(), name); // If username is valid, we will add it to our list, we may want to resize it instead of use insert
						usernameTest = false;
					}
				}

			}
		}
	}

}

