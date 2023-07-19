
//average nlog2(n)
// worst n^2

void quicksort(vector<int>& a, int low, int high)
{
    if(low>=high)return;
    int pivot=low;
    int lm=low+1, rm=high;
    for(;lm<rm;)
    {
        while(lm<=high &&  a[lm] <= a[pivot] )lm++;
        while(rm>pivot && a[pivot] < a[rm] )rm--;
        if(lm<rm)
        {
            int tmp=a[lm];
            a[lm]=a[rm];
            a[rm]=tmp;
        }
    }
    int tmp=a[rm];
    a[rm]=a[pivot];
    a[pivot]=tmp;
    quicksort(a,low,rm-1);
    quicksort(a,rm+1,high);
}




