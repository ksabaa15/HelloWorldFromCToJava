/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package helloworld;

/**
 *
 * @author karim
 */
public class HelloWorld {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        System.out.println("Hello World, from java before");
        helloWorld_c();
    }
    
    static{
        System.loadLibrary("HelloWorldNative");
    }
    
    private native static void helloWorld_c();
    
    public static void helloWorld(){
        System.out.println("Hello World, from java after");
    }
}