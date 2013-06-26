/*
 * File: Mobile World Prediction
 * ----------------------
 * Name: Atul Agrawal
 * Done: June 26, 2013 at 6:15 PM

 * This file is the starter project for the cell phone mind reading problem on
 * Assignment #3
 * [TODO: extend the documentation]
 */

#include <iostream>
#include"lexicon.h"
#include<stdio.h>
#include<cstdlib>
#include<string>
#include"stack.h"
#include<string>
#include"set.h"
#include"foreach.h"
#include"simpio.h"
#include"console.h"
using namespace std;

void ListCompletions(string digits, Lexicon & lex);
void getCompleteWords(string prefix,Lexicon &lex);

Stack<string> getMappedDigits(int number);
Set<string> getPrefix(string digits,int index);
Set<string> storeWords;
Map<int,Stack<string> > MappedDigits;
int main() {
    string s="";
  
	//Map<int,Stack<string> > MappedDigits;Its a dumb way to store.I wanted to store it in stack.Storing in a array
	//will be beneficial 
	//eg. static string digitToLetters[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	Stack<string> num2;
		num2.push("c");
		num2.push("b");
		num2.push("a");

	Stack<string> num3;
		num3.push("f");
		num3.push("e");
		num3.push("d");
	Stack<string> num4;
		num4.push("i");
		num4.push("h");
		num4.push("g");
	Stack<string> num5;
		num5.push("l");
		num5.push("k");
		num5.push("j");
	Stack<string> num6;
		num6.push("o");
		num6.push("n");
		num6.push("m");
	Stack<string> num7;
		num7.push("s");
		num7.push("r");
		num7.push("q");
		num7.push("p");
	Stack<string> num8;
		num8.push("v");
		num8.push("u");
		num8.push("t");
	Stack<string> num9;
		num9.push("z");
		num9.push("y");
		num9.push("x");
		num9.push("w");
	MappedDigits.put(2,num2);
	MappedDigits.put(3,num3);
	MappedDigits.put(4,num4);
	MappedDigits.put(5,num5);
	MappedDigits.put(6,num6);
	MappedDigits.put(7,num7);
	MappedDigits.put(8,num8);
	MappedDigits.put(9,num9);

	
		cout<<"Enter the prefix..0 to hault"<<endl;
		s=getLine();
		try{
			Lexicon lex("EnglishWords.dat");
			cout<<""<<endl;
			ListCompletions(s,lex);
		}
		catch(int){
			cout<< "unhandled exception" << endl;
		}

	system("PAUSE");
	
	return 0;
}

void ListCompletions(string digits, Lexicon & lex){
	Set<string> allPrefix;
	allPrefix=getPrefix(digits,0);
	foreach(string str in allPrefix){
		getCompleteWords(str,lex);
	}
	foreach(string str in storeWords){
		cout<<str<<endl;
	}
}

void getCompleteWords(string prefix,Lexicon &lex){
	if(lex.containsPrefix(prefix)){
		if(lex.contains(prefix))
			storeWords.add(prefix);
	for(int i='a';i<='z';i++){
		string newPrefix;
		newPrefix=prefix+(char)i;
		getCompleteWords(newPrefix,lex);
	}
	}
}

Stack<string> getMappedDigits(int number){
	return MappedDigits[number];
}

Set<string> getPrefix(string digits,int index){
	Set<string> completeSet;int getNumber;
	if(index==digits.length()){
		Set<string> a;
		a.add("");
		return a;
	}
	else{
		char c=digits[index];
		getNumber=c-'0';
		Stack<string> stack=getMappedDigits(getNumber);	
		Set<string> incompleteSet=getPrefix(digits,index+1);
		while(!(stack.isEmpty())){
			string charString=stack.pop();
			foreach(string str in incompleteSet){
				string fullstr=charString+str;
				completeSet.add(fullstr);
			}
		}
	}
	return completeSet;
}



