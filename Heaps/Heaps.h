
class Heap{

   vector<int>v;

   public:
       Heap(int default_size =10)
       {
           v.reserve(default_size);
           v.push_back(-1);
       }

       void push(int d)
       {
           v.push_back(d);
           int idx = v.size()-1;
           int parent = idx/2;

           while(idx>1 && v[idx] < v[parent])
           {
               swap(v[idx],v[parent]);
               idx = parent;
               parent = idx/2;
           }
       }

       void heapify(int i) // like restore down
       {
           int minidx = i;
           int left = 2*i;
           int right = 2*i + 1;

           if(left < v.size() && v[left] < v[minidx])
             minidx = left;

           if(right < v.size() && v[right] < v[minidx])
             minidx = right;

           if(minidx != i)
           {
               swap(v[i] , v[minidx]);
               heapify(minidx);
           }    

       }
       
       //same as restore up
       void MinHeap::decreaseKey(int i, int new_val) 
     {
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
    }   


       void pop()
       {
           swap(v[1],v[v.size()-1])
           v.pop_back();
           heapify(1);
       }
     


};