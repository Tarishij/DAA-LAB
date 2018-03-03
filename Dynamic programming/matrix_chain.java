import java.util.*;
public class App{
    public static void main(String[] args){
        System.out.println("enter number of matrices");
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt()+1;
        int [] a=new int[t];
        System.out.println("give the order");
        for(int k=0;k<t;k++)
            a[k]=sc.nextInt();

        matrix_chain(a,t);
    }
    public static void matrix_chain(int[] a,int t){
        int n=t-1;
        int j,k,q;
        int[][] m=new int[n+1][n+1];
        int[][] s=new int [n+1][n+1];
        for(int i=1;i<=n;i++)
            m[i][i]=0;

        for(int l=2;l<=n;l++){
            for(int i=1;i<=n-l+1;i++){
                j=i+l-1;
                m[i][j]=100000;
                for(k=i;k<=j-1;k++){
                    q=m[i][k]+m[k+1][j]+a[i-1]*a[k]*a[j];

                    if(q<m[i][j]){
                        m[i][j]=q;
                        s[i][j]=k;
                    }
                }
            }
        }


        print(s,1,n);
    }
    public static void print(int[][] s,int i,int j){
        if(i==j)
            System.out.print(i);
        else{
            System.out.print("(");
            print(s,i,s[i][j]);
            print(s,s[i][j]+1,j);
            System.out.print(")");
        }

    }
}
