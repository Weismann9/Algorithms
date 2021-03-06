// Exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

class Example{
public:
	string str_field;
	int int_field;
	double double_field;
public:
	Example(){}
	void Set(){
		cout<<"str_field: "; cin>>str_field;
		cout<<"int_field: "; cin>>int_field;
		cout<<"double_field: "; cin>>double_field;
	}
	void Get(){
		cout << "str_field - " << str_field;
		cout << "\nint_field - " << int_field;
		cout << "\ndouble_field: " << double_field;
		cout << endl;
	}
	~Example(){}
};

//Data processing functions
void fill(vector<Example*> &document, int from){
	cout<<"\nFilling the data with records. \nExt - "<<(int)document.size()<<endl;
	for(int i=from; i<(int)document.size(); i++){
		cout << "\n["<<i+1<<"] record \n";
		Example *record = new Example();
		record->Set();
		document[i] = record;
	}
}

void add_element(vector<Example*> &document){
	cout<<"Adding elements... Count: "; int c; cin>>c;
	int next=(int)document.size();
	document.resize((int)document.size()+c);
	fill(document,next);
}

void del_element(vector<Example*> &document){
	if((int)document.size()==0){
		cout<<"\nDatabase is empty!\n"; 
		system("pause");
	}
	else{
		cout<<"\nEnter the index of element to be removed.\n";
		int id; cin>>id; id--;
		if(id>=0 && id<(int)document.size()){
		document.erase(document.begin()+id);
		cout<<"\nElement ["<<id+1<<"] removed...\n";
		system("pause");
		}else 
		{
			cout<<"\nNo such element!\n";
			system("pause");
		}
	}
}

void output(vector<Example*> &document){
	if((int)document.size()==0){
		cout<<"\nDatabase is empty!\n"; 
		system("pause");
	}else{
	cout<<"\nDocuments output:\n";
		for(int i=0; i<(int)document.size(); i++){
			cout << "["<<i+1<<"] record \n";
			document[i]->Get();
		}
	system("pause");
	}
}


//Algorithms
//bool compare(){
//	return 
//}
void bubble_sort(vector<Example*> &document){
	for(int i = 0; i < (int)document.size(); i++){
		for(int j = 0 ; j < (int)document.size()-1; j++){
			if(document[j]->int_field > document[j+1]->int_field){
				swap(document[j],document[j+1]);
			}
		}
	}
}

void shaker_sort(vector<Example*> &document){
	for(int i = 0; i < (int)document.size(); i++){

		for(int j = 0 ; j < (int)document.size()-1-i; j++){
			if(document[j]->int_field > document[j+1]->int_field){
				swap(document[j],document[j+1]);
			}
		}

		for(int k = (int)document.size()-1-i; k > i; k--){
			if(document[k-1]->int_field > document[k]->int_field){
				swap(document[k],document[k-1]);
			}
		}

	}
	
}

void insertion_sort(vector<Example*> &document){
	for(int i=0; i < (int)document.size()-1; i++){
		int j=i+1;
		Example* tmp = document[j];
		while(j > 0 && (document[j-1]->int_field > tmp->int_field)){
			document[j] = document[j-1];
			j--;
		}
		document[j] = tmp;
	}
}

void shell_sort(vector<Example*> &document){
	int step = (int)document.size() / 2;
	while(step > 0){
		for (int i = 0; i < (int)document.size() - step; i++) {
			int j = i + step;
			Example* tmp = document[j];
			while (j >= step && (document[j-step]->int_field > tmp->int_field) ) {
				document[j] = document[j - step];
				j -= step;
			}
			document[j] = tmp;
		}
        if (step == 2) {
            step = 1;
        } else {
			step = (int)(step/2.2);
        }
	}
}

 void quick_sort(vector<Example*> &document, int left, int right){
	int iter=left, jter=right;
	int t = (iter + jter) / 2;
	Example* temp = document[t];
	while (document[iter]->int_field < temp->int_field)iter++;
	while (document[jter]->int_field > temp->int_field)jter--;
	if (jter >= iter) {
		swap(document[iter], document[jter]);
		iter++;
		jter--;
	}
	if (left < jter)quick_sort(document, left,jter);
	if (right > iter)quick_sort(document, iter, right);
}
 
void repairTop(vector<Example*> &document, int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	// If left child is larger than root
	if (l < n && document[l]->int_field > document[largest]->int_field)
		largest = l;

	// If right child is larger than largest so far
	if (r < n && document[r]->int_field > document[largest]->int_field)
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		swap(document[i], document[largest]);

		// Recursively heapify the affected sub-tree
		repairTop(document, n, largest);
	}
}

