#ifndef LIST_H
#define LIST_H
#ifndef VAR
#define VAR

#include <stdexcept>

template <typename T> 
class List {
    public:
        virtual ~List(){}
	virtual void insert(int pos, T e) = 0;
	virtual void append(T e) = 0;
	virtual void prepend(T e) = 0;
	virtual T remove(int pos) = 0;
	virtual T get(int pos) const = 0;
	virtual int search(T e) const = 0;
	virtual bool empty() const  = 0;
	virtual int size() const = 0;
};

#endif
#endif
