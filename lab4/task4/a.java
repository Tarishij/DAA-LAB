import java.util.*;
public class Main{
    public static void main(String[] args){
        int n;
        Scanner s=new Scanner(System.in);
        n=s.nextInt();
        int[] a=new int[n];
        for(int i=0;i<n;i++)
            a[i]=s.nextInt();
        int max=0,sum=0;
        for(int i:a){
            sum+=i;
            if(sum<0){
                sum=0;
            }
            else if(sum>max)
                max=sum;
        }
        System.out.println(max);
    }
}
