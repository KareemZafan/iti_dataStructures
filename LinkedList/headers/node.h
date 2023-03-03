#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED



template<class T>

class Node
{

public:

    T data;
    Node<T> *prev, *next;

    Node(T data)
    {
        this -> data = data;
        prev = next = NULL;
    }

protected:

private:
};
#endif // NODE_H_INCLUDED
