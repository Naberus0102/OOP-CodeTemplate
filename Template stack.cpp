template <class T>
class Stack{
	public:
		Stack():first(0){};
		~Stack();
		void push(T d);
		T pop();
		bool isEmpty();
		bool isFull();
	private:
		Element<T> *first;
		Stack(const Stack &){};
		Stack & operator=(const Stack &){};
};
template <class U>
class Element{
	friend class Stack<U>;
	Element *next;
	U data;
	Element(Element *n, U d):next(n),data(d){}
};
template <class T>
void Stack<T>::push(T d){	first = new Element<T>(first,d); }
template <class T>
T Stack<T>::pop(){
Element<T> * p = first;
T d = p->data;
first = first->next;
delete p;
return d;
}
template <class T>
Stack<T>::~Stack(){
while(!isEmpty()){
Element<T> * p = first;
first = first->next;
delete p;
}
}
template <class T>
Stack<T>::~Stack(){
	while(!isEmpty()){
		Element<T> * p = first;
		first = first->next;
		delete p;
	}
}
int main(){
	int n;
	cout << "Ngai muon xem dang nhi phan cua so:";	cin >> n;
	Stack<int> stkint;
	while(n){	stkint.push(n%2);	n/=2;	}
	cout <<"Ket qua:";
	while(!stkint.isEmpty())	cout << stkint.pop();
	/* câ?n include "mstring.h"
	Stack<String> stks;
	stks.push("ajg ajgd");
	stks.push(" a 128");
	while(!stks.isEmpty())	cout << stks.pop() << endl;
	*/
	return 0;
}


