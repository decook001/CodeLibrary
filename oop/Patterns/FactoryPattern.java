package FactoryPattern;


import java.util.Date;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        ImageReader ir=null;
        int tok=0;

        if(tok==1)
        {
            ir=new GifReader("gif");
        }
        else
        {
            ir=new JpegReader("jpeg");
        }

        DecodedImage dc=ir.getDecodedImage();
        dc.getName();
    }
}


class DecodedImage {
    String name;
    public DecodedImage(String aka)
    {
        name=aka;
    }

    public String getName()
    {
        System.out.println(name + "is decoded");
        return name;
    }
}


class GifReader implements ImageReader {

    DecodedImage image;
    GifReader(String name)
    {
        image=new DecodedImage(name);

    }

    @Override
    public DecodedImage getDecodedImage() {
        return image;
    }
}

interface ImageReader {
    DecodedImage getDecodedImage();

}

class JpegReader implements ImageReader {
    DecodedImage name;

    JpegReader(String image)
    {
        name=new DecodedImage(image);
    }

    @Override
    public DecodedImage getDecodedImage() {
        return name;
    }
}









