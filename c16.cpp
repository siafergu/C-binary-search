/*Sianna Ferguson
Cit-245-Z01
7/8/2025
purpose: this files uses template functions to search through arrays in a binary way. it outputs the 
array and then tests it against a different array to see what overlap exists.*/


#pragma warning(disable: 4996)
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//template funciton
template<typename T>
int binarySearch(const vector<T>& arr, const T& key) {
	int low = 0, high = arr.size() - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == key)
			return mid;
		else if (arr[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1; //not found
}
//test 
template<typename T>
void testSearch(const vector<T>& arr, const vector<T>& tests) {
	for (const T& item : tests) {
		int index = binarySearch(arr, item);
		if (index != -1)
			cout << item << " is at index: " << index << endl;
		else
			cout << item << " is not in the array."<<endl;
	}
}
//main
int main() {
	vector<int> intArr = {0,1,1,2,3,5,6,13,21,32,55};
	vector<int> intTests = {-1,0,1,2,3,4,5,6,7};

	cout << "integer test array contains: \n";
	for (int n : intArr)
		cout << n << " ";
	cout << "\n";
	testSearch(intArr, intTests);
	cout << " \n";
	//string test
	vector<string> strArr = {"head", "knees", "shoudlers", "toes"};
	vector<string> strTests = {"elbows", "knees"};
	cout << "string test array contains: \n";
	for (const string& s : strArr)
		cout << s << " ";
	cout << "\n";
	testSearch(strArr, strTests);

	return 0;

}
