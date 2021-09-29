template< class X>

class Vector
{
   int cs;
   int ms;
   X *arr;

   public:
     Vector(int max_size=1)
       {
            cs=0;
            ms= max_size;
           arr = new X[ms];

         //cout << "kllljljlllllllll" << endl;
       }
      void push_back(const X x)
      {
           if(cs==ms)
            {
                X *oldarr = arr;
                ms*= 2;
                arr = new X[ms];
                for(int i=0;i<cs;i++)
                {
                    //cout << oldarr[i] << endl;
                   arr[i] = oldarr[i];

                }

            }
            //cout << cs << endl;
            arr[cs]=x;
            cs++;
      } ;

      void pop_back ()
      {
          if(cs>=0)
            cs--;
           
      };

      X operator[] (const X i) const
      {
          return arr[i];
      };

      bool isEmpty() const 
      {
            return(cs==0);
      };

      int size() const 
      {
          return cs;
      };

      X front() const
      {
          
          return arr[0];
      };

      X back() const 
      {
         
           return arr[cs-1];
      };

      int capacity() const 
      {
          return ms;
      };

     



};