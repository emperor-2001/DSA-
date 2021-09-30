
template<class T>
class Queue
{
    T* arr;
    int front;
    int rear;
    int  cs;
    int ms;

    public:
        Queue(int default_size = 5)
        {
            ms = default_size;
            front = -1;
            cs = 0;
            rear = -1;
            arr = new T[ms];
            
        }
        void push(T d)
        {
            if(isfull() )
            cout << "Sorry Queue is full" << "\n";
            else
            {
                rear = (rear+1)%ms;
                arr[rear] = d;
                if(cs == 0)
                  front =0;
                cs++;

            }
        }
        void pop()
        {
            if(isempty())
            {
             cout << "Sorry Queue is empty" << "\n";
             return; 
            }
             front = (front + 1)%ms;
             cs--;
             if(cs == 0)
             {
                 rear = -1;
                 front = -1;
             }
             return;
             
        }
        T Fronte()
        {
            return arr[front];
        }
        bool isempty()
        {
            return cs == 0; 
        }
        bool isfull()

        {
            return cs==ms;
        }
        bool back()
        {
            return arr[rear];
        }

};
