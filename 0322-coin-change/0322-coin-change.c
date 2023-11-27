int min(int a,int b)
{
    return a<b?a:b;
}

int coinChange(int* coins,int coinSize,int amount)
{
    int* a=(int*)malloc((amount+1)*sizeof(int));
    for(int i=0;i<=amount;i++) a[i]=INT16_MAX;
    a[0]=0;
    for(int i=1;i<=amount;i++)
    {
        for(int j=0;j<coinSize;j++)
        {
            if(coins[j]<=i&&a[i-coins[j]]!=INT16_MAX) a[i]=min(a[i],a[i-coins[j]]+1);
        }
    }
    int res=a[amount]==INT16_MAX?-1:a[amount];
    free(a);
    return res;
}