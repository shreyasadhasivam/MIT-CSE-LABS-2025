import java.util.Scanner;
class  arrayReadDemo
{
    public static void main(String[] args)
    {
        // int n,c;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array:");
        int n = sc.nextInt();
        // System.out.println("Enter the elements of the array:");
        int array[] = new int[n];

        System.out.println("Enter "+n+" integers:" );
        for(int i=0;i<n;i++)
            array[i]=sc.nextInt();

        System.out.println("The array elements are:");
        for(int i=0;i<n;i++)
            System.out.println(array[i]);


    }
}