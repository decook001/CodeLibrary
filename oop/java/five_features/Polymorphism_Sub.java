/*
encapsulation
abstraction
inheritence
polymorphism - override, overload
substitution

*/


public class four_features
{
    public static void main(String[] args) 
    {
        A a = new B(); // substitution , loose-coupling
        a.print();    
        // a.ride();   
    }
}


class A
{
    int x=10;
    void print()
    {
        System.out.println( x +" in A " );
    }
}


class B extends A
{
	int x=15;
    // override
    void print()
    {
        System.out.println( x +" in B " );
    }
    
    void ride()
    {
        System.out.println( " B can ride " );
    }

    // overload
    void ride( string s )
    {
    	System.out.println(s);
    }

}

