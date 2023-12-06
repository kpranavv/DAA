#include<stdio.h>
int selection(int size,int arr[size]){
    for(int i=0;i<size-1;i++){
        int min_index=i;
        for(int j=i+1;j<size;j++){
            if(arr[min_index]>arr[j]){
                min_index=j;
            }
            
        }
        // swap condition should be outside the 2nd for loop
        if(min_index!=i){
                int temp=arr[min_index];
                arr[min_index]=arr[i];
                arr[i]=temp;
            }

    }
}

int main(){
int size;
printf("Enter the size:\n");
scanf("%d\n",&size);
int arr[size];
printf("Enter the arry elements:\n");
for(int i=0;i<size;i++){
    scanf("%d",&arr[i]);
}

selection(size,arr);
printf("Sorted elements through selection sort method are:\n");
for(int i=0;i<size;i++)
{
    printf("%d ",arr[i]);
}
}