#include<iostream>
#include"biginteger.h"
#include<string>
#include<fstream>
#include <chrono>
using namespace std::chrono;
using namespace std;

void main()
{
	biginteger k;
	int choice;
	cout << "1-Manualy test." << endl;
	cout << "2-sample test cases." << endl;
	cout << "3-complete test cases." << endl;
	cin >> choice;
	auto start = high_resolution_clock::now();
	if (choice == 1)
	{
		char op;
		string s1, s2, result="";
		while(true)
		{ 	
		cout << "enter num1 (+,-,*,/,%) number2 and bye to exit" << endl;
		cin >> s1;
		if (s1[0] == 'b'||s1[0]=='B')
		{
			break;
		}
			cin>> op >> s2;
		////cin as num1 space operation number2;

		switch (op)
		{
		case '+':
			result = k.addition(s1, s2);
			break;
		case '-':
			result = k.subtraction(s1, s2);
			break;
		case '*':
			result = k.multiplication(s1, s2);
			break;
		case '/':
			result = k.divide(s1, s2);
			break;
		case '%':
			result = k.mod(s1, s2);
			break;
		default:
			break;
		}
		cout << result<<endl;

		}
	}else{
	fstream input;
	fstream output;
	if (choice == 2)
	{
		output.open("output_sample.text", ios::app);
		input.open("SampleRSA.txt");
	}
	else
	{
		output.open("output_complete.text", ios::app);
		input.open("TestRSA.txt");
	}
	string n;
	getline(input, n);
	int num = stoi(n);
	string B, p, m, s_eord, result = "0";
	int eord;
	for (int i = 0; i < num; i++)
	{
		getline(input, n);
		getline(input, p);
		getline(input, m);
		getline(input, s_eord);
		eord = stoi(s_eord);
		if (eord == 0)
		{
			auto start = high_resolution_clock::now();
			result = k.Encrypt(m, p, n);
			output << result << "\n";
			auto stop = high_resolution_clock::now();
			double duration_m = double(duration_cast<milliseconds>(stop - start).count());
			duration_m = duration_m / 1000;
			output << "time :" << duration_m << " sec \n";
		}
		else
		{
			auto start = high_resolution_clock::now();
			result = k.decrypt(m, p, n);
			output << result << "\n";
			auto stop = high_resolution_clock::now();
			double duration_m = double(duration_cast<milliseconds>(stop - start).count());
			duration_m = duration_m / 1000;
			output << "time :" << duration_m << " sec \n";
		}
	}
	input.close();
	output.close();
	auto stop = high_resolution_clock::now();
	double duration_m = double(duration_cast<milliseconds>(stop - start).count());
	duration_m = duration_m / 1000;
	cout << duration_m << " S " << endl;
	system("pause");
}


}
