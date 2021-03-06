/*
Making files for processing
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

typedef struct node {
	char flag;
	struct node *next;
}cell;

bool isLetter(char*);	//to check whether the character is a latin letter
int addWord(string, cell**, map<cell*, int>*, int);	//to add the word into the DS
cell* newNode(map<cell*, int>*, int*);		//to add a new array of the DS
int makeFile(cell*, map<cell*, int>*, int, const char*);	//convert and add all the data into files

int main(int argc, char* argv[])
{
	char *file_name;
	/*Taking input of the filename*/
	if(argv[1]) {					//either from command line input
		file_name = argv[1];
	}
	else {							//or as a standard input
		cout<<"Enter the file name: ";
		file_name = (char*)malloc(sizeof(char)*1000);
		scanf("%s",file_name);
	}
	const char *FILE_NAME = (const char*)file_name;
	
	/*Open the file for reading*/
	FILE *file;
	file = fopen(FILE_NAME, "r");
	if(file == NULL) {
		return 1; //Could not open file
	}
	
	cell *top=NULL;					//It is the headmost part of the TRIE DS
	map<cell*, int> mapper;			//It stores the sequencial number of the array
	int key = 1;					//It is the array number, i.e. each new array is given a unique number
	
	/*Extracting the words(consisting of letters only and building the structure*/
	char ch = getc(file);
	while(ch != EOF) {
		string word="";
		while(isLetter(&ch) && ch != EOF) {
			word += ch;
			ch = getc(file);
		}
		
		if(word.size() > 0) {		//if any word is there to enter into dictionary
			key = addWord(word, &top, &mapper, key);
		}
		ch = getc(file);
	}
	fclose(file);
	
	key--;			//since key is always one more than the number of arrays
	cout<<"Number of arrays made: "<<key<<endl;
	
	return makeFile(top, &mapper, key, FILE_NAME);
}

int makeFile(cell* head, map<cell*, int> *mp, int size, const char* FILE_NAME) {
	
	char **flag;
	int **arr, key, i, nextKey;
	cell *temp;
	
	//Building up arrays for inserting values
	arr		= (int**)malloc(sizeof(int*)*size);
	flag 	= (char**)malloc(sizeof(char*)*size);
	for(i=0; i<size; i++) {
		arr[i] = (int*)calloc(sizeof(int), 26);
		flag[i] = (char*)calloc(sizeof(char), 26);
	}
	
	/*Converting the pointer based structures into arrays*/
	for(map<cell*, int>::iterator it=(*mp).begin(); it != (*mp).end(); ++it) {
		key = it->second;		//The array number for which values is to be put
		
		temp = it->first;		//the array which is considered
		for(i=0; i<26; i++) {
			
			if(temp[i].next == NULL) {
				arr[key-1][i] = 0;		// =0 shows that there is no next array 
			}
			else {
				nextKey = (*mp)[temp[i].next] -1;	//points to the next array
				arr[key-1][i] = nextKey;
			}
			flag[key-1][i] = temp[i].flag;
		}
	}
	
	/*W rite the data into file*/
	string name = FILE_NAME;
	string name1 = name+".seq";
	FILE *f1 = fopen(name1.c_str(), "w+");
	name1 = name+".flag";
	FILE *f2 = fopen(name1.c_str(), "w+");
	
	if(f1 == NULL || f2 == NULL)
		return 1;
	
	fprintf(f2, "%d\n", size);
	for(i=0; i<size; i++) {
		
		fprintf(f1, "%d", arr[i][0]);
		for(int j=1; j<26; j++) {
			fprintf(f1, " %d", arr[i][j]);
		}
		fprintf(f1, "\n");
		
		int j=0;
		while(j<26 && flag[i][j] != 'e')
			j++;
		if(j<26) {
			fprintf(f2, "%c", j+'a');
			j++;
			while(j<26) {
				if(flag[i][j]=='e')
					fprintf(f2, "%c", j+'a');
				j++;
			}
		}
		fprintf(f2, "\n");
	}
	fclose(f1); 
	fclose(f2);
	
	return 0;
}

int addWord(string item, cell **head, map<cell*, int> *mapper, int maxKey) {
	
	if(*head == NULL) {					//if the start array is not there
		*head = newNode(mapper, &maxKey);
	}
	
	int i, n=item.length();
	cell *prev=*head, *cur = (*head)[item[0]-'a'].next;
	char prevChar=item[0], curChar;
	
	/*
	Note:
	Storing - 
	'a' means that there are letters after that point.
	'z' is the default which shows that there is no letters followin that point.
	'e' shows that the point is end of word or optionally that some letters follow it too.
	*/
	
	(*head)[item[0]-'a'].flag = 'a';			// the first element should be 'a' as all other letters follow it
	for(i=1; i<n; i++) {
		curChar = item[i];
		
		if(cur == NULL) {			//shows that the array is not present
			cur = newNode(mapper, &maxKey);
			prev[prevChar-'a'].next = cur;
		}
		if(cur[curChar-'a'].flag == 'z')		//that means if this point is not reached yet
			cur[curChar-'a'].flag = 'a';
		
		prev = cur;
		cur = cur[curChar-'a'].next;
		
		prevChar = curChar;
	}
	prev[prevChar-'a'].flag = 'e';		//since this is the end of the word
	return maxKey;
}

cell* newNode(map<cell*, int> *mp, int *key) {		//creates a new array and initialize it accordinly
	cell *temp=(cell*)malloc(sizeof(cell)*26);
	for(int i=0; i<26; i++) {
		temp[i].flag = 'z';
		temp[i].next = NULL;
	}
	mp->insert(pair<cell*, int>(temp, *key));
	(*key)++;
	return temp;
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
