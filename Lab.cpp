//============================================================================
// Name        : Lab.cpp
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

char letters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u'
   ,'v','w','x','y','z',};
string morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.",
    "---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

class Message{
protected:
	string message;
public:
	Message();
	Message(string message);
	virtual void print();
	virtual ~Message();
	string getMessage();
};

class MorseCodeMessage : public Message{	// extends Message class
private:
	string translatedMessage;
public:
	MorseCodeMessage();
	MorseCodeMessage(string m);
	void translate(string message);	//call during initialization
	void print();	//overrides print in Message class
	string getTranslatedMessage();
};

class MessageStack{
public:
	vector<Message*> stackVector;
	MessageStack();	//default constructor
	MessageStack(Message *mObj);
	void push(Message *mObj);
	void pop();
	void printStack();
};

Message::Message(){
	cout << "Inside message constructor" << endl;
}

Message::Message(string message){
	this->message = message;
	cout << "Inside message constructor with a string" << endl;
}

Message::~Message(){}

void Message::print(){
	cout << message << endl;
}

string Message::getMessage(){
	return message;
}

MorseCodeMessage::MorseCodeMessage() : Message(){
	cout << "Inside default morse code constructor" << endl;
}

MorseCodeMessage::MorseCodeMessage(string message) : Message(message){	//Message's parametric constructor is called
	cout << "Inside morse code constructor with a string" << endl;
	translate(message);
}

void MorseCodeMessage::translate(string input){
	for(int i = 0; i < input.length(); i++)
	    {
	        if( input[i] == ' ')
	        {
	            translatedMessage += "/";
	        }
	        for( int j = 0; j < 26; j++)
	        {
	           input[i] = tolower(input[i]);
	            if( input[i] == letters[j])
	            {
	                translatedMessage += (morse[j]+ " ");
	            }
	        }
	    }
	    cout<<""<<translatedMessage<<endl; //for testing purpose
}

string MorseCodeMessage::getTranslatedMessage(){
	return translatedMessage;
}
void MorseCodeMessage::print(){
	cout << "The translated message is: " << translatedMessage <<endl;
}

MessageStack::MessageStack(){}

MessageStack::MessageStack(Message* mObj){
	stackVector.push_back(mObj);
}

void MessageStack::printStack(){
	int length = stackVector.size();
	if( length == 0){
		cout << "Stack is empty" << endl;
		return;
	}

	for(int i = 0; i < length; i++){
		stackVector[i]->print();
	}
}

void MessageStack::push(Message* mObj){
	int i = 0;
	stackVector.push_back(mObj);
}

void MessageStack::pop(){
	if(stackVector.size() == 0){
		cout << "Cannot pop message because the stack is empty. Create a message then push it to the stack." << endl;
	}
	else{
		stackVector.pop_back();	//removes the last element from the vector
	}
}

int main() {
	int option1 = 0, option2 = 0;
	string input;
	Message *m1;
	MessageStack myStack;

	while(option1 != 5){
		cout << "\nStack Menu: " << endl
		     << "\t 1) Enter Message" << endl
			 << "\t 2) Push Message" << endl
		     << "\t 3) Pop Message" << endl
		     << "\t 4) Print Stack" << endl
		     << "\t 5) Exit" << endl;
		     cin >> option1;

		switch (option1) {
		case 1:	//Enter message
			cout << "Enter a message followed by a period:" << endl;
			getline(cin, input, '.');

			cout << "Would you like to translate the message? \n"
					"1) Yes \n2) No" << endl;
			cin >> option2;

			if (option2 == 1) {
				MorseCodeMessage* myMessage = new MorseCodeMessage(input);
				m1 = myMessage;
			} else if (option2 == 2) {
				Message* myMessage = new Message(input);
				m1 = myMessage;
			} else {
				cout << "Invalid selection made. Choose 1 or 2." << endl;
			}
			break;

		case 2:	//Push Message
			if (m1 == NULL) {
				cout << "There is no message to push to the stack" << endl;
			} else {
				myStack.stackVector.push_back(m1);
				cout << "Message was pushed to stack" << endl;
			}
			break;

		case 3:	//Pop Message
			if (m1 == NULL || myStack.stackVector.size() == 0) {
				cout << "The stack is empty, push a message to the stack first"
						<< endl;
			} else {
				myStack.stackVector.pop_back();
				cout << "Message was popped from stack" << endl;
			}
			break;

		case 4:	//Print Message
			myStack.printStack();
			break;

		case 5:
			break;
		}

	}
}

