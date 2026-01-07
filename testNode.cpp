#include <iostream>
#include "node.h"
using namespace std;
int main(){
	Node<char>* first = new Node<char>('A');
	first= new Node<char>('R',first);
	first= new Node<char>('P', first);
	cout<<"Secuencia: ";
	Node<char>*aux = first;
	while(aux!=nullptr){
		cout << aux->data << " ";
		aux = aux->next;
	}
	cout << endl;
	return 0;
}
