#include <ostream>
#include <iostream>
#include "List.h"
#include "node.h"
using namespace std;
template <typename T>
class ListLinked : public List<T> {
	private:
	Node<T>* first;
	int n;
	public:
	ListLinked(){
		first = nullptr;
		n = 0;
	}
	~ListLinked(){
		delete[] first;
	}
	T operator[] (int pos){
		if(pos<0 || pos >=n -1){
			throw out_of_range("fuera de rango");
		}
		return first[pos];
	}
	template <typename U>
	friend ostream&operator<<(ostream&out, const ListLinked<T> &List);
};
