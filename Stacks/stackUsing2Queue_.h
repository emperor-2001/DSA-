
template<class T>
class Stack{

     queue<T>q1,q2;
     
   public:
        
       void push(T d)
       {
           if(!q1.empty())
              q1.push(d);

            else
               q2.push(d);

       } 

       int pop()
       {
          int temp;
     if(!q1.empty())
          {
              while(q1.size()!=1)
              {
                  q2.push(q1.front());
                  q1.pop();
              }
              temp = q1.front();
              q1.pop();
          }
      else if(!q2.empty())
          {
               while(q2.size()!=1)
              {
                  q1.push(q2.front());
                  q2.pop();
              }
               temp = q2.front();
              q2.pop();
          } 
    else
       temp = -1;
       
       
       return temp;
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