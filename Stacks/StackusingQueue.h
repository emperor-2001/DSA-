
template<class T>
class Stack{

     queue<T>q1,q2;
     
   public:
        void transfer(queue<int>& q3,queue<int>& q4)
         {
             if(q4.empty())
               return;

              T element = q4.front();
              q4.pop();
              transfer(q3,q4);
              q3.push(element);
         }
    
       void push(T d)
       {
           q1.push(d);
       } 

       void pop()
       {
          if(q1.empty())
          {
              cout << "Sorry Queue is empty" << endl;
              return;
          } 
          transfer(q2,q1);
          q2.pop();
          transfer(q1,q2); 
       }
       T top()
       {
           return q1.back();
       } 
       bool isempty()
       {
           return q1.empty();
       }  
       



};