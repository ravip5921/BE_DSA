#include <iostream>
using namespace std;
template <class t>
struct NODE
{
    t item;
    NODE<t>* next;
};
template <class t>
class StackL
{
    typedef NODE<t> Node;
    int sizeL;
    const int maxSize;
    Node* start;
public:
    class UNDERFLOW{};
    class OVERFLOW{};
    StackL(int s=5):maxSize(s)
    {
        sizeL=0;
        start=nullptr;
    }
    ~StackL()
    {
        if(start!=nullptr)
        {
            Node* p =start;
            Node* q = p->next;
            if(q==nullptr)
                delete p;
            else
            for(;q!=nullptr;p=q,q=q->next)
                delete p;
        }
    }
    int getSize()
    {
        return sizeL;
    }
    void peek()
    {
        if(start==nullptr)
        {
            throw UNDERFLOW();
        }
        cout<<start->item;
    }
    void push(t);
    t pop();
    //void display();
};
template <class t>
void StackL<t>::push(t data)
{
    if(sizeL<maxSize)
    {
        sizeL++;
        Node* newNode = new Node();
        newNode->item=data;
        if(start==nullptr)
        {
            newNode->next=nullptr;
            start=newNode;
        }
        else
        {
            newNode->next=start;
            start=newNode;
        }
    }
    else
    {
        throw OVERFLOW{};
    }

}
template <class t>
t StackL<t>::pop()
{
    if(start==nullptr)
        throw UNDERFLOW();
    sizeL--;
    t temp=start->item;
    start=start->next;
    return temp;
}
/*template <class t>
void StackL<t>::display()
{
    if(start == nullptr)
        throw UNDERFLOW();
    Node<t>* p = start;
    for(; p != nullptr ; p = p->next)
        std::cout<<" "<<p->item;
}*/
int main()
{
    int op,sizeSt,num;
    cout<<"Size of Stack:";
    cin>>num;
    sizeSt=num;
    StackL<int> s(num);
    while(1)
    {
    try
    {
        cout<<"\nEnter Operation:\t1)Push\t2)Pop\t3)Exit:";
        cin>>op;
        if(op==1)
        {
            if(s.getSize()<sizeSt)
            {
                cout<<"\nEnter number to be pushed:";
                cin>>num;
                s.push(num);
                cout<<"\nTop of Stack:\t";
                s.peek();
            }
            else
            {
                throw(StackL<int>::OVERFLOW());
            }
        }
        else if(op==2)
        {
            s.pop();
            cout<<"\nTop of Stack:\t";
            s.peek();
        }
        else
        {
           exit(0);
        }
    }
    catch(StackL<int>::UNDERFLOW)
    {
        cout<<"\nStack is Empty!";
    }
    catch(StackL<int>::OVERFLOW)
    {
        cout<<"\nStack is Full!";
    }
    }
    return 0;
}