/*
reading processed files for query search
*/

#include<iostream>
#include <algorithm>
#include<map>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<cctype>
using namespace std;

bool isLetter(char*);	//to check whether the character is a latin letter

int main(int argc, char* argv[])
{
	char *file_name;
	/*Taking input of the filename*/
	if(argv[1]) {
		file_name = argv[1];
	}
	else {
		cout<<"Enter the file name: ";
		file_name = (char*)malloc(sizeof(char)*1000);
		scanf("%s",file_name);
	}
	const char *FILE_NAME = (const char*)file_name;
	
	/*Open the processed file for reading*/
	string file=FILE_NAME, name;
	name = file+".seq";
	FILE *seq	=fopen(name.c_str(), "r");
	name = file+".flag";
	FILE *ptr	=fopen(name.c_str(), "r");
	
	if(ptr == NULL || seq == NULL)
		return 1;
		
	int i, size, j;
	int **arr;
	char **flag, inp;
	
	fscanf(ptr, "%d", &size);			//size is stored in .flag file
	
	//Building up arrays for inserting values
	arr		= (int**)malloc(sizeof(int*)*size);
	flag 	= (char**)malloc(sizeof(char*)*size);
	for(i=0; i<size; i++) {
		arr[i] = (int*)malloc(sizeof(int)*26);
		flag[i] = (char*)malloc(sizeof(char)*26);
	}
	
	//taking the contents of the file into the array
	inp = getc(ptr);
	for(i=0; i<size; i++) {
		for(j=0; j<26; j++) {
			fscanf(seq, "%d", &arr[i][j]);
			fscanf(ptr, "%c%c", &flag[i][j], &inp);
			
			if(! isLetter(&flag[i][j])) {
				cout<<"Error in reading file";
				return 2;
			}
		}
	}
	fclose(seq);
	fclose(ptr);
	
	
	while(1) {
		string searchString;
		cout<<"Enter the string to be searched: ";
		cin>>searchString;
		string copyString = searchString;
		
		int len = searchString.length(), key=0;
		for(i=0; i<len-1; i++) {
			isLetter(&searchString[i]);
			j = searchString[i]-'a';
			if(arr[key][j] == 0)
				break;
			else {
				key = arr[key][j];
			}
		}
		isLetter(&searchString[i]);
		j = searchString[i]-'a';		//index of the last character
		if(i<len-1 || flag[key][j] == 'z')
			cout<<copyString<<" is not present"<<endl;
		else if(flag[key][j] == 'a')
			cout<<copyString<<" is a prefix of some other string(s)"<<endl;
		else if(flag[key][j] == 'e')
			cout<<copyString<<" is present"<<endl;
		else
			cout<<"Error occured in searching "<<copyString<<endl;
	}
	return 0;
}

bool isLetter(char* x) {		//checks whether the character is a letter or not 
	if(*x>='a' && *x<='z')
		return true;
	else if(*x>='A' && *x<='Z') {		//if it is uppercase then change it into lowercase 
		*x = *x+32;
		return true;
	}
	else
		return false;
}
