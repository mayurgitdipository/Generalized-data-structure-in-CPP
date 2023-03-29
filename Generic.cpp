#include<iostream>
using namespace std;

template<class T>
struct node
{
   T data;
   struct node* next;
   struct node* prev;
};

template <class T>
class SinglyLL
{
   public :
      struct node<T>* First;

      SinglyLL();
      void InsertFirst(T no);
      void InsertLast(T no);
      void InsertAtPos(T no,int iPos);

      void DeleteFirst();
      void DeleteLast();
      void DeleteAtPos(int iPos);

      void Display();
      int Count();
};

template <class T>
SinglyLL<T> :: SinglyLL()
{
   First = NULL;
}

template <class T>
void SinglyLL<T> :: InsertFirst(T no)
{
   struct node<T>* newn = new node<T>;
   newn->data = no;
   newn->next = NULL;

   if(First == NULL)
   {
       First = newn;
   }
   else
   {
      newn->next = First;
      First = newn;
   }
}

template <class T>
void SinglyLL<T> :: InsertLast(T no)
{
   struct node<T>* newn = new node<T>;
   struct node<T>* temp = First;
   newn->data= no;
   newn->next= NULL;

   if(First == NULL)
   {
      First = newn;
   }
   else
   {
      struct node<T>* temp = First;

      while(temp->next != NULL)
      {
         temp = temp->next;
      }
      temp->next = newn;
   }
}

template <class T>
void SinglyLL<T> :: DeleteFirst()
{
   struct node<T>* temp = First;
   if(First == NULL)
   {
      return ;
   }
   else if((First)->next == NULL)
   {
      delete First;
   }
   else
   {
      First = (First)->next;
      delete temp;
   }
}

template <class T>
void SinglyLL<T> :: DeleteLast()
{
   struct node<T>* temp = First;
   if(First == NULL)
   {
      return ;
   }
   else if((First)->next == NULL)
   {
      delete First;
      First = NULL;
   }
   else
   {
      while(temp->next->next!=NULL)
      {
         temp = temp -> next;
      }
      delete temp->next;
      temp->next = NULL;
   }
}

template <class T>
void SinglyLL<T> :: InsertAtPos(T no,int iPos)
{
   struct node<T>* temp = NULL;
   int iNodeCnt=0;
   iNodeCnt = Count();

   if((iPos < 1) && (iPos > iNodeCnt+1))
   {
      printf("Invalid Position");
      return;
   }
   else if(iPos == 1)
   {
      InsertFirst(no);
   }
   else if(iPos == iNodeCnt + 1)
   {
      InsertLast(no);
   }
   else
   {
      struct node<T>* newn = new node<T>;
      newn->data = no;
      newn->next = NULL;
      temp = First;

      for(int iCnt=1;iCnt<iPos-1;iCnt++)
      {
         temp = temp->next;
      }
      newn->next = temp->next;
      temp->next = newn;
   }
}

template <class T>
void SinglyLL<T> :: DeleteAtPos(int iPos)
{
   struct node<T>* temp1 = NULL;
   struct node<T>* temp2 = NULL;
   int iNodeCnt=Count();
   if((iPos < 1) && (iPos > iNodeCnt))
   {
      printf("Invalid Position\n");
      return;
   }
   else if(iPos == 1)
   {
      DeleteFirst();
   }
   else if(iPos == iNodeCnt)
   {
      DeleteLast();
   }
   else
   {
      temp2 = First;
      for(int iCnt=1;iCnt<iPos-1;iCnt++)
      {
         temp2 = temp2->next;
      }
      temp1 = temp2->next;
      temp2->next = temp2->next->next;
      delete temp1;
   }
}

template <class T>
void SinglyLL<T> :: Display()
{
   struct node<T>* temp = First;
   
      while(temp != NULL)
      {
         cout<<"|"<<temp->data<<"|->";
         temp = temp->next;
      }
      
   cout<<"NULL "<<"\n";
}

template <class T>
int SinglyLL<T> :: Count()
{
   struct node<T>* temp = First;
   int iCnt = 0;
   
   
      while(temp != NULL)
      {
         iCnt++;
         temp = temp->next;
      }
   return iCnt;
}




template <class T>
class SinglyCL
{
   public :
      struct node<T>* First;
      struct node<T>* Last;

      SinglyCL();

      void InsertFirst(T no);
      void InsertLast(T no);
      void InsertAtPos(T no,int ipos);

      void DeleteFirst();
      void DeleteLast();
      void DeleteAtPos(int ipos);

      void Display();
      int Count();
};

template <class T>
SinglyCL<T> :: SinglyCL()
{
   First = NULL;
   Last = NULL;
}

template <class T>
void SinglyCL<T> :: InsertFirst(T no)
{
   struct node<T>* newn = new node<T>;
   newn->data= no;
   newn->next= NULL;

   if((First==NULL) && (Last==NULL))
   {
      First = Last = newn;
      (Last)->next = First;
   }
   else
   {
      newn->next= First;
      First= newn;
      (Last)->next= First;
   }
}

template <class T>
void SinglyCL<T> :: InsertLast(T no)
{
   struct node<T>* newn = new node<T>;
   newn->data= no;
   newn->next= NULL;

   if((First == NULL) && (Last == NULL))
   {
      First = Last = NULL;
      (Last)->next = First;
   }  
   else
   {
      (Last)->next = newn;
      Last = newn;
      (Last)->next = First;
   }
}

template <class T>
void SinglyCL<T> :: DeleteFirst()
{
   if((First == NULL) && (Last == NULL))
   {
      return;
   }
   else if(First == Last)
   {
      delete First;
      First = Last = NULL;
   }
   else
   {
      First= (First)->next;
      delete (Last)->next;
      (Last)->next= First;
   }
}

