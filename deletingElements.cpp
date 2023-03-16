#include<iostream>
#include<list> 
using namespace std;
int main()
{
    list<int> list1={10,15,20,25,30,35};
    cout << "The original list is : ";
    for (list<int>::iterator i=list1.begin(); i!=list1.end(); i++)
       cout << *i << " ";
       
    cout << endl;

    list1.pop_front();

    cout << "The list after deleting first element using pop_front() : ";
    for (list<int>::iterator i=list1.begin(); i!=list1.end(); i++)
       cout << *i << " ";
       
    cout << endl;

    list1.pop_back();

    cout << "The list after deleting last element using pop_back() : ";
    for (list<int>::iterator i=list1.begin(); i!=list1.end(); i++)
       cout << *i << " ";
       
    cout << endl;
      
}
