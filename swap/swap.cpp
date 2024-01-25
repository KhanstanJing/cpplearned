#include <iostream>
using namespace std;

void swap1(int a, int b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap2(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//here what should be noticed is that if you delete any "*", there will be an error 
//this tells us that we must remember only pointers can be valuing each other
void swap3(int* a, int* b) {
	int* temp;
	temp = a;
	a = b;
	b = temp;
}

//here if you do: swap4(int&* a, int&* b)
//then there will be an error like: "a"(or "b") cannot create a pointer which points to a reference
void swap4(int*& a, int*& b) {
	int* temp;
	temp = a;
	a = b;
	b = temp;
}

void swap5(int*& a, int*& b) {
	int* temp;
	temp = a;
	a = b;
	b = temp;
}

int main() {
	int left = 10, right = 20;

	cout << "before swap1:\n"
		<< "left = " << left << ", right = " << right << ", &left = " << &left << ", &right = " << &right << endl;
	swap1(left, right);
	cout << "after swap1:\n"
		<< "left = " << left << ", right = " << right << ", &left = " << &left << ", &right = " << &right << endl;
	cout << "'info' didnot change, 'add' didnot change, neither the repository nor the cargo changed" << endl;
	cout << "this shows that swap1 does not change the value saved in the address\n" << endl;

	cout << "before swap2:\n"
		<< "left = " << left << ", right = " << right << ", &left = " << &left << ", &right = " << &right << endl;
	swap2(left, right);
	cout << "after swap2:\n"
		<< "left = " << left << ", right = " << right << ", &left = " << &left << ", &right = " << &right << endl;
	cout << "'info' changed, 'add' didnot changem, the repository did not change(they couldnot have been), but the cargo changed" << endl;
	cout << "this shows that swap2 changes the value saved in the address\n" << endl;

	// here if the code is
	// int *l = left;
	// then it is wrong 
	cout << "next we create 2 pointers('ptr') and see what will happen\n" << endl;
	cout << "notice that the name 'pointer' or 'ptr' for short is just another concept we define for a special repository\n"
		"this kind of repository also has its own address('add') in the real world, with cargo within it\n"
		"what should be notice here is that the cargo is and only is an address with type announcement\n" << endl;

	int* l = &left;
	cout << "l = " << l << ", &l = " << &l << "*l = " << *l 
		<< ", left = " << left << ", &left = " << &left << endl;
	int* r = &right;
	cout << "r = " << r << ", &r = " << &r << "*r = " << *r 
		<< ", right = " << right << ", &right = " << &right << endl;
	cout << "this shows that: if in the address 'add' saves 'info', then for a 'ptr' which points to the 'info'\n"
		"the 'info' of the 'ptr' is the 'add' of the previous 'info'\n" << endl;

	int& lrefer = left;
	cout << "lrefer = " << lrefer << ", &lrefer = " << &lrefer << endl;
	int& rrefer = right;
	cout << "rrefer = " << rrefer << ", &rrefer = " << &rrefer << endl;
	cout << "this shows the 'ref' of something is actually the thing itself, just a difference in the name, they are the same\n"
		"this also remind us we CANNOT use a 'ptr' to point a reference, because it does not have an actual address\n" << endl;

	cout << "before swap3:\n"
		<< "left = " << left << ", right = " << right << ", &left = " << &left << ", &right = " << &right << endl;
	swap3(l, r);
	cout << "after swap3:\n"
		<< "left = " << left << ", right = " << right << ", &left = " << &left << ", &right = " << &right << endl;
	cout << "this, again, shows that swap1 does not change the value saved in the address\n" << endl;

	cout << "before swap4:\n" 
		<< "left = " << left << ", right = " << right << ", &left = " << &left << ", &right = " << &right
		<< "\nl = " << l << ", r = " << r << ", &l = " << &l << ", &r = " << &r << ", *l = " << *l << ", *r = " << *r << endl;
	swap4(l, r);
	cout << "after swap4:\n" 
		<< "left = " << left << ", right = " << right << ", &left = " << &left << ", &right = " << &right
		<< "\nl = " << l << ", r = " << r << ", &l = " << &l << ", &r = " << &r << ", *l = " << *l << ", *r = " << *r << endl;
	cout << "this shows that swap4 swaped the ptrs 'l' and 'r', now, they are pointing to different things\n"
		"however, what they are pointing did not change" << endl;
}