template <class T>
void SinglyCL<T> :: DeleteLast()
{
   struct node<T>* temp= First;
   if((First == NULL) && (Last == NULL))
   {
      return;
   }
   else if(First == Last)
   {
      delete First;
      First = Last = NULL;
   }
   else
   {
      while(temp->next != Last)
      {
         temp = temp->next;
      }
      Last= temp;
      delete temp->next;
      (Last)->next= First;
   }
}

template <class T>
void SinglyCL<T> :: InsertAtPos(T no,int ipos)
{
   int NodeCnt= Count();
   struct node<T>* temp=NULL;
   if((ipos < 1) && (ipos > NodeCnt+1))
   {
      printf("Invalid position\n");
      return;
   }
   else if(ipos == 1)
   {
      InsertFirst(no);
   }
   else if(ipos == NodeCnt+1)
   {
      InsertLast(no);
   }
   else
   {
      struct node<T>* newn= new node<T>;
      newn->data= no;
      newn->next= NULL;
      temp= First;
      for(int iCnt=1;iCnt<ipos-1;iCnt++)
      {
         temp= temp->next;
      }
      newn->next= temp->next;
      temp->next= newn;
   }
}

template <class T>
void SinglyCL<T> :: DeleteAtPos(int ipos)
{
   int NodeCnt=Count();
   struct node<T>* temp1= NULL;
   struct node<T>* temp2= NULL;

   if((ipos < 1) && (ipos > NodeCnt))
   {
      printf("Invalid Position\n");
      return;
   }
   else if(ipos == 1)
   {
      DeleteFirst();
   }
   else if(ipos == NodeCnt)
   {
      DeleteLast();
   }
   else
   {
      temp1= First;
      for(int iCnt=1;iCnt<ipos-1;iCnt++)
      {
         temp1= temp1->next;
      }
      temp2= temp1->next;
      temp1->next= temp1->next->next;
      delete temp2;      
   }
} 

template <class T>
void SinglyCL<T> :: Display()
{
   struct node<T>* temp = First;
   do
   {
      cout<<"|"<<temp->data<<"|->";
      temp= temp->next;
   }while(temp != Last->next);
   cout<<"NULL"<<"\n";
}

template <class T>
int SinglyCL <T>:: Count()
{
   struct node<T>* temp = First;
   int iCnt=0;
   do 
   {
      iCnt++;
      temp= temp->next;
   }while(temp != Last->next);
   return iCnt;
}




template <class T>
class DoublyLL
{
   public :
      struct node<T>* First;

      DoublyLL();

      void InsertFirst(T no);
      void InsertLast(T no);
      void InsertAtPos(T no,int ipos);

      void DeleteAtPos(int ipos);
      void DeleteFirst();
      void DeleteLast();

      void Display();
      int Count();

};

template <class T>
DoublyLL<T> :: DoublyLL()
{
   First = NULL;
}

template <class T>
void DoublyLL<T> :: InsertFirst(T no)
{
   struct node<T>* newn = new node<T>;
   newn->data = no;
   newn->next = NULL;
   newn->prev = NULL;

   if(First == NULL)
   {
      First = newn;
   }
   else
   {
      newn->next = First;
      First = newn;
   }
}

template <class T>
void DoublyLL<T> :: InsertLast(T no)
{
   struct node<T>* newn = new node<T>;
   newn->data= no;
   newn->next= NULL;
   newn->prev= NULL;
   struct node<T>* temp = First;

   if(First == NULL)
   {
      First = newn;
   }
   else
   {
      while(temp->next != NULL)
      {
         temp= temp->next;
      }
      temp->next= newn;
      newn->prev= temp;
   }
}

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
   if(First == NULL)
   {
      return;
   }
   else if((First)->next == NULL)
   {
      delete First;
      First = NULL;
   }
   else
   {
      First = (First)->next;
      delete (First)->prev;
      (First)->prev= NULL;
   }
}

template <class T>
void DoublyLL<T> :: DeleteLast()
{
   if(First == NULL)
   {
      return;
   }
   else if((First)->next == NULL)
   {
      delete First;
      First = NULL;
   }
   else
   {
      struct node<T>* temp= First;
      while(temp->next->next != NULL)
      {
         temp = temp->next;
      }
      temp->next->prev= NULL;
      delete temp->next;
      temp->next = NULL;
   }
}

template <class T>
void DoublyLL<T> :: InsertAtPos(T no,int ipos)
{
   int iNodeCnt=0;
   iNodeCnt= Count();
   struct node<T>* temp = NULL;

   if((ipos < 1) && (ipos > iNodeCnt+1))
   {
      cout<<"Invalid Position"<<"\n";
      return;
   }
   else if(ipos == 1)
   {
      InsertFirst(no);
   }
   else if(ipos == iNodeCnt+1)
   {
      InsertLast(no);
   }
   else
   {
      struct node<T>* newn = new node<T>;
      newn->data= no;
      newn->next= NULL;
      newn->prev= NULL;
      temp = First;
      for(int iCnt=1;iCnt<ipos-1;iCnt++)
      {
         temp = temp->next;
      }
      newn->next= temp->next;
      temp->next= newn;
      newn->prev= temp;
      newn->next->prev= newn;
   }
}

