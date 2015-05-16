#include<iostream>
using namespace std;

class my_stack
{
	int arr[10];
	int top = 0;


public :
	void push(int a){
		
		if (top < 10){
		
			arr[top] = a;
			top++;
		}
		else
			cout << "cannot insert the stack is full";
		}

	void pop(){
		if (top == 0)
			cout << "cannot pop stack is already empty";
		else
			top--;
	
	}
	void print(){
		int i = top-1;

		while(i>=0){
			cout << " |----------| ";
			cout << endl;
			cout << " |--- " << arr[i] <<" ---| " ;
			cout << endl;
			i--;
		}

	
	}


};



int main(){

	my_stack stk;
	int ch;
	while (1){
		cout << "enter an option \n1.push \n2.pop \n3.printthe stack ";
		cout << endl;
		cin >> ch;
	
		switch (ch)
		{
		case 1: cout << "enter the number";
			cin >> ch;
			stk.push(ch);
			break;

		case 2:stk.pop();
			break;

		case 3:stk.print();
			break;

		default:exit(0);
			break;
		}

	
	}




}