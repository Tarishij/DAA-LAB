import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String t=sc.nextLine();
        String p=sc.nextLine();
        int flag=0;
        int j,i;
        for(i=0;i<=t.length()-p.length();i++){
            for(j=0;j<p.length();j++){
                if(t.charAt(i+j)!=p.charAt(j)){
                    break;
                }
            }
            if(j==p.length()){
                flag=1;
                System.out.println(i);
            }
        }
        if(flag==0)
            System.out.println("pattern not found");
    }
}
