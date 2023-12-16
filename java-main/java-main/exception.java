import java.util.*;
class NonIntResultException extends Exception
{
    int n;
    int d;
    NonIntResultException(int num, int denom)
    {
        super("Result is not an integer");
        n = num;
        d = denom;
    }

    public String toString()
    {
        return "Result of "+ n +" / "+d+" is non-integer.";
    }
}

class CustomExcepDemo
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int[] num = new int[8];
        System.out.println("Enter the array for numerator:");
        for(int i=0;i<8;i++)
        {
            num[i] = sc.nextInt();
        }
        System.out.println("The numerator is: ");
        for(int i=0;i<8;i++)
        {
            System.out.print(num[i]+" ");
        }
        int[] denom = new int[6];
        System.out.println("\nEnter the array for denominator:");
        for(int i=0;i<6;i++)
        {
            denom[i] = sc.nextInt();
        }
        System.out.println("The denominator is: ");
        for(int i=0;i<8;i++)
        {
            System.out.print(num[i]+" ");
        }
        System.out.println();
        for(int i=0;i<num.length;i++)
        {
            try{
                if((num[i]%denom[i])!=0)
                {
                    throw new NonIntResultException(num[i], denom[i]);
                }
                System.out.println(num[i]+ " / "+denom[i]+" is "+num[i]/denom[i]);
            }
            catch(ArithmeticException exc)
            {
                System.out.println("Can't divide by zero");
            }
            catch(ArrayIndexOutOfBoundsException exc)
            {
                System.out.println("No matching element found.");

            }
            catch(NonIntResultException exc)
            {
                System.out.println(exc);
            }

        }
    }
}