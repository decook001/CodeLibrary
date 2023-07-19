/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package MultiThreading;

/**
 *
 * @author shoai
 */
public class TestJava {

    public static void main(String[] args) throws InterruptedException {
        ThreadRed t1=new ThreadRed(1);
        ThreadRed t2=new ThreadRed(2);
        Thread t3=new Thread( new ThreadBlue(3) );
        
        t3.start();
        t1.start();
        t1.join();
        t2.start();

    }
}
