class Rethrow
{
    public static void genException()
    {
        int[] num = {4,8,16,32,64,128,256,512};
        int[] denom ={2,0,4,4,0,8};

        for(int i=0;i <num.length;i++)
        {
            try{
                System.out.println(num[i]+" / "+denom[i]+ " is " +num[i]/denom[i]);

            }
            catch(ArrayIndexOutOfBoundsException exc)
            {
                System.out.println(exc);
            }
            catch(ArithmeticException exc)
            {
                System.out.println(exc);
                throw exc;
            }
        }
    }
}

class RethrowDemo
{
    public static void main(String[] args)
    {
        try{
            Rethrow.genException();
        }
        catch(ArithmeticException exc)
        {
            System.out.println("Error")
        }
    }
}