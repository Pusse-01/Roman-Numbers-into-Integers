/****************************
NAME        -P.M.N.R.Pussadeniya
INDEX NO    -19/ENG/082
COURSE		-PROGRAMMING QUEST
COURSE CODE -CO2210
DATE        -09/14/2021
QUEST NO    -02
*****************************/

#include <bits/stdc++.h>

using namespace std;

//Assigning roman number vals to arabic numbers in a map
map<string, int>m = { {"x",10},{"i",1},{"v",5} ,{"l",50},{"c",100} };

//Function to convert the oman number to decimal value
int romanToInt(string str) {
	int n = str.length() - 1;
	int val = 0, repeated = 0;
	string s, s2;
	for (int i = 0; i < str.length(); i++) {
		s = str[i];
		s2 = str[i + 1];
		repeated = 0;
		if (s == s2) {
			for (int j = i; j < str.length(); j++) {
				if (str[i] == str[j + 1]) {
					repeated++;

				}
				else {
					i = j;
					break;
				}
			}
			val += m[s] * (repeated + 1);
		}
		if (s != s2) {

			if (m[s] > m[s2]) {
				val += m[s] + m[s2];
				i = i + 1;
			}
			else {
				val += m[s2] - m[s];
				i = i + 1;
			}
		}
	}
	return val;
}

//Function validate the stored roman number
bool validate(string str) {

	int I=0, V=0, L=0, X=0, C=0;
	string s1, s2, s3;
	
	for (int i = 0; i < str.length(); i++) { 
		if (str[i] == 'x') {
			X++;
		}
		else if (str[i] == 'i') {
			I++;
		}
		else if (str[i] == 'v') {
			V++;
		}
		else if (str[i] == 'l') {
			L++;
		}
		else if (str[i] == 'c') {
			C++;
		}
		else  {
			return false;
		}
		
	}
	if (X > 3 || I > 3 || V > 1 || L > 1 || C > 3 ) {
		return false;
	}
	else {
		s1 = str[0];
		s2 = str[1];
		if (str.length() > 2 && (m[s1] < m[s2] && str[0] != 'x')) {
			return false;
		}
		else {
			for (int i = str.length() - 1; i >= 2; i--) {
				s1 = str[i];
				s2 = str[i - 1];
				s3 = str[i - 2];
				if (m[s1] > m[s2]) {
					if (m[s1] > m[s3]) {
						return false;
					}
				}
			}
		}
		
	}
	
}



int main()
{
	string str;
	
	cout<<"------------------Program to convert roman number into integers---------------------"<<endl;
	cout<<endl;
	
	
	//Reading the text file
	ifstream numbers("numbers.txt");
	if (!numbers) {
		//Passing the error message if the file couldnt read succesfully
		cout << "No file named numbers.txt found" << endl;
	}else{
		while (!numbers.eof()) {//reading the file until the end
			numbers >> str;
			cout << str << " \t:";
			transform(str.begin(), str.end(), str.begin(), ::tolower);
			
			//validating the roman number
			if (validate(str)) {
				cout << romanToInt(str) << endl;
			}
			else {
				cout << "Error" << endl;
			}
		}
	}
	
	//close the file after reading
	numbers.close();
}

