#include<bits/stdc++.h>
#include <chrono>
#include <thread>
using namespace std;

void welcome()
{
    system("clear");//clearing the screen
    for(int i=0;i<40;i++)
         cout<<" ";
    cout<<"Sorting algorithms visiualisation"<<endl;//Heading
    cout<<endl;
    for(int i=0;i<144;i++)//underline
        cout<<"-";
    cout<<endl;
    cout<<endl;
}

bool issorted(int a[],int n)//checking whether sorted or not
{
    for(int i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
            return false;
    }
    return true;
}

void reset(int a[],int b[],int n)//restoring the original order
{
    int i;
    for(i=0;i<n;i++)
        b[i]=a[i];
    return ;    
}

int menu()//displaying the menu
{
    int n;
    cout<<"Menu:"<<endl;
    cout<<endl;
    cout<<1<<"."<<"Bubblesort"<<endl;
    cout<<"2.Insertionsort"<<endl;
    cout<<"3.Selectionsort"<<endl;
    cout<<"4.Mergesort"<<endl;
    cout<<"5.Quicksort"<<endl;
    cout<<"6.Heapsort"<<endl;
    cout<<"7.Exit"<<endl;
    cout<<'\n'<<"Enter your choice"<<endl;
    cin>>n;
    while(n<1 || n>7)//invalid input check
    {
        welcome();
        cout<<"Enter a valid choice"<<endl;
        cout<<'\n';
        cout<<"Menu:"<<endl;
        cout<<endl;
        cout<<1<<"."<<"Bubblesort"<<endl;
        cout<<"2.Insertionsort"<<endl;
        cout<<"3.Selectionsort"<<endl;
        cout<<"4.Mergesort"<<endl;
        cout<<"5.Quicksort"<<endl;
        cout<<"6.Heapsort"<<endl;
        cout<<"7.Exit"<<endl;
        cout<<'\n'<<"Enter your choice"<<endl;
        cin>>n;   
    }
    return n;
}

 void printing(int a[],int n)
 {
    using namespace std::this_thread;     // sleep_for, sleep_until
    using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
    using std::chrono::system_clock;
    sleep_until(system_clock::now() + 500ms);
    welcome();
     for(int i=0;i<n;i++)//printing
     {
        for(int j=0;j<a[i];j++)
            cout<<"-";
        cout<<"   "<<a[i]<<endl;    
     }
 }

 void selectionsort(int a[],int n)
 { 
    int i,j,min,temp;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])//finding minimum
                min=j;
        }
        if(min!=i)
        {
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;//swap
            printing(a,n);
        }
    }
 }

 void bubblesort(int a[],int n)
 {
     int i,j,temp;
     for(i=n-1;i>=0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]>a[j+1])//jth element is greater than (j+1)th
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;//swap
                printing(a,n);
            }
        }
    }
 }

 void insertionsort(int a[],int n)
 {
     int i,j,x;
     for(i=0;i<n;i++)
     {
        j=i-1;
        x=a[i];
        while(j>-1 && a[j]>x)//finding the right position for the element
        {
            a[j+1]=a[j];
            printing(a,n);
            j--;
        }
        a[j+1]=x;
        printing(a,n);
     }
 }

 void merge(int a[],int l,int m,int h)
 {
    int i,j,k;
    i=l;
    j=m+1;
    k=0;
    int b[h-l+1];//auxillary array
    while(i<=m && j<=h)
    {
        if(a[i]<a[j])
           b[k++]=a[i++];
        else 
           b[k++]=a[j++];   
    }
    for(;i<=m;i++)
        b[k++]=a[i];
    for(;j<=h;j++)
        b[k++]=a[j];
    for(i=l;i<=h;i++)
        a[i]=b[i-l];      
 }

 void mergesort(int a[],int l,int h,int n)
 {
    if(l<h)
    {
        int mid=l+(h-l)/2;
        mergesort(a,l,mid,n);//recursive
        mergesort(a,mid+1,h,n);
        merge(a,l,mid,h);//sorting
        printing(a,n);
    }
    return ;
 }

 int partition(int a[],int l,int h,int n)
 {
    int pivot=a[l];//pivot
    int i=l,j=h,temp;
    do
    {
        do 
        {
            i++;
        }while(a[i]<=pivot);
        while(a[j]>pivot)
            j--;
        if(i<j)//swapping greater and smaller elements
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            printing(a,n);
        }
    }while(i<j);//finding the correct position for the pivot
    if(j!=l)
    {
        a[l]=a[j];
        a[j]=pivot;
        printing(a,n);
    }
    return j;
 }

 void quicksort(int a[],int l,int h,int n)
 {
    if(l<h)
    {
        int j=partition(a,l,h,n);//pivot position
        quicksort(a,l,j-1,n);//recursive sorting
        quicksort(a,j+1,h,n);
    }
    return ;
 }

 void heapsort(int a[],int n)
 {
    int i,temp,j,x,k;
    for(i=0;i<n;i++)//heapify
    {
        temp=a[i];
        j=i;
        while(j>0 && temp>a[(j-1)/2])//if child is greater than parent
        {
            a[j]=a[(j-1)/2];
            j=(j-1)/2;
        }
        a[j]=temp;
        printing(a,i);
    }
    for(i=0;i<n;i++)
    {
        temp=a[0];
        a[0]=a[n-i-1];
        k=0;
        j=2*k+1;
        while(j<n-i-1)//rearranging
        {
            if(j!=n-i-2 && a[j+1]>a[j])
                j++;
            if(a[k]<a[j])
            {
                x=a[k];
                a[k]=a[j];
                a[j]=x;
                k=j;
                j=2*j+1;
            }   
            else
                break;             
        }
        a[n-i-1]=temp;
        printing(a,n);
    } 
 }


int main() {
    using namespace std::this_thread;     // sleep_for, sleep_until
    using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
    using std::chrono::system_clock;
    welcome();
    int n,i,j,x;
    cout<<"Enter total number of elements"<<endl;
    cin>>n;
    int a[n],b[n];
    cout<<"Enter the elements one by one"<<endl;
    for(i=0;i<n;i++)
        cin>>a[i];  
    x=0;
    while(true)//till the user wanted to continue
    {
        welcome();
        reset(a,b,n);
        x=menu();
        if(x==7)
            break;
        if(x==1)
            bubblesort(b,n);
        else if(x==2)     
            insertionsort(b,n);
        else if(x==3)
            selectionsort(b,n);
        else if(x==4)
            mergesort(b,0,n-1,n);
        else if(x==5)
            quicksort(b,0,n-1,n);
        else
            heapsort(b,n);    
        cout<<'\n'<<"Press"<<endl;
        cout<<"1.Continue"<<endl;
        cout<<"2.Exit"<<endl;    
        cin>>x;
        if(x==2)
            break;               
    } 
}