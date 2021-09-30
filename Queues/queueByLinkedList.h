template<class T>
class Queue;

template<class T>
class Node{
    T data;
    Node<T>* next;
    public:
     Node(T d):data(d), next(NULL){};
     friend class Queue<T>;

};

template<class T>
class Queue{

    Node<T>* head;
    Node<T>* tail;

   public:
       Queue()
       {
           head = tail = NULL;
       }
       void push(T d)
       {
           Node<T>* s = new Node<T>(d);

           if(head == NULL) 
           {
               
             head = tail = s; 
           } 
           else
           {
           tail ->next = s;
           tail = s;
           }
          
       }
       void pop()
       {
           if(head == NULL) 
           {
               cout << "Sorry Queue is empty" << "\n";
               return;
           }
           Node<T>* tmp = head;
           head = head ->next;
           delete tmp;
       }

       T front()
       {
           return head->data;
       }
       bool isempty()
       {
           return (head == NULL);
       }
       T back()
       {
           return tail->data;
       }





};