template< class T>
class Stack{

    Vector<T> stack;
    public:
      void push(T d)
      {
          stack.push_back(d);
      };
      void pop()
      {
          if(stack.size() >= 1)
            stack.pop_back();
           
      };
      T top()
      {
          return stack[stack.size()-1];
      };
      bool isempty()
      {
          return ( stack.size() == 0);
      }



};
