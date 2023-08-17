/*
    if no constructor declared default constructoris created
    if any constructor declared, only exists those constructors
    always declare a blank constructor for normal/abstract classes
    interfaces cannot have constructors
    all the methods are public in interfaces
*/

class HelloWorld 
{
    public static void main(String[] args) 
    {
        C c=new C();
    }
}

interface Price
{
    int getPrice();
}

interface Address
{
    void getAddress();
}

abstract class Abc
{
    String name;
    Abc()
    {
        
    }
    
    Abc( String name )
    {
        this.name=name;
    }
    
    void getName()
    {
        System.out.println( name );
    }

    abstract void placement( int x );
}

class C extends Abc implements Price, Address 
{
    
    public void placement(int x)
    {
        System.out.println( "placement "+x );
    }
    
    public int getPrice()
    {
        System.out.println( "price " );
        return 0;
    }
    
    public void getAddress()
    {
        System.out.println( "address " );
    }
}



