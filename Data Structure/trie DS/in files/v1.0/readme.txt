TRIE in files

Intro:
It uses the concept of trie data structure but rather than using pointers as its linkage it uses array indexes and thus when written to files (called processed files it can be used for searching in future without again processing it.

Kick Start:
- to start with we first need files (and their file names, ofcourse) which are to be processed.
- the file names are given as a command line argument one-by-one or by standard input one at a time.
- file name is the complete file name(i.e. complete path, to avoid any error)
- the file is opened and processed by "trie DS maker.cpp" program and two new files, "<file_name>.seq" and "<file_name>.flag" are generated, where <file_name> is the complete path of the file given.
- now for searching "trie DS search.cpp" program is used which takes an input of the file name given earlier, along with unlimited number of query string to search.
- it outputs whether the query string is present or not or it is the prefix of any string.

Technical details:
1. Return values:
		0 = proper termination of the program
		1 = error in opening any file.
		2 = error in reading the file contents.
		
2. Character markers:
		'z' = shows that there is not letter after this point and the point is not reached and is the default value.
		'a' = shows that one or more characters follow this point
		'e' = shows that it is the position where one or more words ended and/or some other letter(s) follow this point.
		
	Note: "point" here refers to the sequence of characters and the array traversed so far

3. Files: 
		*.cpp = the programs to be executed
		*.seq, *.flag = processed files for future query
		*.bak = the debug files which consists of points where data can be printed by proper un-commenting of lines in th program, they are present in "backup files" folder
		
for any further query contact @ gtm93singh[at]gmail.com