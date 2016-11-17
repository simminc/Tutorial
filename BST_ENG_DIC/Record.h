#include<iostream>
#include<string>
using namespace std;

class Record {
	
public :
	string word;
	string meaning;
	Record(string w = "", string m = "") { setWord(w, m); }

	void setWord(string w,string m) {
		word = w;
		meaning = m;
	}

	void display() {
		cout << "word :" << word << "," <<"meaning" << meaning;
	}
	
	int compare(string w) {
		return w.compare(word); //w가 사전적 앞이면 0이하 
	}
};