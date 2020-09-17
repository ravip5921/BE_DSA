#include <iostream>

using namespace std;
template<class t>
class Queue
{
  int front;
  int rear;
  const int SIZE;
  t * q;
  bool first,firstD,end;
  
  public:
  Queue(int n):SIZE(n)
  {
      q=new t[SIZE];
      front=0;
      rear=0;
      first =true;
      firstD =true;
      end=false;
  }
  ~Queue()
  {
      delete []q;
  }
  class OVERFLOW{};
  class UNDERFLOW{};
  class QUEUEEND{};
  bool isFull()
  {
      if(rear==SIZE-1)
      {
          throw(OVERFLOW());
          return true;
      }
      return false;
  }
  bool isEmpty()
  {
      if(firstD)
      {
          firstD=false;
          return false;

      }
      if(front==rear && rear==0)
      {
          throw(UNDERFLOW());
          
          return true;
      }
      if(end)
      {
          throw(QUEUEEND());
          return true;
      }
      return false;
  }
  void enqueue(t item)
  {
      
      if(!isFull())
      {
          if(!first)
              rear++;
              q[rear]=item;
              first=false;
            
        cout<<"Rear=" << rear<<endl;
      }
  }
  t dequeue()
  {
      t data;
      if(!isEmpty() || (rear==0))
      {
          data=q[front];
          if(front!=rear)
          {
              front++;
              cout<<"F and R=> "<<front<<rear<<endl;
              end=false;
          }
          else
          {
              end=true;
          }
      }
      return data;
  }
  
};
int main()
{
    int sizeQ;
    cout<<"Enter Queue Size: ";
    cin>>sizeQ;
    Queue<int> a(sizeQ);
    char op;
    int sel,n;
    do
    {
    try
    {
    cout<<"Enter operation: ";
    cin>>sel;
    if(sel==1)
    {
        cout<<"Enter data: ";
        cin>>n;
        a.enqueue(n);
    }
    else if(sel==2)
    {
        cout<<a.dequeue();
    }
    else
    {
        cout<<"Invalid choice!";
    }
    }
    catch(Queue<int>::OVERFLOW)
    {
        cout<<"Queue is full!";
        op=='Y';
    }
    catch(Queue<int>::UNDERFLOW)
    {
        cout<<"Queue is empty!";
        op=='Y';
    }
    catch(Queue<int>::QUEUEEND)
    {
        cout<<"End of the filled Queue has been reached!";
        op=='Y';
    }
    cout<<"\nContinue?:";
    cin>>op;
    }while(toupper(op)=='Y' || op=='1');
    return 0;
}