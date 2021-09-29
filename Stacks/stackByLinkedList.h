template<class T>
class Stack;

template<class T>
class Node{
      T data;
      Node<T>* next;
      public:
          Node(T d): data(d), next(NULL) {};
          friend class Stack<T>;

};
template<class T>
class Stack
{
    Node<T>* head;

    public:
         Stack() {
             head= NULL;
         }
         void push(T d)
         {
             Node<T>* s = new Node<T>(d);
             s->next = head;
             head = s;
         }
         void pop()
         {
             if(head!= NULL)
             {
                  Node<T>* tmp = head;
                  head = head->next;
                  delete tmp;
             }
         }

         T top()
         {
             if(head!= NULL)
               return head->data;
               else
               return -1;
         }

         bool isempty()
         {
             return( head == NULL);
         }
};