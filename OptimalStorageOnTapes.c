#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int prog_no;
    int prg_length;
}node;

void heapify(node arr[] , int n , int p) /// MAX-HEAPIFY FUNTION
{
    int gt=p;
    int lc = 2*p+1;
    int rc = 2*p+2;
    if(lc<n && arr[lc].prg_length>arr[gt].prg_length)
        gt=lc;
    if(rc<n && arr[rc].prg_length>arr[gt].prg_length)
        gt=rc;
    if(gt!=p)
    {
        node temp = arr[p];
        arr[p] = arr[gt];
        arr[gt]=temp;
        heapify(arr,n,gt);
    }
}
void heap_sort(node arr[] , int n) /// HEAP SORT
{
    int i;
    for(i=(n+1)/2;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    int cs=n;
    while(cs>1)
    {
        node temp = arr[0];
        arr[0] = arr[cs-1];
        arr[cs-1]=temp;
        cs--;
        heapify(arr,cs,0);
    }
}

int main()
{
    int n,i,j;
    printf("--------------------------ENTER THE NUMBER OF PROGRAMS TO BE STORED--------------------------\n");
    scanf("%d",&n);
    node* arr = (node*)malloc(n*sizeof(node)); /// ALLOCATING MEMORY TO ARRAY OF STRUCTURE NODE
    printf("----------------------------------ENTER PROGRAM LENGTHS---------------------------------------\n");
    for(i=0;i<n;i++) /// INPUT OF LENGTH FOR EACH PROFRAM
    {
        printf("--PROGRAM : %d",i+1);
        printf("\n--LENGTH : ");
        scanf("%d",&arr[i].prg_length);
        arr[i].prog_no=i+1;
    }
    heap_sort(arr,n);  /// HEAP SORT FOR PLACING THE PROGRAM WIHT MINIMUM PROGRAM LENGTH
    float sum=0;
    float MRT=0; /// MEAN RETRIEVAL TIME
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            sum+=arr[j].prg_length;
        }
    }
    MRT=sum/n;
    printf("-----MEAN RETRIEVAL TIME : %f\n",MRT);
    printf("-----ORDER IN WHICH PROGRAM CAN BE ARRANGED ON TAPE TO GET THE ABOVE MRT:\n");
    for(i=0;i<n;i++)
    {
        printf("%d || ",arr[i].prog_no);
    }
    printf("\nTHANKS");
    return 0;
}
