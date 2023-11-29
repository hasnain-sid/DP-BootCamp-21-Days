class Solution
{
   

    public int solve(int i,Job arr[],int maxdead){

        if (i >= arr.length ){
            return 0;
        }

        int take = Integer.MIN_VALUE;
        int nottake = Integer.MIN_VALUE;

        if (maxdead > 0){
            take = arr[i].profit + solve(i+1,arr,maxdead-1);
        }
        nottake = 0+ solve(i+1,arr,maxdead);

        return Math.max(take,nottake);
    }
    int[] JobScheduling(Job arr[], int n)
    {
        int maxdead = 0;
        

        for (int i=0;i<arr.length;i++){
            if (arr[i].deadline > maxdead){
                maxdead=arr[i].deadline;
            }
        }
        int ans = solve(0,arr,maxdead);
        int a[]= new int[2];
        a[0]= ans;
        a[1]=0;
        return a;
    }
}