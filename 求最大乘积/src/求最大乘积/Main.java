package 求最大乘积;

import java.util.Arrays;
import java.util.Scanner;
 
public class Main{  
    public static void main(String[] args){  
        @SuppressWarnings("resource")
		Scanner in = new Scanner(System.in);  
        int u=in.nextInt();
        int sum=1;
        while(u!=0){
            int n=in.nextInt();
            int m=in.nextInt();
            int[] a=new int[n];
            for(int i=0;i<n;i++){
                a[i]=in.nextInt();
            }
            Arrays.sort(a);
            sum=1;
            int num1;
            int num2;
            for(int i=n-1,j=0;i>=j&&m!=0;){
                num1=a[i]*a[i-1];
                num2=a[j]*a[j+1];
                if(num1<=num2&&m>=2){
                    sum*=num2;
                    j+=2;
                    m-=2;
                }
                else{
                    sum*=a[i--];
                    m--;
                }
                System.out.print(sum+" ");
            }
            u--;
            System.out.println("\n"+sum);
        }
    }  
}  