template <class T>
void DoublyLL<T> :: DeleteAtPos(int ipos)
{
   int iNodeCnt = 0;
   iNodeCnt= Count();
   struct node<T>* temp1= NULL;
   struct node<T>* temp2= NULL;

   if((ipos < 1) && (ipos > iNodeCnt))
   {
      cout<<"Invalid Position"<<"\n";
      return;
   }
   else if(ipos ==1)
   {
      DeleteFirst();
   }
   else if(ipos == iNodeCnt)
   {
      DeleteLast();
   }
   else
   {
      temp1= First;
      for(int iCnt=1;iCnt<ipos-1;iCnt++)
      {
         temp1= temp1->next;
      }
      temp2= temp1->next;
      temp1->next= temp1->next->next;
      delete temp2;
      temp1->next->prev= temp1;
   }
}

template <class T>
void DoublyLL<T> :: Display()
{
   struct node<T>* temp = First;
   while(temp != NULL)
   {
      cout<<"|"<<temp->data<<"|->";
      temp = (temp)->next;
   }
   cout<<"NULL"<<"\n";
}

template <class T>
int DoublyLL<T> :: Count()
{
   struct node<T>* temp = First;
   int iCnt=0;
   while(temp != NULL)
   {
      iCnt++;
      temp = temp->next;
   }
   return iCnt;
}




template<class T>
class DoublyCL
{
   public :
      struct node<T>* First;
      struct node<T>* Last;

      DoublyCL();

      void InsertFirst(T no);
      void InsertLast(T no);
      void InsertAtPos(T no,int ipos);

      void DeleteFirst();
      void DeleteLast();
      void DeleteAtPos(int ipos);

      void Display();
      int Count();
};

template<class T>
DoublyCL<T> :: DoublyCL()
{
   First = NULL;
   Last = NULL;
}

template<class T>
void DoublyCL<T> :: InsertFirst(T no)
{
   struct node<T>* newn = new node<T>;
   newn->data= no;
   newn->next= NULL;
   newn->prev= NULL;

   if((First == NULL) && (Last == NULL))
   {
      First = Last = newn;
      (First)->prev = Last;
      (Last)->next = First;
   }
   else
   {
      newn->next = First;
      (First)->prev = newn;
      First = newn;
      (Last)->next = First;
   }
}

template<class T>
void DoublyCL<T> :: InsertLast(T no)
{
   struct node<T>* newn= new node<T>;
   newn->data= no;
   newn->next= NULL;
   newn->prev= NULL;

   if((First == NULL) && (Last == NULL))
   {
      First = Last = newn;
      (First)->prev = newn;
      (Last)->next = First;
   }
   else
   {
      (Last)->next=newn;
      (Last)->next->prev= Last;
      Last = newn;
      (Last)->next= First;
   }
}

template<class T>
void DoublyCL<T> :: DeleteFirst()
{
   if((First == NULL) && (Last == NULL))
   {
      return;
   }
   else if(First == Last)
   {
      delete First;
      First = Last = NULL;
   }
   else
   {
      First = (First)->next;
      delete (Last)->next;
      (Last)->next = First;
   }
}

template<class T>
void DoublyCL<T> :: DeleteLast()
{
   if((First == NULL) && (Last == NULL))
   {
      return;
   }
   else if(First == Last)
   {
      delete First;
      First = Last = NULL;
   }
   else
   {
      Last = (Last)->prev;
      delete First->prev;
      (First)->prev = Last;
      (Last)->next = First;
   }
}

template<class T>
void DoublyCL<T> :: InsertAtPos(T no,int ipos)
{
   int NodeCnt=Count();
   struct node<T>* temp= NULL;

   if((ipos < 1) && (ipos > NodeCnt+1))
   {
      cout<<"Invalid Position"<<"\n";
      return;
   }
   else if(ipos ==1)
   {
      InsertFirst(no);
   }
   else if(ipos == NodeCnt+1)
   {
      InsertLast(no);
   }
   else
   {
      temp = First;
      struct node<T>* newn = new node<T>;
      newn->data = no;
      newn->next = NULL;
      newn->prev = NULL;
      for(int iCnt=1;iCnt<ipos-1;iCnt++)
      {
         temp = temp->next;
      }
      newn->next = temp->next;
      temp->next = newn;
      newn->prev = temp;
      newn->next->prev = newn;
   }
}

template<class T>
void DoublyCL<T> :: DeleteAtPos(int ipos)
{
   int NodeCnt=Count();
   struct node<T>* temp1= NULL;
   struct node<T>* temp2= NULL;

   if((ipos < 1) && (ipos > NodeCnt+1))
   {
      cout<<"Invalid Position"<<"\n";
      return;
   }
   else if(ipos ==1)
   {
      DeleteFirst();
   }
   else if(ipos == NodeCnt)
   {
      DeleteLast();
   }
   else
   {
      int iCnt=0;
      temp1 = First;

      for(iCnt = 1 ; iCnt < ipos-1 ; iCnt++)
      {
         temp1 = temp1 -> next;
      }
      temp2 = temp1->next;
      temp1->next = temp2->next;
      temp2->next->prev = temp1;
      delete temp2;
   }
}

template<class T>
void DoublyCL<T> :: Display()
{
   struct node<T>* temp = First;
   do
   {
      cout<<"|"<<temp->data<<"|->";
      temp = temp->next;
   } while (temp != (Last)->next);
   cout<<"NULL"<<"\n";
}

template<class T>
int DoublyCL<T> :: Count()
{
   struct node<T>* temp = First;
   int iCnt=0;
   do
   {
      iCnt++;
      temp = temp->next;
   } while (temp != (Last)->next);
   return iCnt;
}


template <class T>
class Stack
{  
   public:
      struct node<T>* First;

      Stack();

      void Push(T no);
      void Pop();
      void Display();
      int Count();
      
};

template <class T>
Stack<T> :: Stack()
{
   First = NULL;
}

