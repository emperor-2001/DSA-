
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
              while(!q1.empty())
              {
                  temp = q1.front();
                  q1.pop();

                  if(q1.empty())
                     break;
 
                  q2.push(temp);    
              } 
          }
      else if(!q2.empty())
          {
               while(!q2.empty())
              {
                  temp = q2.front();
                  q2.pop();

                  if(q2.empty())
                     break;
 
                  q1.push(temp);    
              } 
          } 
    else
       temp = -1;
       
       
       return temp;
       }
       T top()
       {
          if(!q1.empty())
          {
              while(!q1.empty())
              {
                  temp = q1.front();
                  q1.pop();
                  q2.push(temp);   


                  if(q1.empty())
                    return temp;
                     
 
                  
              } 
          }
      else if(!q2.empty())
          {
               while(!q2.empty())
              {
                  temp = q2.front();
                  q2.pop();
                   q1.push(temp); 

                  if(q2.empty())
                     return temp;
 
                    
              } 
          } 
       } 
       bool isempty()
       {
           return q1.empty();
       }  
       



};