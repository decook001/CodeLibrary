package CompositePattern;

public class Main
{
    public static void main(String[] args) {
	// write your code here
        Directory book = new Directory("Book");

        Directory scifi = new Directory("SciFi");
        scifi.add(new File("Inception"));
        scifi.add(new File("Interesteller"));

        Directory thriller = new Directory("Thriller");
        thriller.add(new File("The Dark Knight"));
        thriller.add(new File("Shwashank Redemption"));

        book.add(scifi);
        book.add(thriller);

        book.ls();

    }
}

interface AbstractFile {
    void ls();
}

class Directory implements AbstractFile {

    String Name;
    int ind;
    AbstractFile [] Files = new AbstractFile[100];

    Directory(String name)
    {
        Name=name;
        ind=0;
    }

    void add(AbstractFile file)
    {
        if(ind<100)
            Files[ind++]=file;
    }

    void delete()
    {
        if(ind>0) ind--;
    }

    @Override
    public void ls()
    {
        System.out.println(Name);
        for(int i=0;i<ind;i++)
        {
            Files[i].ls();
        }
    }
}

class File implements AbstractFile {
    String Name;
    File(String name)
    {
        Name=name;
    }

    @Override
    public void ls() {
        System.out.println(Name);
    }
}

