#include<iostream>
#include<forward_list>
using namespace std;

int main()
{
	forward_list<int> list_1;
	forward_list<int> list_2;

	forward_list<int>::iterator itr;
	forward_list<int>::iterator itr1;

	// Assigning values to the list using assign() function
	list_1.assign({5, 4, 7});

	// Pushing 3 elements with value 40
	list_2.assign(3,4);

	// here begin indicates the starting of list and end represents ending of the list .
	cout << "The elements of first forward list are : ";
	for (itr=list_1.begin();itr!=list_1.end();itr++)
		cout << (*itr) << " ";
	cout << "\n";
	
	cout << "The elements of second forward list are : ";
	for (itr=list_2.begin();itr!=list_2.end();itr++)
		cout << (*itr) << " ";
	cout << "\n";

	// Pushing the element in front of the list
	list_1.push_front(0);

	cout<<"List1 After the push_front function : ";
	for (itr=list_1.begin();itr!=list_1.end();itr++)
		cout << (*itr) << " ";
	cout << "\n";

	// It also Pushing element in front of list but in efficient way . 
	list_1.emplace_front(-1);

	cout<<"List1 After the emplace_front function : ";
	for (itr=list_1.begin();itr!=list_1.end();itr++)
		cout << (*itr) << " ";
	cout << "\n";

	// It is used when we have to delete the front element of list .
	list_1.pop_front();

	cout<<"List1 After the pop_front function : ";
	for (itr=list_1.begin();itr!=list_1.end();itr++)
		cout << (*itr) << " ";
	cout << "\n";

	// Pushing element after any specific position 
	itr1 =  list_2.insert_after(list_2.begin(), {30, 20, 10});
    cout<<"List2 After the insert_After function : ";
	for (itr=list_2.begin();itr!=list_2.end();itr++)
		cout << (*itr) << " ";
	cout << "\n";

	// Pushing element after any specific position but in efficient way.
	itr1 = list_2.emplace_after(itr1,50);
    cout<<"List2 After the emplace_after function : ";
	for (itr=list_2.begin();itr!=list_2.end();itr++)
		cout << (*itr) << " ";
	cout << "\n";

	// Deleting element after the specific position
	itr1 = list_2.erase_after(itr1);
    cout<<"List2 After the erase after function function : ";
	for (itr=list_2.begin();itr!=list_2.end();itr++)
		cout << (*itr) << " ";
	cout << "\n";

	// It removes all occurences of 4 in the list
	list_2.remove(4);
	cout<<"List2 after remove function : ";
	for (itr=list_2.begin();itr!=list_2.end();itr++)
		cout << (*itr) << " ";
	cout << "\n";

	// Removing all occurences which are less than 30
	list_2.remove_if([](int a){ return a<30;});
	cout<<"List2 after remove if function : ";
	for (itr=list_2.begin();itr!=list_2.end();itr++)
		cout << (*itr) << " ";
	cout << "\n";

	// It is shifting all elements from list2 to list1 .
	list_1.splice_after(list_2.begin(),list_1);
	cout<<"List2 After the splice after function : ";
	for (itr=list_2.begin();itr!=list_2.end();itr++)
		cout << (*itr) << " ";
	cout << "\n";

    return 0;
}
