// Exam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
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

void process(vector<Example*> &database){
	bool n=false;
	while(!n){
	system("cls");
	cout<<"Working with documents database.";
	cout<<"\nCurrent size: "<<(int)database.size();
	cout<<"\nChoose action:";
	cout<<"\n0 - show | 1 - add | 2 - remove | 3 - quit\n";
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
