package AdapterPattern;

public class Main
{
    public static void main(String[] args) {
	// write your code here
        RoundHole hole = new RoundHole(10);
        RoundPeg roundPeg = new RoundPeg(8);
        SquarePeg squarePeg = new SquarePeg(6);
        SquarePegAdapter adapter  = new SquarePegAdapter(squarePeg);

        System.out.println(hole.fits(roundPeg));

        System.out.println(hole.fits(adapter));


    }
}

class RoundHole {

    private int Radius;

    RoundHole(int radius)
    {
        Radius=radius;
    }

    int getRadius()
    {
        return Radius;
    }

    Boolean fits(RoundPeg peg)
    {
        return Radius>=peg.getRadius();
    }

}

class RoundPeg {
    double Radius;

    RoundPeg(){}

    RoundPeg(double radius)
    {
        Radius=radius;
    }

    double getRadius()
    {
        return Radius;
    }

}

public class SquarePeg {

    double Width;

    SquarePeg(double width)
    {
        Width=width;
    }

    double getWidth()
    {
        return  Width;
    }


}

class SquarePegAdapter extends RoundPeg {

    private SquarePeg Peg;
    SquarePegAdapter(SquarePeg peg) {
        Peg=peg;
    }

    @Override
    double getRadius()
    {
        return Peg.getWidth()/ Math.sqrt(2);
    }
}