void heap_sort(vector<Example*> &document) {
	for (int i = (int)document.size() / 2 - 1; i >= 0; i--) {
		repairTop(document, (int)document.size() - 1, i);
	}
	for (int i = (int)document.size() - 1; i >= 0; i--) {
		swap(document[0], document[i]);
		repairTop(document, i, 0);
	}
}



int get_max(vector<Example*> &document){
	int max = document[0]->int_field;
	for(int i = 0; i < (int)document.size(); i++){
		if(document[i]->int_field > max){
			max = document[i]->int_field;
		}
	}
	return max;
}

int **initArr(int row, int column) {
	int **arr = new int*[row];
	for (int i = 0; i < row; i++){
		arr[i] = new int[column];
	}
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			arr[i][j] = 0;
		}
	}
	return arr;
}

vector<Example*> count_sort(vector<Example*> &document, int exp){
	int **arr = initArr(10, (int)document.size());

	for (int i = 0; i < (int)document.size(); i++) {
		arr[(document[i]->int_field / exp) % 10][i] = document[i]->int_field;
	}

	for (int i = 0, k = 0; i < 10; i++) {
		for (int j = 0; j < (int)document.size(); j++) {
			if (arr[i][j]) {
				document[k]->int_field = arr[i][j];
				k++;
			}
		}
	}
	return document;
}

void radix_sort(vector<Example*> &document){
	int max = get_max(document);
	for(int exp = 1; max / exp > 0; exp *= 10){
		document = count_sort(document,exp);
	}
}

void binary_search(vector<Example*> &document, int pLeft, int pRight, int sEl){
	int el = (pLeft + pRight) / 2;
	if (document[el]->int_field == sEl){ 
		cout << "Record: " << document[el]->str_field << " " <<  document[el]->int_field << " " << document[el]->double_field << "\n";
		if (el-1 >= 0 && el+1 <= (int)document.size()-1){
			for (int i = el - 1; document[el]->int_field == document[i]->int_field; i--) {
				cout << "Record: " << document[i]->str_field << " " <<  document[i]->int_field << " " << document[i]->double_field << "\n";
			}

			for (int j = el + 1; document[el]->int_field == document[j]->int_field; j++) {
				cout << "Record: " << document[j]->str_field << " " <<  document[j]->int_field << " " << document[j]->double_field << "\n";
			}
		}
	}else {
		if (pLeft == pRight){
			cout << "Record not found\n";
			return;
		}
	}

	if (document[el]->int_field > sEl) {
		binary_search(document, pLeft, el - 1, sEl);
	}

	if (document[el]->int_field  < sEl) {
		binary_search(document, el + 1, pRight, sEl);
	}
}

//Main function
void process(vector<Example*> &database){
	bool n=false;
	while(!n){
	system("cls");
	cout<<"Working with documents database.";
	cout<<"\nCurrent size: "<<(int)database.size();
	cout<<"\nChoose action:";
	cout<<"\n0 - show | 1 - add | 2 - remove | 3 - quit | 4 - random fill | 5 - bubble sort | 6 - shaker sort | 7 - insertion sort | 8 - Shell sort | 9 - quick(hyarem) sort | A - radix sort | B - binary search | C - heap sort\n";
	char selector; cin>>selector;
	switch(selector){
		case '0':{
			output(database);
			break;
			   }
		case '1':{
			add_element(database);
			break;
			   }
		case '2':{
			del_element(database);
			break;
			   }
		case '3':{
			n=true;
			break;
			   }
		case '4':{
			bubble_sort(database);
			output(database);
			break;
				}
		case '5':{
			bubble_sort(database);
			output(database);
			break;
				}
		case '6':{
			shaker_sort(database);
			output(database);
			break;
				}
		case '7':{
			insertion_sort(database);
			output(database);
			break;
				}
		case '8':{
			shell_sort(database);
			output(database);
			break;
				}
		case '9':{
			quick_sort(database, 0 ,(int)database.size()-1);
			output(database);
			break;
				}
		case 'A':{
			radix_sort(database);
			output(database);
			break;
				}
		case 'B':{
			int search_el;
			cout << "Enter seraching element: "; cin >> search_el;
			binary_search(database, 0 , (int)database.size()-1, search_el);
			system("pause");
			break;
				}
		case 'C':{
			heap_sort(database);
			output(database);
			break;
				}
		default: break;
	}

	}
}

void main()
{
	vector<Example*> database;
	process(database);
	system("PAUSE");
}

