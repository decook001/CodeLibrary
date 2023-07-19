

struct MaxHeap
{
    
    vector<int> car;
    int n=0;
    
    MaxHeap()
    {
        
    }

    void push_(int x)
    {
        car.push_back(x);
        for(int i = car.size()-1 ; i>0 ; i=par )
        {
            int par=(i-1)/2;
            if( car[par] > car[i] )
            {
                int tmp=car[par];
                car[par]=car[i];
                car[i]=tmp;
            }
            else break;
        }
    }

    int pop_()
    {
        int ret=0;
        if( car.size() ) ret=car[0];
        car[0]=car.back();
        car.push_back();
        for(int i=0,lc,rc,oc;i < car.size() /2;)
        {
            lc=i*2+1;
            rc=i*2+2;

            if(rc<n)
            {
                if( car[rc]>car[lc] )  oc=lc;
                else oc=rc;
            }
            else oc=lc;

            if( car[i] > car[oc] )
            {
                int aha=car[oc];
                car[oc]=car[i];
                car[i]=aha;
                i=oc;
            }
            else break;
        }
        return ret;
    }

    int top_()
    {
        if( car.size() ) return car[0];
        return 0;
    }

};



