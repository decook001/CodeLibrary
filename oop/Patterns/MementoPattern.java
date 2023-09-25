// Capture and restore an object's internal state
// tutorials point

import java.util.*;

class Memento {
    private String state;

    public Memento(String state) {
        this.state = state;
    }

    public String getState() {
        return state;
    }
}

class Originator 
{
    private String state;
   

    public void setState(String state) 
    {
        System.out.println("Originator: Setting state to " + state);
        this.state = state;
    }

    public Memento save() 
    {
        System.out.println("Originator: Saving to Memento.");
        return new Memento(state);
    }
    public void restore(Memento m) 
    {
        state = m.getState();
        System.out.println("Originator: State after restoring from Memento: " + state);
    }
}

class Caretaker 
{
    private ArrayList<Memento> mementos = new ArrayList<>();
    public void addMemento(Memento m) 
    {
        mementos.add(m);
    }

    public Memento getMemento() 
    {
        Memento ret=null;
        if( mementos.size()>0 ) ret=mementos.get( mementos.size()-1  );
        mementos.remove( mementos.size()-1  );
        return ret;
    }
}

public class MementoPattern 
{
    public static void main(String[] args) 
    {
        Caretaker caretaker = new Caretaker();
        Originator originator = new Originator();
        originator.setState("State1");
        originator.setState("State2");
        caretaker.addMemento( originator.save() );
        originator.setState("State3");
        caretaker.addMemento( originator.save() );
        originator.setState("State4");
        originator.restore( caretaker.getMemento() );
    }
}

