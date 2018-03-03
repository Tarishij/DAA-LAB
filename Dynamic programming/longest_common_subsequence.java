import java.util.*;
public class Lcs{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String x=sc.nextLine();
        String y=sc.nextLine();
        length(x,y);
        
        }
    public static void length(String x,String y){
        int m=x.length();
        int n=y.length();
        int i,j;
        int[][] b=new int[m+1][n+1];
        int[][] c=new int[m+1][n+1];
        for(i=0;i<=m;i++)
            c[i][0]=0;
        for( j=0;j<=n;j++)
            c[0][j]=0;
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                if(x.charAt(i-1)==y.charAt(j-1)){
                    c[i][j]=c[i-1][j-1]+1;
                    b[i][j]=1;                          //slant arrow=1
                 }
                 else if(c[i-1][j]>=c[i][j-1]){
                    c[i][j]=c[i-1][j];
                    b[i][j]=0;                            //upper arrow=0
                 }
                 else
                 {
                     c[i][j]=c[i][j-1];
                     b[i][j]=-1;                          //left arrow=-1
                  }
               }
            }    
        print(b,x,m,n);  
        }
      
    public static void print(int[][]b,String x,int i,int j){
        if (!(i==0||j==0)){
            
        if(b[i][j]==1){
            print(b,x,i-1,j-1);
            System.out.print(x.charAt(i-1));
            }
        else if(b[i][j]==0)
            print(b,x,i-1,j);
        else
            print(b,x,i,j-1);

    }
   }
}
         
