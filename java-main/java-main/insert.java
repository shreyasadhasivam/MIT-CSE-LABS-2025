import java.util.Scanner;

class insert
{
  public static void main(String[] args)
  {
    int n,i,ele,inpos;
    int delpos;
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the size of the array:");
    n = sc.nextInt();
    int arr[] = new int[n];
    System.out.println("Enter the elements:");
    for(i=0;i<arr.length;i++)
        arr[i] = sc.nextInt();

    System.out.println("Enter the element and position you want to insert");
    ele = sc.nextInt();
    inpos = sc.nextInt();

    for(i=n;i>inpos-1;i--)
    {
        arr[i] = arr[i-1];

    }
    arr[inpos-1] = ele;
    n= n+1;
    System.out.println("After inserting, printing array");
    for(i=0;i<arr.length;i++)
    {
        System.out.print(arr[i] + " ");

    }
    System.out.println();
  }
}

//     System.out.println("Enter the position you want to delete the element from:");
//     for(i=delpos-1;i<n-1;i++)
//     {
//         arr[i] = arr[i+1];
//     }
//     n=n-1;
//     System.out.println("After deleting, the array is");
//     for(i=0;i<n;i++)
//     {
//         System.out.print(arr[i]+" ");

//     }
//     System.out.println();
//   }
// }