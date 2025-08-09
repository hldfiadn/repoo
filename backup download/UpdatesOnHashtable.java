// Java program to demonstrate
// updating Hashtable
 
import java.io.*;
import java.util.*;
class UpdatesOnHashtable {
    public static void main(String args[])
    {
 
        // Initialization of a Hashtable
        Hashtable<Integer, String> ht
            = new Hashtable<Integer, String>();
 
        // Inserting the Elements
          // using put method
        ht.put(1, "Geeks");
        ht.put(2, "Geeks");
        ht.put(3, "Geeks");
         
          // print initial map to the console
        System.out.println("Initial Map " + ht);
         
          // Update the value at key 2
        ht.put(2, "For");
         
          // print the updated map
        System.out.println("Updated Map " + ht);
    }
}