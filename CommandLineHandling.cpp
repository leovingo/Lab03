﻿#include "Lab03_header.h"
int line_order(char* argv[], int argv2) {
	if (strcmp(argv[1], "-a") == 0) {
		switch (argv2) {
			case 5: {
				bool is_command1 = true;
				int i = 0;
				while (argv[argv2][i] != '\0') {
					if (argv[argv2][i] > '9' || argv[argv2][i] < '0') {
						return 1;
					}
					return 3;
				}
			}
			case 6:
				return 2;
			default:
				return -1;
		}
	}
	else {
		switch (argv2) {
			case 5:
				return 4;
			case 6:
				return 5;
			default:
				return -1;
		}
	}
	return -1;
}
void Command_line(char* argv[], int argv2) {
	int order = line_order(argv, argv2);
	switch (order) {
		case 1:
			Command_line_1(argv);
			return;
		case 2:
			Command_line_2(argv);
			return;
		case 3:
			Command_line_3(argv);
			return;
		case 4:
			Command_line_4(argv);
			return;
		case 5:
			Command_line_5(argv);
			return;
		default:
			return;
	}
}
void Command_line_1(char* argv[]){}
void Command_line_2(char* argv[]) {
	//tính size
	int size = atoi(argv[4]);
	int* arr = new int[size];
	string order;
	GenerateData(arr, size, data_order(argv, 5, order));
	// gán biến đầu ra
	int output;
	if (strcmp(argv[4], "-time") == 0) {
		output = 0;
	}
	else if (strcmp(argv[4], "-comp") == 0) {
		output = 1;
	}
	else if (strcmp(argv[4], "-both") == 0) {
		output = 2;
	}
	else {
		output = -1;
	}
	//vì kích thước mảng có thể lớn nên khuyên mọi người cấp phát động
	double time1;
	int comp1;
	comp1 = Calculate_Complexity(argv, 2, time1, arr, size);
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm:" << argv[2] << endl;
	cout << "Input size: " << argv[4] << endl;
	cout << "Input order: " << order << endl;
	GenerateData(arr, size, 0);
	cout << "--------------\n";
	switch (output)
	{
	case 0:
		cout << "Running time: " << fixed << time1 << setprecision(3) << " msec " << endl;
		break;
	case 1:
		cout << "Comparisions: " << comp1 << endl;
		break;
	case 2:
		cout << "Running time: " << fixed << time1 << setprecision(3) << " msec " << endl;
		cout << "Comparisions: " << comp1 << endl;
		break;
	default:
		break;
	}
	cout << endl;
}
void Command_line_3(char* argv[]) {
	//tính size
	int size = atoi(argv[3]);

	// gán biến đầu ra
	int output;
	if (strcmp(argv[4], "-time") == 0) {
		output = 0;
	}
	else if (strcmp(argv[4], "-comp") == 0) {
		output = 1;
	}
	else if (strcmp(argv[4], "-both") == 0) {
		output = 2;
	}
	else {
		output = -1;
	}

	//vì kích thước mảng có thể lớn nên khuyên mọi người cấp phát động
	int* arr = new int[size];
	double time1, time2, time3, time4;
	int comp1, comp2, comp3, comp4;
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm:" << argv[2] << endl;
	cout << "Input size: " << size << endl;
	cout << "Input order: Randomize" << endl;
	GenerateData(arr, size, 0);
	write_to_file("input_1.txt",arr, size);
	comp1 = Calculate_Complexity(argv, 2, time1, arr, size);
	cout << "--------------\n";
	switch (output)
	{
	case 0:
		cout << "Running time: " << fixed << time1 << setprecision(3) << " msec " << endl;
		break;
	case 1:
		cout << "Comparisions: " << comp1 << endl;
		break;
	case 2:
		cout << "Running time: " << fixed << time1 << setprecision(3) << " msec " << endl;
		cout << "Comparisions: " << comp1 << endl;
		break;
	default:
		break;
	}
	cout << endl;
	cout << "Input order: Nearly Sorted" << endl;
	GenerateData(arr, size, 3);
	write_to_file("input_2.txt",arr, size);
	comp2 = Calculate_Complexity(argv, 2, time2, arr, size);
	cout << "--------------\n";
	switch (output)
	{
	case 0:
		//cout << "Running time: " << time2 << endl;
		cout << "Running time: " << fixed << time2 << setprecision(3) << " msec " << endl;
		break;
	case 1:
		cout << "Comparisions: " << comp2 << endl;
		break;
	case 2:
		//cout << "Running time: " << time2 << endl;
		cout << "Running time: " << fixed << time2 << setprecision(3) << " msec " << endl;
		cout << "Comparisions: " << comp2 << endl;
		break;
	default:
		break;
	}
	cout << endl;
	cout << "Input order: Sorted" << endl;
	GenerateData(arr, size, 1);
	write_to_file("input_3.txt",arr, size);
	comp3 = Calculate_Complexity(argv, 2, time3, arr, size);
	cout << "--------------\n";
	switch (output)
	{
	case 0:
		//cout << "Running time: " << time3 << endl;
		cout << "Running time: " << fixed << time3 << setprecision(3) << " msec " << endl;
		break;
	case 1:
		cout << "Comparisions: " << comp3 << endl;
		break;
	case 2:
		//cout << "Running time: " << time3 << endl;
		cout << "Running time: " << fixed << time3 << setprecision(3) << " msec " << endl;
		cout << "Comparisions: " << comp3 << endl;
		break;
	default:
		break;
	}
	cout << endl;
	cout << "Input order: Reversed" << endl;
	GenerateData(arr, size, 2);
	write_to_file("input_4.txt",arr, size);
	comp4 = Calculate_Complexity(argv, 2, time4, arr, size);
	cout << "--------------\n";
	switch (output)
	{
	case 0:
		//cout << "Running time: " << time4 << endl;
		cout << "Running time: " << fixed << time4 << setprecision(3) << " msec " << endl;
		break;
	case 1:
		cout << "Comparisions: " << comp4 << endl;
		break;
	case 2:
		//cout << "Running time: " << time4 << endl;
		cout << "Running time: " << fixed << time4 << setprecision(3) << " msec " << endl;
		cout << "Comparisions: " << comp4 << endl;
		break;
	default:
		break;
	}
}
void Command_line_4(char* argv[]){}
void Command_line_5(char* argv[]) {
	int size = atoi(argv[4]);
	int* arr = new int[size];
	string order;
	GenerateData(arr, size, data_order(argv, 5,order));
	write_to_file("input.txt", arr, size);
	double time1, time2;
	int ass1, ass2;
	int* arr2 = new int[size];
	for (int i = 0; i < size; i++) {
		arr2[i] = arr[i];
	}
	ass1 = Calculate_Complexity(argv, 2, time1, arr, size);
	ass2 = Calculate_Complexity(argv, 3, time2, arr2, size);
	cout << "COMPARE MODE\n";
	cout << "Algorithm:" << argv[2] << " | " << argv[3] << endl;
	cout << "Input size: " << argv[4] << endl;
	cout << "Input order: "<<order<<endl;
	cout << "--------------\n";
	cout << "Running time:(ms) " << time1 << " | " << time2 << endl;
	cout << "Comparisions: " << ass1 << " | " << ass2 << endl;
}
void write_to_file(string file_name, int *arr, int size) {
	ofstream f;
	f.open(file_name,ios_base:: trunc);
	if (!f) {
		cout << "Cannot open file\n";
		return;
	}
	f << size<< endl;
	for (int i = 0; i < size; i++) {
		f << arr[i]<<" ";
	}
	f.close();
}