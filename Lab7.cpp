//============================================================================
// Name        : Lab7.cpp
// Author      : Tess McCorkle
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <stdio.h>
using namespace std;

class Message{
protected:
	string message;

public:
	Message();
	Message(string message);
	void print();
	~Message();

};

Message::Message(){
	cout << "Enter a message: " << endl;
	cin >> message;
}

Message::Message(string message){
	this->message = message;
	cout << "Inside message constructor with a string" << endl;
}

Message::~Message(){

}

void Message::print(){
	cout << message << endl;
}

class MorseCodeMessage : public Message{	// extends Message class
public:
	string translatedMessage;
	MorseCodeMessage();
	MorseCodeMessage(string m);
	void translate(string message);	//call during initialization
	void print();	//overrides print in Message class

};
MorseCodeMessage::MorseCodeMessage() : Message(){
	cout << "Inside default morse code constructor" << endl;
	translate(message);
}

MorseCodeMessage::MorseCodeMessage(string message) : Message(message){	//Message parametric constructor is called
	cout << "Inside morse code constructor with a string" << endl;
	translate(message);
}

void MorseCodeMessage::translate(string message){
	translatedMessage = message + "!";
}

void MorseCodeMessage::print(){
	cout << "The translated message is: " << translatedMessage << endl;
}

class MessageStack{
public:
	MessageStack();	//default constructor
	MessageStack(Message mObj);
	vector<Message> stackVector;
	void push(Message mObj);
	void pop();
	void printStack();
};

MessageStack::MessageStack(Message mObj){
	stackVector.push_back(mObj);
}
void MessageStack::pop(){

}

void MessageStack::printStack(){
	int length = stackVector.size();

	for(int i = 0; i < length; i++){
		cout << stackVector[i].print() << endl;
	}
}

void MessageStack::push(Message mObj){
	stackVector.push_back(mObj);
}

int main() {
	int choice = 0;
	int choice2;
	string message;

	while(choice != 5){
		cout << "1. Enter text" << endl << "2. Print Stack" << endl
				<< "3. Pop" << endl << "4. Push " << endl << "5. Exit" << endl;
		cin >> choice;

		switch(choice){
		case 1:
			cout << "1. Translate" << endl << "2. Do not translate" << endl;
			cin >> choice2;

			if(choice2 == 1){	//chose to translate message
				cout << "Enter a message: " << endl;
				cin >> message;
				MorseCodeMessage tMessage(message);
				tMessage.print();
			}
			if(choice2 == 2){	//chose to not translate message
				Message myMessage;
			}
			break;

		case 2:
			MessageStack myStack;
			break;
		}
	}
	return 0;
}
