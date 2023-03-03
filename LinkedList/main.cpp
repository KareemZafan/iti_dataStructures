#include <iostream>
#include "headers/linked_list.h"

using namespace std;

int main()
{
    LinkedList<double> myList ;

    myList.Add(2.5);
    myList.Add(5.6);
    myList.Add(2.5);
    myList.Add(90.6);

    myList.insertAfterIndex(1,3.5);
    myList.insertBeforeIndex(0,500.9);
    myList.insertBeforeIndex(3,50.5);
    myList.insertBeforeIndex(5,50000);



    myList.Display();
    cout<<"\n";
    myList.reverseList();
    myList.Display();

    cout<<"\nList size = "<<myList.getListSize()<<endl;
    cout<<myList.contains(90)<<endl;

    return 0;
}