template <class T>
void Stack<T> :: Push(T no)
{
   struct node<T>* newn = new node<T>;
   newn->data = no;
   newn->next = NULL;

   if(First == NULL)
   {
      First = newn;
   }
   else
   {
      newn->next = First;
      First = newn;
   }
   cout<< no <<" is Pushed Successfully "<<"\n";
}

template <class T>
void Stack<T> :: Pop()
{
   T iValue=0;
   if(First == NULL)
   {
      printf("Stack is empty\n");
   }
   else if((First)->next == NULL)
   {
      iValue = (First)->data;
      free (First);
      First = NULL;
   }
   else
   {
      iValue = (First)->data;
      struct node<T>* temp = First;
      First = (First)->next;
      free(temp);
   }
   cout<< iValue <<" Is Popped successfully"<<"\n";
}

template <class T>
void Stack<T> :: Display()
{
   struct node<T>* temp = First;
   while(temp != NULL)
   {
      cout<<"|"<<temp->data<<"|->";
      temp = temp->next;
   }
   cout<<"NULL"<<"\n";
}

template <class T>
int Stack<T> :: Count()
{
   int iCnt=0;
   struct node<T>* temp = First;
   while(temp != NULL)
   {
      iCnt++;
      temp = temp->next;
   }
   return iCnt;
}


template <class T>
class Queue
{
   public :
      struct node<T>* First;

      Queue();

      void EnQueue(T no);
      void DeQueue();
      void Display();
      int Count();
};

template <class T>
Queue<T> :: Queue()
{
   First = NULL;
}

template <class T>
void Queue<T> :: EnQueue(T no)
{
   struct node<T>* newn= new node<T>;
   newn->data = no;
   newn->next = NULL;

   if(First == NULL)
   {
      First = newn;
   }
   else
   {
      struct node<T>* temp = First;
      while(temp->next != NULL)
      {
         temp = temp->next;
      }
      temp->next = newn;
   }
   cout<<no<<" is Added Successfully in Queue "<<"\n";
}

template <class T>
void Queue<T> :: DeQueue()
{
   T iValue = 0;
   if(First == NULL)
   {
      cout<<"Queue is Empty"<<"\n";
   }
   else if((First)->next == NULL)
   {
      iValue = (First)->data;
      delete First;
      First = NULL;
   }
   else
   {
      iValue = (First)->data;
      struct node<T>* temp = First;
      First = (First)->next;
      delete temp;
   }
   cout<<iValue<<" is Successfully Removed from Queue "<<"\n";
}

template <class T>
void Queue<T> :: Display()
{
   struct node<T>* temp = First;
   while(temp != NULL)
   {
      cout<<"|"<<temp->data<<"|->";
      temp = temp->next;
   }
   cout<<"NULL"<<"\n";
}

template <class T>
int Queue<T> :: Count()
{
   struct node<T>* temp = First;
   int iCnt=0;
   while(temp != NULL)
   {
      iCnt++;
      temp = temp->next;
   }
   return iCnt;
}




