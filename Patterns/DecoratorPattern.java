package DecoratorPattern;

public class Main
{
    public static void main(String[] args) {
	// write your code here
        Decorator burger = new Meonese(new Sauce(new Burger()));

        burger.write();

    }
}

class Burger implements Decorator {
    @Override
    public void write()
    {
        System.out.print("Burger with ");
    }
}

interface Decorator {
    void write();
}

class Meonese implements Decorator {
    private Decorator Source;

    public Meonese(Decorator source)
    {
        Source=source;
    }

    @Override
    public void write() {
        Source.write();
        System.out.println("meonese");
    }
}

class Sauce implements Decorator {
    private Decorator Source;

    public Sauce(Decorator source)
    {
        Source=source;
    }

    @Override
    public void write() {
        Source.write();
        System.out.printf("sauce ");
    }
}


