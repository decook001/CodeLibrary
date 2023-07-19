
struct MergeSort
{
    vi sort__( vi a )
    {
        int n=a.size();
        merge_sort( a, 0, n-1 );
    }

    void merge_sort( vi& a, int low, int high)
    {
        if(low==high)return ;
        int mid= (low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        vector<int> tmp(high-low+1);
        for(int i=0,j=low,k=mid+1; i<tmp.size();)
        {
            if(j<=mid)
            {
                if(k<=high)
                {
                    if(a[j]<=a[k])tmp[i++]=a[j++];
                    else tmp[i++]=a[k++];
                }
                else tmp[i++]=a[j++];
            }
            else tmp[i++]=a[k++];
        }
        for(int i=0,j=low; j<=high; i++,j++)a[j]=tmp[i];
    }
};