int main()
{
   cout<<"------------------------------------------------------------------------------------------------------------------------"<<"\n";
   cout<<"                                             SINGLY LINEAR LINKED LIST                                                  "<<"\n";

   int iRet=0;
   SinglyLL <int>aiobj;
   aiobj.InsertFirst(21);
   aiobj.InsertFirst(11);
   aiobj.Display();
   iRet = aiobj.Count();
   cout<<" InsertFirst Nodes in the Linklist are:"<<iRet<<"\n";

   aiobj.InsertLast(111);
   aiobj.InsertLast(121);
   aiobj.Display();
   iRet = aiobj.Count();
   cout<<" InsertLast Nodes in the Linklist are:"<<iRet<<"\n";

   aiobj.InsertAtPos(105,3);
   aiobj.Display();
   iRet = aiobj.Count();
   cout<<"InsertAtPos Nodes in the Linklist are:"<<iRet<<"\n";

   aiobj.DeleteAtPos(3);
   aiobj.Display();
   iRet = aiobj.Count();
   cout<<"DeleteAtPos Nodes in the Linklist are:"<<iRet<<"\n";
   
   aiobj.DeleteFirst();
   aiobj.Display();
   iRet = aiobj.Count();
   cout<<"DeleteFirst Nodes in the Linklist are:"<<iRet<<"\n";

   aiobj.DeleteLast();
   aiobj.Display();
   iRet = aiobj.Count();
   cout<<"DeleteLast Nodes in the Linklist are:"<<iRet<<"\n";


   SinglyLL <char>acobj;
   acobj.InsertFirst('B');
   acobj.InsertFirst('A');
   acobj.Display();
   iRet = acobj.Count();
   cout<<" InsertFirst Nodes in the Linklist are:"<<iRet<<"\n";

   acobj.InsertLast('C');
   acobj.InsertLast('D');
   acobj.Display();
   iRet = acobj.Count();
   cout<<" InsertLast Nodes in the Linklist are:"<<iRet<<"\n";

   acobj.InsertAtPos('P',3);
   acobj.Display();
   iRet = acobj.Count();
   cout<<"InsertAtPos Nodes in the Linklist are:"<<iRet<<"\n";

   acobj.DeleteAtPos(3);
   acobj.Display();
   iRet = acobj.Count();
   cout<<"DeleteAtPos Nodes in the Linklist are:"<<iRet<<"\n";
   
   acobj.DeleteFirst();
   acobj.Display();
   iRet = acobj.Count();
   cout<<"DeleteFirst Nodes in the Linklist are:"<<iRet<<"\n";

   acobj.DeleteLast();
   acobj.Display();
   iRet = acobj.Count();
   cout<<"DeleteLast Nodes in the Linklist are:"<<iRet<<"\n";


   SinglyLL <float>afobj;
   afobj.InsertFirst(21.21f);
   afobj.InsertFirst(11.11f);
   afobj.Display();
   iRet = afobj.Count();
   cout<<" InsertFirst Nodes in the Linklist are:"<<iRet<<"\n";

   afobj.InsertLast(51.51f);
   afobj.InsertLast(101.11f);
   afobj.Display();
   iRet = afobj.Count();
   cout<<" InsertLast Nodes in the Linklist are:"<<iRet<<"\n";

   afobj.InsertAtPos(75.75f,3);
   afobj.Display();
   iRet = afobj.Count();
   cout<<"InsertAtPos Nodes in the Linklist are:"<<iRet<<"\n";

   afobj.DeleteAtPos(3);
   afobj.Display();
   iRet = afobj.Count();
   cout<<"DeleteAtPos Nodes in the Linklist are:"<<iRet<<"\n";
   
   afobj.DeleteFirst();
   afobj.Display();
   iRet = afobj.Count();
   cout<<"DeleteFirst Nodes in the Linklist are:"<<iRet<<"\n";

   afobj.DeleteLast();
   afobj.Display();
   iRet = afobj.Count();
   cout<<"DeleteLast Nodes in the Linklist are:"<<iRet<<"\n";


   SinglyLL <double>adobj;
   adobj.InsertFirst(22.222);
   adobj.InsertFirst(11.111);
   adobj.Display();
   iRet = adobj.Count();
   cout<<" InsertFirst Nodes in the Linklist are:"<<iRet<<"\n";

   adobj.InsertLast(33.333);
   adobj.InsertLast(44.444);
   adobj.Display();
   iRet = adobj.Count();
   cout<<" InsertLast Nodes in the Linklist are:"<<iRet<<"\n";

   adobj.InsertAtPos(55.555,3);
   adobj.Display();
   iRet = adobj.Count();
   cout<<"InsertAtPos Nodes in the Linklist are:"<<iRet<<"\n";

   adobj.DeleteAtPos(3);
   adobj.Display();
   iRet = adobj.Count();
   cout<<"DeleteAtPos Nodes in the Linklist are:"<<iRet<<"\n";
   
   adobj.DeleteFirst();
   adobj.Display();
   iRet = adobj.Count();
   cout<<"DeleteFirst Nodes in the Linklist are:"<<iRet<<"\n";

   adobj.DeleteLast();
   adobj.Display();
   iRet = adobj.Count();
   cout<<"DeleteLast Nodes in the Linklist are:"<<iRet<<"\n";

   cout<<"------------------------------------------------------------------------------------------------------------------------"<<"\n";
   cout<<"                                             SINGLY CIRCULAR LINKED LIST                                              "<<"\n";

   SinglyCL <int>biobj;
   biobj.InsertFirst(21);
   biobj.InsertFirst(11);
   biobj.Display();
   iRet = biobj.Count();
   cout<<" InsertFirst Nodes in the Linklist are:"<<iRet<<"\n";

   biobj.InsertLast(111);
   biobj.InsertLast(121);
   biobj.Display();
   iRet = biobj.Count();
   cout<<" InsertLast Nodes in the Linklist are:"<<iRet<<"\n";

   biobj.InsertAtPos(105,3);
   biobj.Display();
   iRet = biobj.Count();
   cout<<"InsertAtPos Nodes in the Linklist are:"<<iRet<<"\n";

   biobj.DeleteAtPos(3);
   biobj.Display();
   iRet = biobj.Count();
   cout<<"DeleteAtPos Nodes in the Linklist are:"<<iRet<<"\n";
   
   biobj.DeleteFirst();
   biobj.Display();
   iRet = biobj.Count();
   cout<<"DeleteFirst Nodes in the Linklist are:"<<iRet<<"\n";

   biobj.DeleteLast();
   biobj.Display();
   iRet = biobj.Count();
   cout<<"DeleteLast Nodes in the Linklist are:"<<iRet<<"\n";


   SinglyCL <char>bcobj;
   bcobj.InsertFirst('B');
   bcobj.InsertFirst('A');
   bcobj.Display();
   iRet = bcobj.Count();
   cout<<" InsertFirst Nodes in the Linklist are:"<<iRet<<"\n";

   bcobj.InsertLast('C');
   bcobj.InsertLast('D');
   bcobj.Display();
   iRet = bcobj.Count();
   cout<<" InsertLast Nodes in the Linklist are:"<<iRet<<"\n";

   bcobj.InsertAtPos('P',3);
   bcobj.Display();
   iRet = bcobj.Count();
   cout<<"InsertAtPos Nodes in the Linklist are:"<<iRet<<"\n";

   bcobj.DeleteAtPos(3);
   bcobj.Display();
   iRet = bcobj.Count();
   cout<<"DeleteAtPos Nodes in the Linklist are:"<<iRet<<"\n";
   
   bcobj.DeleteFirst();
   bcobj.Display();
   iRet = bcobj.Count();
   cout<<"DeleteFirst Nodes in the Linklist are:"<<iRet<<"\n";

   bcobj.DeleteLast();
   bcobj.Display();
   iRet = bcobj.Count();
   cout<<"DeleteLast Nodes in the Linklist are:"<<iRet<<"\n";


   SinglyCL <float>bfobj;
   bfobj.InsertFirst(21.21f);
   bfobj.InsertFirst(11.11f);
   bfobj.Display();
   iRet = bfobj.Count();
   cout<<" InsertFirst Nodes in the Linklist are:"<<iRet<<"\n";

   bfobj.InsertLast(51.51f);
   bfobj.InsertLast(101.11f);
   bfobj.Display();
   iRet = bfobj.Count();
   cout<<" InsertLast Nodes in the Linklist are:"<<iRet<<"\n";

   bfobj.InsertAtPos(75.75f,3);
   bfobj.Display();
   iRet = bfobj.Count();
   cout<<"InsertAtPos Nodes in the Linklist are:"<<iRet<<"\n";

   bfobj.DeleteAtPos(3);
   bfobj.Display();
   iRet = bfobj.Count();
   cout<<"DeleteAtPos Nodes in the Linklist are:"<<iRet<<"\n";
   
   bfobj.DeleteFirst();
   bfobj.Display();
   iRet = bfobj.Count();
   cout<<"DeleteFirst Nodes in the Linklist are:"<<iRet<<"\n";

   bfobj.DeleteLast();
   bfobj.Display();
   iRet = bfobj.Count();
   cout<<"DeleteLast Nodes in the Linklist are:"<<iRet<<"\n";


   SinglyCL <double>bdobj;
   bdobj.InsertFirst(22.222);
   bdobj.InsertFirst(11.111);
   bdobj.Display();
   iRet = bdobj.Count();
   cout<<" InsertFirst Nodes in the Linklist are:"<<iRet<<"\n";

   bdobj.InsertLast(33.333);
   bdobj.InsertLast(44.444);
   bdobj.Display();
   iRet = bdobj.Count();
   cout<<" InsertLast Nodes in the Linklist are:"<<iRet<<"\n";

   bdobj.InsertAtPos(55.555,3);
   bdobj.Display();
   iRet = bdobj.Count();
   cout<<"InsertAtPos Nodes in the Linklist are:"<<iRet<<"\n";

   bdobj.DeleteAtPos(3);
   bdobj.Display();
   iRet = bdobj.Count();
   cout<<"DeleteAtPos Nodes in the Linklist are:"<<iRet<<"\n";
   
   bdobj.DeleteFirst();
   bdobj.Display();
   iRet = bdobj.Count();
   cout<<"DeleteFirst Nodes in the Linklist are:"<<iRet<<"\n";

   bdobj.DeleteLast();
   bdobj.Display();
   iRet = bdobj.Count();
   cout<<"DeleteLast Nodes in the Linklist are:"<<iRet<<"\n";

   cout<<"-----------------------------------------------------------------------------------------------------------------------"<<"\n";
   cout<<"                                           DOUBLY LINEAR LINKED LIST                                                   "<<"\n";

   DoublyLL <int>ciobj;
   ciobj.InsertFirst(21);
   ciobj.InsertFirst(11);
   ciobj.Display();
   iRet = ciobj.Count();
   cout<<" InsertFirst Nodes in the Linklist are:"<<iRet<<"\n";

   ciobj.InsertLast(111);
   ciobj.InsertLast(121);
   ciobj.Display();
   iRet = ciobj.Count();
   cout<<" InsertLast Nodes in the Linklist are:"<<iRet<<"\n";

   ciobj.InsertAtPos(105,3);
   ciobj.Display();
   iRet = ciobj.Count();
   cout<<"InsertAtPos Nodes in the Linklist are:"<<iRet<<"\n";

   ciobj.DeleteAtPos(3);
   ciobj.Display();
   iRet = ciobj.Count();
   cout<<"DeleteAtPos Nodes in the Linklist are:"<<iRet<<"\n";
   
   ciobj.DeleteFirst();
   ciobj.Display();
   iRet = ciobj.Count();
   cout<<"DeleteFirst Nodes in the Linklist are:"<<iRet<<"\n";

   ciobj.DeleteLast();
   ciobj.Display();
   iRet = ciobj.Count();
   cout<<"DeleteLast Nodes in the Linklist are:"<<iRet<<"\n";


   DoublyLL <char>ccobj;
   ccobj.InsertFirst('B');
   ccobj.InsertFirst('A');
   ccobj.Display();
   iRet = ccobj.Count();
   cout<<" InsertFirst Nodes in the Linklist are:"<<iRet<<"\n";

   ccobj.InsertLast('C');
   ccobj.InsertLast('D');
   ccobj.Display();
   iRet = ccobj.Count();
   cout<<" InsertLast Nodes in the Linklist are:"<<iRet<<"\n";

   ccobj.InsertAtPos('P',3);
   ccobj.Display();
   iRet = ccobj.Count();
   cout<<"InsertAtPos Nodes in the Linklist are:"<<iRet<<"\n";

   ccobj.DeleteAtPos(3);
   ccobj.Display();
   iRet = ccobj.Count();
   cout<<"DeleteAtPos Nodes in the Linklist are:"<<iRet<<"\n";
   
   ccobj.DeleteFirst();
   ccobj.Display();
   iRet = ccobj.Count();
   cout<<"DeleteFirst Nodes in the Linklist are:"<<iRet<<"\n";

   ccobj.DeleteLast();
   ccobj.Display();
   iRet = ccobj.Count();
   cout<<"DeleteLast Nodes in the Linklist are:"<<iRet<<"\n";


   DoublyLL <float>cfobj;
   cfobj.InsertFirst(21.21f);
   cfobj.InsertFirst(11.11f);
   cfobj.Display();
   iRet = cfobj.Count();
   cout<<" InsertFirst Nodes in the Linklist are:"<<iRet<<"\n";

   cfobj.InsertLast(51.51f);
   cfobj.InsertLast(101.11f);
   cfobj.Display();
   iRet = cfobj.Count();
   cout<<" InsertLast Nodes in the Linklist are:"<<iRet<<"\n";

   cfobj.InsertAtPos(75.75f,3);
   cfobj.Display();
   iRet = cfobj.Count();
   cout<<"InsertAtPos Nodes in the Linklist are:"<<iRet<<"\n";

   cfobj.DeleteAtPos(3);
   cfobj.Display();
   iRet = cfobj.Count();
   cout<<"DeleteAtPos Nodes in the Linklist are:"<<iRet<<"\n";
   
   cfobj.DeleteFirst();
   cfobj.Display();
   iRet = cfobj.Count();
   cout<<"DeleteFirst Nodes in the Linklist are:"<<iRet<<"\n";

   cfobj.DeleteLast();
   cfobj.Display();
   iRet = cfobj.Count();
   cout<<"DeleteLast Nodes in the Linklist are:"<<iRet<<"\n";


   DoublyLL <double>cdobj;
   cdobj.InsertFirst(22.222);
   cdobj.InsertFirst(11.111);
   cdobj.Display();
   iRet = cdobj.Count();
   cout<<" InsertFirst Nodes in the Linklist are:"<<iRet<<"\n";

   cdobj.InsertLast(33.333);
   cdobj.InsertLast(44.444);
   cdobj.Display();
   iRet = cdobj.Count();
   cout<<" InsertLast Nodes in the Linklist are:"<<iRet<<"\n";

   cdobj.InsertAtPos(55.555,3);
   cdobj.Display();
   iRet = cdobj.Count();
   cout<<"InsertAtPos Nodes in the Linklist are:"<<iRet<<"\n";

   cdobj.DeleteAtPos(3);
   cdobj.Display();
   iRet = cdobj.Count();
   cout<<"DeleteAtPos Nodes in the Linklist are:"<<iRet<<"\n";
   
   cdobj.DeleteFirst();
   cdobj.Display();
   iRet = cdobj.Count();
   cout<<"DeleteFirst Nodes in the Linklist are:"<<iRet<<"\n";

   cdobj.DeleteLast();
   cdobj.Display();
   iRet = cdobj.Count();
   cout<<"DeleteLast Nodes in the Linklist are:"<<iRet<<"\n";

   cout<<"-----------------------------------------------------------------------------------------------------------------------"<<"\n";
   cout<<"                                          DOUBLY CIRCULAR LINKED LIST                                                   "<<"\n";

   DoublyCL <int>diobj;
   diobj.InsertFirst(21);
   diobj.InsertFirst(11);
   diobj.Display();
   iRet = diobj.Count();
   cout<<" InsertFirst Nodes in the Linklist are:"<<iRet<<"\n";

   diobj.InsertLast(111);
   diobj.InsertLast(121);
   diobj.Display();
   iRet = diobj.Count();
   cout<<" InsertLast Nodes in the Linklist are:"<<iRet<<"\n";

   diobj.InsertAtPos(105,3);
   diobj.Display();
   iRet = diobj.Count();
   cout<<"InsertAtPos Nodes in the Linklist are:"<<iRet<<"\n";

   diobj.DeleteAtPos(3);
   diobj.Display();
   iRet = diobj.Count();
   cout<<"DeleteAtPos Nodes in the Linklist are:"<<iRet<<"\n";
   
   diobj.DeleteFirst();
   diobj.Display();
   iRet = diobj.Count();
   cout<<"DeleteFirst Nodes in the Linklist are:"<<iRet<<"\n";

   diobj.DeleteLast();
   diobj.Display();
   iRet = diobj.Count();
   cout<<"DeleteLast Nodes in the Linklist are:"<<iRet<<"\n";


   DoublyCL <char>dcobj;
   dcobj.InsertFirst('B');
   dcobj.InsertFirst('A');
   dcobj.Display();
   iRet = dcobj.Count();
   cout<<" InsertFirst Nodes in the Linklist are:"<<iRet<<"\n";

   dcobj.InsertLast('C');
   dcobj.InsertLast('D');
   dcobj.Display();
   iRet = dcobj.Count();
   cout<<" InsertLast Nodes in the Linklist are:"<<iRet<<"\n";

   dcobj.InsertAtPos('P',3);
   dcobj.Display();
   iRet = dcobj.Count();
   cout<<"InsertAtPos Nodes in the Linklist are:"<<iRet<<"\n";

   dcobj.DeleteAtPos(3);
   dcobj.Display();
   iRet = dcobj.Count();
   cout<<"DeleteAtPos Nodes in the Linklist are:"<<iRet<<"\n";
   
   dcobj.DeleteFirst();
   dcobj.Display();
   iRet = dcobj.Count();
   cout<<"DeleteFirst Nodes in the Linklist are:"<<iRet<<"\n";

   dcobj.DeleteLast();
   dcobj.Display();
   iRet = dcobj.Count();
   cout<<"DeleteLast Nodes in the Linklist are:"<<iRet<<"\n";


   DoublyCL <float>dfobj;
   dfobj.InsertFirst(21.21f);
   dfobj.InsertFirst(11.11f);
   dfobj.Display();
   iRet = dfobj.Count();
   cout<<" InsertFirst Nodes in the Linklist are:"<<iRet<<"\n";

   dfobj.InsertLast(51.51f);
   dfobj.InsertLast(101.11f);
   dfobj.Display();
   iRet = dfobj.Count();
   cout<<" InsertLast Nodes in the Linklist are:"<<iRet<<"\n";

   dfobj.InsertAtPos(75.75f,3);
   dfobj.Display();
   iRet = dfobj.Count();
   cout<<"InsertAtPos Nodes in the Linklist are:"<<iRet<<"\n";

   dfobj.DeleteAtPos(3);
   dfobj.Display();
   iRet = dfobj.Count();
   cout<<"DeleteAtPos Nodes in the Linklist are:"<<iRet<<"\n";
   
   dfobj.DeleteFirst();
   dfobj.Display();
   iRet = dfobj.Count();
   cout<<"DeleteFirst Nodes in the Linklist are:"<<iRet<<"\n";

   dfobj.DeleteLast();
   dfobj.Display();
   iRet = dfobj.Count();
   cout<<"DeleteLast Nodes in the Linklist are:"<<iRet<<"\n";


   DoublyCL <double>ddobj;
   ddobj.InsertFirst(22.222);
   ddobj.InsertFirst(11.111);
   ddobj.Display();
   iRet = ddobj.Count();
   cout<<" InsertFirst Nodes in the Linklist are:"<<iRet<<"\n";

   ddobj.InsertLast(33.333);
   ddobj.InsertLast(44.444);
   ddobj.Display();
   iRet = ddobj.Count();
   cout<<" InsertLast Nodes in the Linklist are:"<<iRet<<"\n";

   ddobj.InsertAtPos(55.555,3);
   ddobj.Display();
   iRet = ddobj.Count();
   cout<<"InsertAtPos Nodes in the Linklist are:"<<iRet<<"\n";

   ddobj.DeleteAtPos(3);
   ddobj.Display();
   iRet = ddobj.Count();
   cout<<"DeleteAtPos Nodes in the Linklist are:"<<iRet<<"\n";
   
   ddobj.DeleteFirst();
   ddobj.Display();
   iRet = ddobj.Count();
   cout<<"DeleteFirst Nodes in the Linklist are:"<<iRet<<"\n";

   ddobj.DeleteLast();
   ddobj.Display();
   iRet = ddobj.Count();
   cout<<"DeleteLast Nodes in the Linklist are:"<<iRet<<"\n";

   cout<<"--------------------------------------------------------------------------------------------------------------------"<<"\n";
   cout<<"                                                      Stack                                                        "<<"\n";

   Stack<int>Ssobj;

   Ssobj.Push(51);
   Ssobj.Push(21);
   Ssobj.Push(11);

   Ssobj.Display();
   iRet = Ssobj.Count();
   printf("Nodes in the stack are : %d \n",iRet);

   Ssobj.Pop();

   Ssobj.Display();
   iRet = Ssobj.Count();
   printf("Nodes in the stack are : %d \n",iRet);

   Stack <char>Scobj;
   Scobj.Push('C');
   Scobj.Push('B');
   Scobj.Push('A');

   Scobj.Display();
   iRet = Scobj.Count();
   printf("Nodes in the stack are : %d \n",iRet);

   Scobj.Pop();

   Scobj.Display();
   iRet = Scobj.Count();
   printf("Nodes in the stack are : %d \n",iRet);

   Stack <float>Sfobj;
   Sfobj.Push(51.51f);
   Sfobj.Push(21.21f);
   Sfobj.Push(11.11f);

   Sfobj.Display();
   iRet = Sfobj.Count();
   printf("Nodes in the stack are : %d \n",iRet);

   Sfobj.Pop();

   Sfobj.Display();
   iRet = Sfobj.Count();
   printf("Nodes in the stack are : %d \n",iRet);

   Stack <double>Sdobj;
   Sdobj.Push(51.555);
   Sdobj.Push(21.222);
   Sdobj.Push(11.111);

   Sdobj.Display();
   iRet = Sdobj.Count();
   printf("Nodes in the stack are : %d \n",iRet);

   Sdobj.Pop();

   Sdobj.Display();
   iRet = Sdobj.Count();
   printf("Nodes in the stack are : %d \n",iRet);


   cout<<"----------------------------------------------------------------------------------------------------------------"<<"\n";
   cout<<"                                               Queue                                                            "<<"\n";

   Queue <int>Qiobj;

   Qiobj.EnQueue(11);
   Qiobj.EnQueue(21);
   Qiobj.EnQueue(51);

   Qiobj.Display();
   iRet = Qiobj.Count();
   printf("Nodes in the Queue are : %d \n",iRet);

   Qiobj.DeQueue();

   Qiobj.Display();
   iRet = Qiobj.Count();
   printf("Nodes in the Queue are : %d \n",iRet);

   Queue <char>Qcobj;
   Qcobj.EnQueue('A');
   Qcobj.EnQueue('B');
   Qcobj.EnQueue('C');

   Qcobj.Display();
   iRet = Qcobj.Count();
   printf("Nodes in the Queue are : %d \n",iRet);

   Qcobj.DeQueue();

   Qcobj.Display();
   iRet = Qcobj.Count();
   printf("Nodes in the Queue are : %d \n",iRet);

   Queue <float>Qfobj;
   Qfobj.EnQueue(11.11f);
   Qfobj.EnQueue(21.21f);
   Qfobj.EnQueue(51.51f);

   Qfobj.Display();
   iRet = Qfobj.Count();
   printf("Nodes in the Queue are : %d \n",iRet);

   Qfobj.DeQueue();

   Qfobj.Display();
   iRet = Qfobj.Count();
   printf("Nodes in the Queue are : %d \n",iRet);

   Queue <double>Qdobj;
   Qdobj.EnQueue(11.111);
   Qdobj.EnQueue(21.222);
   Qdobj.EnQueue(51.555);

   Qdobj.Display();
   iRet = Qdobj.Count();
   printf("Nodes in the Queue are : %d \n",iRet);

   Qdobj.DeQueue();

   Qdobj.Display();
   iRet = Qdobj.Count();
   printf("Nodes in the Queue are : %d \n",iRet);


   return 0;
}