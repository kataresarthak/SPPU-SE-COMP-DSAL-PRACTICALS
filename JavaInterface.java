import java.util.*;

interface base1
{
    void add();
    void sub();
}

interface base2
{
    void multi();
    void div();
}

class Base
{
    void disp()
    {
        System.out.println("This is Base Class");
    }
}

class Derive extends Base implements base1,base2
{
    int a,b;
    Scanner sc=new Scanner(System.in);

    void input()
    {
        System.out.print("Enter The Values Of A & B :");
        a=sc.nextInt();
        b=sc.nextInt();
    }
    public void add()
    {
        int c=a+b;
        System.out.println("Addition : "+c);
    }
    public void sub()
    {
        int c=a-b;
        System.out.println("Subtraction : "+c);
    }
    public void div()
    {
        int c=a/b;
        System.out.println("Division : "+c);
    
    }
    public void multi()
    {
        int c=a*b;
        System.out.println("Multiplication : "+c);
    }
}

public class JavaInterface
{
	public static void main(String[] args)
    {
	    Derive d=new Derive();
	    d.input();
	    d.add();
	    d.sub();
	    d.div();
	    d.multi();
	    d.disp();
	}
}
